#ifndef MENUIO_H
#define MENUIO_H
#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class MenuIO
{
public:
    // input file for Noodle.txt, Rice.txt, Special.txt, Drink.txt, and Out_order.txt
    static vector<Menu> menu_inputF(string txt_name)
    {
        vector<Menu> templist;
        ifstream inputF(txt_name);
        if (inputF)
        {
            Menu menu("a", 1.1);
            string temp_food;
            double temp_price;
            string line;

            while (getline(inputF, line))
            {
                stringstream ss(line);
                getline(ss, temp_food, '\t');
                ss >> temp_price;
                menu.set_food(temp_food);
                menu.set_price(temp_price);
                templist.push_back(menu);
            }
            inputF.close();
        }
        else
        {
            cout << "Error! Unable to open file: " << txt_name << endl;
        }
        return templist;
    }

    // output file for Noodle.txt, Rice.txt, Special.txt, Drink.txt, and Out_order.txt
    static void menu_outputF(vector<Menu> tlist, string txt_name)
    {
        ifstream inputF(txt_name);
        ofstream temp;
        temp.open("temp.txt"); // create tempurary file
        // put all element from tasklist vector into tempurary file
        for (Menu m : tlist)
        {
            temp << m.get_food() << "\t" << m.get_price() << endl;
        }

        temp.close();
        inputF.close();

        // delete old file,
        // then rename tempurary file to the name of the old file
        if (txt_name == "Rice.txt")
        {
            remove("Rice.txt");
            rename("temp.txt", "Rice.txt");
        }
        else if (txt_name == "Special.txt")
        {
            remove("Special.txt");
            rename("temp.txt", "Special.txt");
        }
        else if (txt_name == "Drink.txt")
        {
            remove("Drink.txt");
            rename("temp.txt", "Drink.txt");
        }
        else if (txt_name == "Noodle.txt")
        {
            remove("Noodle.txt");
            rename("temp.txt", "Noodle.txt");
        }
        else if (txt_name == "Out_order.txt")
        {
            remove("Out_order.txt");
            rename("temp.txt", "Out_order.txt");
        }
    }

};

#endif
