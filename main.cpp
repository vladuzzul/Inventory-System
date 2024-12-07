#include <iostream>
#include "inventory_system.h"
using namespace std;

int main() {


    vector<Item> items;
    initialize(items);

    int option = 0;

    while (option != 6){
        cout << "\n\n=== " << store_name << " Inventory System ===\n\n";
        cout << "1. See store inventory\n2. Add item\n3. Get item info\n4. Supply stock\n5. Register sold item\n6. Save and leave\n\nOption: ";
        cin >> option;
        cout << "\n";
        switch (option){
            case 1:{
                see_inv(items);
                break;
            }
            case 2:{
                add_item(items);
                break;
            }
            case 3:{
                string name;
                cout << "Enter the name of the item: "; cin >> name;
                get_item(items, name);
                break;
            }
            case 4:{
                int quantity;
                string name;
                cout << "Enter the name of the supplied item: "; cin >> name;
                cout << "Enter the bought quantity: "; cin >> quantity;
                supply_item(items, name, quantity);
                break;
            }
            case 5:{
                int quantity;
                string name;
                cout << "Enter the name of the sold item: "; cin >> name;
                cout << "Enter the sold quantity: "; cin >> quantity;
                sold_item(items, name, quantity);
                break;
            }
            case 6:{
                cout << "Have a nice day!\n";
                fout.close();
                break;
            }
            default: cout << "Option not available, please try again!\n";
        }
    }
}
