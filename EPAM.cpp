#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
using namespace std;

struct Product {
    string name;
    double price;
};

bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void addProduct(vector<Product>& products) {
    system("cls");
    string strPrice;
    Product product;
    cout << "Name: ";
    getline(cin, product.name);
    system("cls");
    a:
    cout << "Price: ";
    getline(cin, strPrice);
    
    if (is_number(strPrice)) {
        product.price = stoi(strPrice);
        products.push_back(product);
        cout << "Product has been added.\n";
        Sleep(500);
        system("cls");
    }
    else {
        cout << "Invalid, try again\n";
        Sleep(500);
        system("cls");
        goto a;
    }
}

void displayProducts(const vector<Product>& products) {
    system("cls");
    cout << "List:\n";
    for (const auto& product : products) {
        cout << "Name: " << product.name << ", Price: " << product.price << endl;
    }
    system("pause");
    system("cls");
}

int main() {
    vector<Product> products;

    string choice;
    int num = 0;
    do
    {
        cout << "Menu:\n";
        cout << "1. Add product\n";
        cout << "2. Show all products\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        getline(cin, choice);
        
        try {
            num = stoi(choice);
        }
        catch (const invalid_argument& e) {
            cerr << "Invalid input. Please enter a valid number.\n";
            Sleep(500);
            system("cls");
            continue; 
        }

        switch (num) {
        case 1:
            addProduct(products);
            break;
        case 2:
            displayProducts(products);
            break;
        case 3:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid, try again\n";
            Sleep(500);
            system("cls");
            break;
        }
    } while (num != 3);

    return 0;
}
