#ifndef NOODLE_H
#define NOODLE_H
#include "Menu.h"
#include "MenuIO.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Noodle
{
protected:
    vector<Menu> noodle;
public:
    Noodle(vector<Menu> noodle_param)
    {
        noodle = noodle_param;
    }

    void set_noodle()
    {
        noodle = MenuIO::menu_inputF("Noodle.txt");
    }

    vector<Menu> get_noodle() const
    {
        return noodle;
    }
    //------------------------------------only access by manager---------------------------------
    // add new noodle dish to noodle menu
    void add_noodle(string food_name, double food_price)
    {
        int count = 0;
        // check if there are the exist dish in the menu
        for (Menu m : noodle)
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
            noodle.push_back(menu);
        }

        else
        {
            cout << "The food is already exist in Menu! Please try again!\n";
        }
    }
    // remove noodle dish that do not want to sale no more out of noodle menu
    Noodle& operator-= (int num)
    {
        // Find numbers of foods in menu 
        int limit_num = 0;
        for (Menu m : noodle)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            cout << "Invalid number! There are " << noodle.size() << " dishes in the menu!\n";
            cout << "Please try again.\n";
        }
        // take out the food
        else
        {
            int i = num - 1;
            noodle.erase(noodle.begin() + i);
        }
        return *this;
    }
    //---------------------------------------------------------------------------------------
    // display ALL noodle dishes in menu
    void display_all_noodle()
    {
        int i = 1;
        for (Menu m : noodle)
        {
            cout << i << ". " << m.get_food() << "\t\t" << m.get_price() << endl;
            i++;
        }
    }
    // pure virtual function, display noodle soup/dry dishes in menu
    virtual void display_noodle() = 0;

};

#endif
