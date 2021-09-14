#ifndef NOODLESOUP_H
#define NOODLESOUP_H
#include "Menu.h"
#include "Noodle.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NoodleSoup : public Noodle
{
private:
    vector<Menu> noodlesoup;
public:
    NoodleSoup(vector<Menu> noodlesoup_param, vector<Menu> noodle) : Noodle(noodle)
    {
        noodlesoup = noodlesoup_param;
    }

    void set_noodlesoup()
    {
        // clear the previous values of subclass' vector
        // so when add new dish to vector from parent class
        // old values in the subclass' vector is not stack up
        noodlesoup.clear();

        for (Menu m : noodle)
        {
            // In Vietnamese, "Pho" and "Bun" is the type of noodle,
            // when these words include, it mostly mean this is noodle soup
            if (m.get_food().find("Pho") != string::npos ||
                m.get_food().find("Bun") != string::npos)
            {
                noodlesoup.push_back(m);
            }
        }
    }

    vector<Menu> get_noodlesoup() const
    {
        return noodlesoup;
    }
    //--------------------------------------only access by manager----------------------------
     // take 'Menu' value based on int value parameter from noodlesoup vector
    //and return to add_out_order() in OutOrder.h
    Menu take_runout_order(int num)
    {
        Menu order;
        // Find numbers of foods in menu 
        int limit_num = 0;
        for (Menu m : noodlesoup)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            order = { "non", 0.0 };
            cout << "Invalid number! There are " << noodlesoup.size() << " dishes in the menu!\n";
        }
        // take the food and put in the order
        else
        {
            int count = 1;

            for (Menu m : noodlesoup)
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
     // take 'Menu' value based on int value parameter from noodlesoup vector 
    //and return to add_order() in Order.h
    Menu take_order(int num)
    {
        Menu order;
        OutOrder out({ });
        out.set_out_order();

        // Find numbers of foods in menu 
        int limit_num = 0;
        for (Menu m : noodlesoup)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            order = { "non", 0.0 };
            cout << "Invalid number! There are " << noodlesoup.size() << " dishes in the menu!\n";
        }
        // take the food and put in the order
        else
        {
            int count = 1;

            for (Menu m : noodlesoup)
            {
                if (count == num)
                {
                    order = m;
                    break;
                }
                count++;
            }
            // check if the food is listed in the out_order vector
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
    // display noodle soup dishes in noodle menu
    // override pure virtual function from super class Noodle
    void display_noodle() override final
    {
        int i = 1;
        for (Menu m : noodlesoup)
        {
            cout << i << ". " << m.get_food() << "\t\t" << m.get_price() << endl;
            i++;
        }
    }
};

#endif
