#ifndef MENULIST_H
#define MENULIST_H

#include "Menu.h"
#include "OutOrder.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuList
{
private:
    vector<Menu> menulist;
public:
    MenuList(vector<Menu> menulist_param)
    {
        menulist = menulist_param;
    }

    void set_menulist(vector<Menu> menulist_param)
    {
        menulist = menulist_param;
    }

    vector<Menu> get_menulist() const
    {
        return menulist;
    }
    //------------------------------------only access by manager---------------------------------
    // Add new dish to menu
    void add_dish(string food_name, double food_price)
    {
        int count = 0;
        // check if there are the exist dish in the menu
        for (Menu m : menulist)
        {
            if (m.get_food() == food_name)
            {
                count++;
                break;
            }
        }

        // if the adding dish is not exist in the menu
        if (count == 0)
        {
            Menu menu(food_name, food_price);
            menulist.push_back(menu);
        }

        else
        {
            cout << "The food is already exist in Menu! Please try again!\n";
        }
    }
    // take out dish that do not want to sale no more from the menu
    MenuList operator-= (int num)
    {
        // Find numbers of foods in menu 
        int limit_num = 0;
        for (Menu m : menulist)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            cout << "Invalid number! There are " << menulist.size() << " dishes in the menu!\n";
            cout << "Please try again.\n";
        }
        // take out the food
        else
        {
            int i = num - 1;
            menulist.erase(menulist.begin() + i);
        }
        return menulist;
    }
    // take 'Menu' value based on int value parameter from menulist vector
    //and return to add_out_order() in OutOrder.h
    Menu take_runout_order(int num)
    {
        Menu order;
        // Find numbers of foods in menu 
        int limit_num = 0;
        for (Menu m : menulist)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            order = { "non", 0.0 };
            cout << "Invalid number! There are " << menulist.size() << " dishes in the menu!\n";
        }
        // take the food and put in the order
        else
        {
            int count = 1;

            for (Menu m : menulist)
            {
                if (count == num)
                {
                    order = m;
                    break;
                }
                count++;
            }
        }
        return order;
    }
    //---------------------------------------------------------------------------------------
    // take 'Menu' value based on int value parameter from menulist vector
    //and return to add_order() in Order.h
    Menu take_order(int num)
    {
        Menu order;
        OutOrder out({ });
        out.set_out_order();

        // Find numbers of foods in menu 
        int limit_num = 0;
        for (Menu m : menulist)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            order = { "non", 0.0 };
            cout << "Invalid number! There are " << menulist.size() << " dishes in the menu!\n";
        }
        // take the food and put in the order
        else
        {
            int count = 1;

            for (Menu m : menulist)
            {
                if (count == num)
                {
                    order = m;
                    break;
                }
                count++;
            }
            // check if the food is listed in the out_order vector list
            for (Menu n : out.get_out_order())
            {
                if (order.get_food() == n.get_food())
                {
                    order = { "non", 0.0 };
                    cout << "Sorry! This dish is run out of order!\n";
                    break;
                }
            }
        }
        return order;
    }
    // display dishes in menu
    void display_menu()
    {
        int i = 1;
        for (Menu m : menulist)
        {
            cout << i << ". " << m.get_food() << "\t\t" << m.get_price() << endl;
            i++;
        }
    }

};

#endif