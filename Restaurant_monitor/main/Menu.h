#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>

using namespace std;

class Menu
{
private:
    string food;
    double price;
public:
    Menu(string food_param, double price_param)
    {
        food = food_param;
        price = price_param;
    }

    Menu()
    {
        food = " ";
        price = 0;
    }

    void set_food(string food_param)
    {
        food = food_param;
    }

    string get_food() const
    {
        return food;
    }

    void set_price(double price_param)
    {
        price = price_param;
    }

    double get_price() const
    {
        return price;
    }
};

#endif
