//
// Created by Vlad Cozma on 07.12.2024.
//

#ifndef INVENTORY_SYSTEM_INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_INVENTORY_SYSTEM_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

string store_name = "Your store's";
string currency = "£";
ofstream fout("Inventory.file", ios::app);

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

void initialize(vector<Item>& items) {
    ifstream fin("Inventory.file");
    if (!fin.is_open()) {
        cout << "No inventory file found. Starting with an empty inventory.\n";
        return;
    }

    string line;
    while (getline(fin, line)) {
        size_t pos = 0;
        Item item;

        pos = line.find(',');
        item.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        item.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        item.quantity = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        item.price = stod(line);

        items.push_back(item);
    }
    fin.close();
}

void save_item(const vector<Item>& items) {
    fout.close();
    fout.open("Inventory.file", ios::trunc);
    for (const auto& item : items) {
        fout << item.name << ","
             << item.id << ","
             << item.quantity << ","
             << fixed << setprecision(2) << item.price << "\n";
    }
    fout.close();
}

void see_inv(const vector<Item>& items) {
    bool showed = false;
    for (const auto& item : items) {
        cout << "\n" << item.name << ": \n";
        cout << "   Id: " << item.id << "\n";
        cout << "   Quantity in stock: " << item.quantity << "\n";
        cout << "   Price: " << fixed << setprecision(2) << item.price << " " << currency << "\n";
        showed = true;
    }
    if (!showed) cout << "No items registered!\n";
}

void add_item(vector<Item>& items) {
    Item item;
    cout << "Enter item id: "; cin >> item.id;
    cin.ignore();
    cout << "Enter item name: "; getline(cin, item.name);
    cout << "Enter item quantity: "; cin >> item.quantity;
    cout << "Enter item price: "; cin >> item.price;
    items.push_back(item);
    save_item(items);
    cout << "\nItem added successfully!\n";
}

void get_item(const vector<Item>& items, const string& item_name) {
    for (const auto& item : items) {
        if (item.name == item_name) {
            cout << "\n" << item.name << ": \n";
            cout << "   Id: " << item.id << "\n";
            cout << "   Quantity in stock: " << item.quantity << "\n";
            cout << "   Price: " << fixed << setprecision(2) << item.price << " " << currency << "\n";
            return;
        }
    }
    cout << "Item not found!\n";
}

void supply_item(vector<Item> &items, const string item_name, const int quantity){
    for (auto &item : items){
        if (item.name == item_name){
            item.quantity += quantity;
            save_item(items);
            cout << "\nItem successfully updated!\n";
            return;
        }
    }
    cout << "Item not found!\n";
}

void sold_item(vector<Item> &items, const string item_name, const int quantity){
    for (auto &item : items){
        if (item.name == item_name){
            item.quantity -= quantity;
            save_item(items);
            cout << "Item successfully updated!\n";
            cout << "You made a sale of: " << item.price * quantity << " " << currency << "!\n";
            return;
        }
    }
    cout << "Item not found!\n";
}

void delete_item(vector<Item> &items, const string& item_name){
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == item_name) {
            items.erase(it);
            save_item(items);
            cout << "\nItem successfully deleted!\n";
            return;
        }
    }
    cout << "Item not found!\n";
}

#endif //INVENTORY_SYSTEM_INVENTORY_SYSTEM_H
