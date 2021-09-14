#ifndef OUTORDER_H
#define OUTORDER_H
#include "Menu.h"
#include "MenuList.h"
#include "MenuIO.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class OutOrder
{
private:
    vector<Menu> out_order;
public:
    OutOrder(vector<Menu> out_order_param)
    {
        out_order = out_order_param;
    }

    void set_out_order()
    {
        out_order = MenuIO::menu_inputF("Out_order.txt");
    }

    vector<Menu> get_out_order() const
    {
        return out_order;
    }
    //------------------------------------manager only access---------------------------------------------
    // add dish that is out of stock into the out_order vector
    void add_out_order(Menu m)
    {
        if (m.get_price() == 0.0 && m.get_food() == "non")
        {
            cout << "Please try again.\n";
        }
        else
        {
            out_order.push_back(m);
        }
    }
    // remove dish that get restock out of out_order vector
    OutOrder operator-= (int num)
    {
        // Find numbers of foods in menu 
        int limit_num = 0;
        for (Menu m : out_order)
        {
            limit_num++;
        }

        // if input number > than the numbers of foods in menu or = 0, invalid number
        if (num > limit_num || num == 0)
        {
            cout << "Invalid number! There are " << out_order.size() << " dishes in the order!\n";
            cout << "Please try again.\n";
        }
        // take out the food
        else
        {
            int i = num - 1;
            out_order.erase(out_order.begin() + i);
        }

        return *this;
    }
    // clear a whole out_order vector 
    // if all dishes that listed in it are got restock
    friend void clear_out_order_list(OutOrder& out);
    //-------------------------------------------------------------------------------------------
    
    // display all dishes that listed in out_order vector
    friend void display_out_order_list(OutOrder& out);
    
};

#endif
