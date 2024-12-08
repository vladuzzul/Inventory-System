#include <iostream>
#include "inventory_system.h"
using namespace std;

int main() {


    vector<Item> items;
    initialize(items);

    int option = 0;

    while (option != 7){
        cout << "\n\n=== " << store_name << " Inventory System ===\n\n";
        cout << "1. See store inventory\n2. Add item\n3. Delete item\n4. Get item info\n5. Supply stock\n6. Register sold item\n7. Save and leave\n\nOption: ";
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
                delete_item(items, name);
                break;
            }
            case 4:{
                string name;
                cout << "Enter the name of the item: "; cin >> name;
                get_item(items, name);
                break;
            }
            case 5:{
                int quantity;
                string name;
                cout << "Enter the name of the supplied item: "; cin >> name;
                cout << "Enter the bought quantity: "; cin >> quantity;
                supply_item(items, name, quantity);
                break;
            }
            case 6:{
                int quantity;
                string name;
                cout << "Enter the name of the sold item: "; cin >> name;
                cout << "Enter the sold quantity: "; cin >> quantity;
                sold_item(items, name, quantity);
                break;
            }
            case 7:{
                cout << "Have a nice day!\n";
                fout.close();
                break;
            }
            default: cout << "Option not available, please try again!\n";
        }
    }
}
