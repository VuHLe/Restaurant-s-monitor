#ifndef ORDER_H
#define ORDER_H
#include "Menu.h"
#include "MenuList.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Order
{
private:
    vector<Menu> order;
    vector<int> quantity;
public:
    Order(vector<Menu> order_param, vector<int> quantity_param)
    {
        order = order_param;
        quantity = quantity_param;
    }
    // add order to customer's bill
    void add_order(Menu m)
    {
        if (m.get_price() == 0.0 && m.get_food() == "non")
        {
            cout << "Please try again.\n";
        }
        else
        {
            order.push_back(m);
        }
    }

    vector<Menu> get_order() const
    {
        return order;
    }

    void set_quantity(int num)
    {
        quantity.push_back(num);
    }

    vector<int> get_quantity() const
    {
        return quantity;
    }
    // take order out from customer's bill
    Order operator-= (int num)
    {
        // Find numbers of foods in bill
        int limit_num = 0;
        for (Menu m : order)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            cout << "Invalid number! There are " << order.size() << " dishes in the order!\n";
            cout << "Please try again.\n";
        }
        // take out the food
        else
        {
            int i = num - 1;
            order.erase(order.begin() + i);
            quantity.erase(quantity.begin() + i);
        }

        return *this;
    }
    // Add total prices of all the orders in customer's bill
    double total_bill()
    {
        double bill = 0;
        for (int i = 0; i < order.size(); i++)
        {
            bill = bill + (quantity[i] * order[i].get_price());
        }

        return bill;
    }
    // Display the customer's check
    void display_order()
    {
        int index = 1;
        cout << "-----------------------------------------------\n";
        cout << "CHECK: \n";
        for (int i = 0; i < order.size(); i++)
        {
            cout << index << ". " << quantity[i] << " "
                << order[i].get_food() << "\t\t" << order[i].get_price() << endl;

            index++;
        }

        cout << endl;

        double tax = total_bill() * 6 / 100;// calculate tax
        cout << setprecision(2) << fixed;

        cout << "Total: " << total_bill() << endl;
        cout << "Tax: " << tax << endl;
        cout << "TOTAL BILL: " << total_bill() + tax << endl;// total price + tax
        cout << "-----------------------------------------------\n";
    }
};

#endif
