#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

int itemIds[MAX_ITEMS];
string itemNames[MAX_ITEMS];
int itemQuantities[MAX_ITEMS];
double itemPrices[MAX_ITEMS];
int itemCount = 0;

void displayAdminMenu();
void displayUserMenu();

// Admin Functions
void displayAllDetails();
void insertItem();
void editItem();
void deleteItem();
void deleteAllItems();

// User Functions
void displayItemsMenu();
void selectItems();
void displayBill();
void lastRecord();
void helpCenter();
void ratings();

// Global variables for User Bill
int userCartIds[MAX_ITEMS];
string userCartNames[MAX_ITEMS];
int userCartQuantities[MAX_ITEMS];
double userCartPrices[MAX_ITEMS];
int userCartCount = 0;

double totalBill = 0;

int main() {
    int choice;
    
    while (true) {
        cout << "\n--- Honda Bike Workshop and Inventory System ---\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAdminMenu();
                break;
            case 2:
                displayUserMenu();
                break;
            case 3:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void displayAdminMenu() {
    int choice;

    while (true) {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Display All Details\n";
        cout << "2. Insert Item\n";
        cout << "3. Edit Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Delete All Items\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllDetails();
                break;
            case 2:
                insertItem();
                break;
            case 3:
                editItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                deleteAllItems();
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void displayUserMenu() {
    int choice;

    while (true) {
        cout << "\n--- User Menu ---\n";
        cout << "1. Items Menu\n";
        cout << "2. Select Items\n";
        cout << "3. My Bill\n";
        cout << "4. Last Record\n";
        cout << "5. Help Center\n";
        cout << "6. Ratings\n";
        cout << "7. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayItemsMenu();
                break;
            case 2:
                selectItems();
                break;
            case 3:
                displayBill();
                break;
            case 4:
                lastRecord();
                break;
            case 5:
                helpCenter();
                break;
            case 6:
                ratings();
                break;
            case 7:
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

void displayAllDetails() {
    if (itemCount == 0) {
        cout << "No items in the inventory.\n";
        return;
    }
    
    cout << "\n--- Inventory Details ---\n";
    for (int i = 0; i < itemCount; i++) {
        cout << "ID: " << itemIds[i]
             << ", Name: " << itemNames[i]
             << ", Quantity: " << itemQuantities[i]
             << ", Price: " << itemPrices[i] << "\n";
    }
}

void insertItem() {
    if (itemCount >= MAX_ITEMS) {
        cout << "Inventory is full!\n";
        return;
    }

    cout << "Enter Item ID: ";
    cin >> itemIds[itemCount];
    cout << "Enter Item Name: ";
    cin >> itemNames[itemCount];
    cout << "Enter Item Quantity: ";
    cin >> itemQuantities[itemCount];
    cout << "Enter Item Price: ";
    cin >> itemPrices[itemCount];

    itemCount++;
    cout << "Item inserted successfully!\n";
}

void editItem() {
    int id;
    cout << "Enter the ID of the item to edit: ";
    cin >> id;

    for (int i = 0; i < itemCount; i++) {
        if (itemIds[i] == id) {
            cout << "Enter new name: ";
            cin >> itemNames[i];
            cout << "Enter new quantity: ";
            cin >> itemQuantities[i];
            cout << "Enter new price: ";
            cin >> itemPrices[i];
            cout << "Item updated successfully!\n";
            return;
        }
    }
    cout << "Item not found!\n";
}

void deleteItem() {
    int id;
    cout << "Enter the ID of the item to delete: ";
    cin >> id;

    for (int i = 0; i < itemCount; i++) {
        if (itemIds[i] == id) {
            for (int j = i; j < itemCount - 1; j++) {
                itemIds[j] = itemIds[j + 1];
                itemNames[j] = itemNames[j + 1];
                itemQuantities[j] = itemQuantities[j + 1];
                itemPrices[j] = itemPrices[j + 1];
            }
            itemCount--;
            cout << "Item deleted successfully!\n";
            return;
        }
    }
    cout << "Item not found!\n";
}

void deleteAllItems() {
    itemCount = 0;
    cout << "All items deleted successfully!\n";
}

void displayItemsMenu() {
    displayAllDetails();
}

void selectItems() {
    int id, quantity;
    cout << "Enter the ID of the item to select: ";
    cin >> id;

    for (int i = 0; i < itemCount; i++) {
        if (itemIds[i] == id) {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity <= itemQuantities[i]) {
                itemQuantities[i] -= quantity;
                userCartIds[userCartCount] = id;
                userCartNames[userCartCount] = itemNames[i];
                userCartQuantities[userCartCount] = quantity;
                userCartPrices[userCartCount] = itemPrices[i] * quantity;
                userCartCount++;
                totalBill += itemPrices[i] * quantity;
                cout << "Item added to cart!\n";
            } else {
                cout << "Not enough stock available!\n";
            }
            return;
        }
    }
    cout << "Item not found!\n";
}

void displayBill() {
    if (userCartCount == 0) {
        cout << "Your cart is empty.\n";
        return;
    }

    cout << "\n--- Your Bill ---\n";
    for (int i = 0; i < userCartCount; i++) {
        cout << "ID: " << userCartIds[i]
             << ", Name: " << userCartNames[i]
             << ", Quantity: " << userCartQuantities[i]
             << ", Total Price: " << userCartPrices[i] << "\n";
    }
    cout << "Total Amount: " << totalBill << "\n";
}

void lastRecord() {
    if (userCartCount == 0) {
        cout << "No last record available.\n";
        return;
    }

    cout << "\n--- Last Record ---\n";
    cout << "ID: " << userCartIds[userCartCount - 1]
         << ", Name: " << userCartNames[userCartCount - 1]
         << ", Quantity: " << userCartQuantities[userCartCount - 1]
         << ", Total Price: " << userCartPrices[userCartCount - 1] << "\n";
}

void helpCenter() {
    cout << "\n--- Help Center ---\n";
    cout << "For assistance, contact us at: help@hondaworkshop.com\n";
}

void ratings() {
    int rating;
    cout << "\nRate our system (1-5): ";
    cin >> rating;
    if (rating >= 1 && rating <= 5) {
        cout << "Thank you for your feedback!\n";
    } else {
        cout << "Invalid rating!\n";
    }
}

