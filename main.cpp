#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Food {
public:
    int id;
    string name;
    double price;

    Food(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
    }
};

class CartItem {
public:
    Food food;
    int quantity;

    CartItem(Food f, int q) : food(f), quantity(q) {}
};

class FoodOrderingSystem {
private:
    vector<Food> menu;
    vector<CartItem> cart;

public:
    FoodOrderingSystem() {
        menu.push_back(Food(1, "Burger", 99));
        menu.push_back(Food(2, "Pizza", 199));
        menu.push_back(Food(3, "Pasta", 149));
        menu.push_back(Food(4, "Sandwich", 79));
        menu.push_back(Food(5, "Cold Drink", 49));
    }

    void displayMenu() {
        cout << "\n========== FOOD MENU ==========\n";
        cout << left << setw(10) << "ID"
             << setw(20) << "Item"
             << setw(10) << "Price" << endl;

        for (auto food : menu) {
            cout << setw(10) << food.id
                 << setw(20) << food.name
                 << "Rs." << food.price << endl;
        }
    }

    void addToCart() {
        int id, qty;
        cout << "\nEnter Food ID: ";
        cin >> id;

        bool found = false;

        for (auto food : menu) {
            if (food.id == id) {
                cout << "Enter Quantity: ";
                cin >> qty;

                cart.push_back(CartItem(food, qty));

                cout << food.name << " added to cart!\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Invalid Food ID!\n";
        }
    }

    void viewCart() {
        if (cart.empty()) {
            cout << "\nCart is Empty!\n";
            return;
        }

        double total = 0;

        cout << "\n========== YOUR CART ==========\n";

        for (auto item : cart) {
            double amount = item.food.price * item.quantity;

            cout << item.food.name
                 << " x " << item.quantity
                 << " = Rs." << amount << endl;

            total += amount;
        }

        cout << "---------------------------\n";
        cout << "Total = Rs." << total << endl;
    }

    void placeOrder() {
        if (cart.empty()) {
            cout << "\nCart is Empty!\n";
            return;
        }

        double total = 0;

        ofstream file("orders.txt", ios::app);

        file << "\n===== NEW ORDER =====\n";

        cout << "\n========== BILL ==========\n";

        for (auto item : cart) {
            double amount = item.food.price * item.quantity;

            cout << item.food.name
                 << " x " << item.quantity
                 << " = Rs." << amount << endl;

            file << item.food.name
                 << " x " << item.quantity
                 << " = Rs." << amount << endl;

            total += amount;
        }

        cout << "------------------------\n";
        cout << "Grand Total: Rs." << total << endl;

        file << "Grand Total: Rs." << total << endl;
        file.close();

        cart.clear();

        cout << "\nOrder Placed Successfully!\n";
        cout << "Order saved in orders.txt\n";
    }
};

int main() {
    FoodOrderingSystem system;

    int choice;

    do {
        cout << "\n\n===== FOOD ORDERING SYSTEM =====\n";
        cout << "1. View Menu\n";
        cout << "2. Add To Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Place Order\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.displayMenu();
            break;

        case 2:
            system.addToCart();
            break;

        case 3:
            system.viewCart();
            break;

        case 4:
            system.placeOrder();
            break;

        case 5:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}