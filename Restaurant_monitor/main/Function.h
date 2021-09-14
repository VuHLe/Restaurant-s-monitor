#ifndef FUNCTION_H
#define FUNCTION_H
#include "Menu.h"
#include "MenuIO.h"
#include "MenuList.h"
#include "Order.h"
#include "Noodle.h"
#include "NoodleSoup.h"
#include "NoodleDry.h"
#include "OutOrder.h"
#include "Access.h"
#include "AccessIO.h"
#include "AccessUser.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// function that write bill to customer
void writing_check(NoodleSoup noodle_soup, NoodleDry noodle_dry,
    MenuList rice, MenuList special, MenuList drink, Order order)
{
    int choice_menu;
    bool loop = true;

    while (loop == true)
    {
        cout << "CHOOSE MENU TO ADD DISH TO ORDER: \n"
            << "1. Noodle soup\n"
            << "2. Noodle dry\n"
            << "3. Rice\n"
            << "4. Special\n"
            << "5. Drink\n\n"
            << "BILL OPTION: \n"
            << "6. Show bill\n"
            << "7. Remove order\n"
            << "0. CHECK OUT and EXIT\n\n";

        cout << "Input: ";
        cin >> choice_menu;
        cout << endl;

        switch (choice_menu)
        {
        // if take dishes from noodle soup
        case 1:
        {
            int choice_food;
            int quantity;
            Menu dish;
   
            noodle_soup.display_noodle(); // display the noodle soup menu
            cout << endl;
            cout << "Choose dish: ";
            cin >> choice_food; // input number that next to the dish's name to choice_food
            dish = noodle_soup.take_order(choice_food); // return choosed dish based on choice_food
            order.add_order(dish); // add choosed dish to bill
            // if the return dish's name is "non" and price is "0", 
            // which mean the input number for choice_food is invalid
            // else ask for quantity of the dish
            if (dish.get_price() != 0.0 && dish.get_food() != "non")
            {
                cout << "Quantity: ";
                cin >> quantity;
                order.set_quantity(quantity);
            }
            cout << endl;
            break;
        }
        // if take dishes from noodle dry
        case 2:
        {
            int choice_food;
            int quantity;
            Menu dish;

            noodle_dry.display_noodle();// display the noodle dry menu
            cout << endl;
            cout << "Choose dish: ";
            cin >> choice_food;// input number that next to the dish's name to choice_food
            dish = noodle_dry.take_order(choice_food);// return choosed dish based on choice_food
            order.add_order(dish);// add choosed dish to bill
            // if the return dish's name is "non" and price is "0", 
            // which mean the input number for choice_food is invalid
            // else ask for quantity of the dish
            if (dish.get_price() != 0.0 && dish.get_food() != "non")
            {
                cout << "Quantity: ";
                cin >> quantity;
                order.set_quantity(quantity);
            }
            cout << endl;
            break;
        }
        // if take dishes from rice
        case 3:
        {
            int choice_food;
            int quantity;
            Menu dish;

            rice.display_menu();// display the rice menu
            cout << endl;
            cout << "Choose dish: ";
            cin >> choice_food;// input number that next to the dish's name to choice_food
            dish = rice.take_order(choice_food);// return choosed dish based on choice_food
            order.add_order(dish);// add choosed dish to bill
            // if the return dish's name is "non" and price is "0", 
            // which mean the input number for choice_food is invalid
            // else ask for quantity of the dish
            if (dish.get_price() != 0.0 && dish.get_food() != "non")
            {
                cout << "Quantity: ";
                cin >> quantity;
                order.set_quantity(quantity);
            }
            cout << endl;
            break;
        }
        // if take dishes from special
        case 4:
        {
            int choice_food;
            int quantity;
            Menu dish;

            special.display_menu();// display the special menu
            cout << endl;
            cout << "Choose dish: ";
            cin >> choice_food;// input number that next to the dish's name to choice_food
            dish = special.take_order(choice_food);// return choosed dish based on choice_food
            order.add_order(dish);// add choosed dish to bill
            // if the return dish's name is "non" and price is "0", 
            // which mean the input number for choice_food is invalid
            // else ask for quantity of the dish
            if (dish.get_price() != 0.0 && dish.get_food() != "non")
            {
                cout << "Quantity: ";
                cin >> quantity;
                order.set_quantity(quantity);
            }
            cout << endl;
            break;
        }
        // if take dishes from drink
        case 5:
        {
            int choice_food;
            int quantity;
            Menu dish;

            drink.display_menu();// display the drink menu
            cout << endl;
            cout << "Choose dish: ";
            cin >> choice_food;// input number that next to the dish's name to choice_food
            dish = drink.take_order(choice_food);// return choosed dish based on choice_food
            order.add_order(dish);// add choosed dish to bill
            // if the return dish's name is "non" and price is "0", 
            // which mean the input number for choice_food is invalid
            // else ask for quantity of the dish
            if (dish.get_price() != 0.0 && dish.get_food() != "non")
            {
                cout << "Quantity: ";
                cin >> quantity;
                order.set_quantity(quantity);
            }
            cout << endl;
            break;
        }
        // if want to show customer's bill
        case 6:
        {
            // if the bill is not empty
            if (!order.get_order().empty())
            {
                order.display_order();
                cout << endl;
            }
            // if the bill is empty
            else
            {
                cout << "Bill is currently empty!\n\n";
            }
            break;
        }
        // if customer want to remove unwanted dish out of their bill
        case 7:
        {
            // if the bill is not empty
            if (!order.get_order().empty())
            {
                int edit_food;
                order.display_order();
                cout << endl;
                cout << "Choose remove order: ";
                cin >> edit_food; // input the number next to the dish that want to remove
                order -= edit_food; // take that dish out of the bill
                cout << endl;
            }
            // if the bill is empty
            else
            {
                cout << "Cannot remove dish! Bill is currently empty!\n\n";
            }
            break;
        }
        // if want to CHECK OUT and EXIT the function
        case 0:
        {
            loop = false;
            // if the bill is not empty, else display nothing
            if (!order.get_order().empty())
            {
                order.display_order();
            }
            cout << endl;
            break;
        }
        // if invalid input number
        default:
        {
            cout << "Invalid Input! Only input numbers from 0 to 7.\n";
            cout << "Please try again!\n\n";
            break;
        }
        }
    }
}
//------------------------------------------------------------------------------------
// function that edit the menu
void edit_menu(NoodleSoup noodle_soup,
    MenuList rice, MenuList special, MenuList drink)
{
    int choice_menu;
    bool loop = true;

    while (loop == true)
    {
        cout << "CHOOSE MENU TO EDIT: \n"
            << "1. Noodle\n"
            << "2. Rice\n"
            << "3. Special\n"
            << "4. Drink\n"
            << "0. DONE and EXIT\n\n";

        cout << "Input: ";
        cin >> choice_menu; // choose menu type to edit
        cout << endl;

        int option = 0;
        // if choice_menu is not 0, which is EXIT
        if (choice_menu != 0 && choice_menu != 5)
        {
            cout << "CHOOSE OPTION: \n"
                << "1. Add dish\n"
                << "2. Remove dish\n\n";
            cout << "Option: ";
            cin >> option;
            cout << endl;
        }

        switch (choice_menu)
        {
        // if choose noodle
        case 1:
        {
            // if add new dish to menu
            if (option == 1)
            {
                string name;
                double price;
                cout << "Name of new dish: ";
                cin.ignore(100, '\n');
                getline(cin, name);
                cout << "Price of new dish: ";
                cin >> price;

                // add new dish
                noodle_soup.add_noodle(name, price);
                cout << endl;

                // show new menu
                cout << "------------------NEW MENU----------------\n";
                noodle_soup.display_all_noodle();
                cout << "------------------------------------------";
                cout << endl;
            }
            // if remove dish that do not want to sale no more out of menu
            else if (option == 2)
            {
                int remove_dish;
                noodle_soup.display_all_noodle();// display noodle menu
                cout << endl;
                cout << "Choose remove dish: ";
                cin >> remove_dish;// choose number next to the dish that want to remove
                cout << endl;

                // remove the dish
                noodle_soup -= remove_dish;

                cout << "------------------NEW MENU----------------\n";
                noodle_soup.display_all_noodle(); // show new menu
                cout << "------------------------------------------";
                cout << endl;
            }
            // if input invalid number
            else
            {
                cout << "Invalid Input for option! Only enter number 1 and 2!\n";
                cout << "Please try again!\n\n";
            }
            break;
        }
        // if choose rice
        case 2:
        {
            // if add new dish to menu
            if (option == 1)
            {
                string name;
                double price;
                cout << "Name of new dish: ";
                cin.ignore(100, '\n');
                getline(cin, name);
                cout << "Price of new dish: ";
                cin >> price;

                rice.add_dish(name, price); // add new dish 
                cout << endl;
                // show new menu
                cout << "------------------NEW MENU----------------\n";
                rice.display_menu();
                cout << "------------------------------------------";
                cout << endl;
            }
            // if remove dish that do not want to sale no more out of menu
            else if (option == 2)
            {
                int remove_dish;
                rice.display_menu();// display rice menu
                cout << endl;
                cout << "Choose remove dish: ";
                cin >> remove_dish;// choose number next to the dish that want to remove
                cout << endl;

                rice -= remove_dish; // remove the dish
                cout << "------------------NEW MENU----------------\n";
                rice.display_menu(); // show new menu
                cout << "------------------------------------------";
                cout << endl;
            }
            // if invalid input
            else
            {
                cout << "Invalid Input for option! Only enter number 1 and 2!\n";
                cout << "Please try again!\n\n";
            }
            break;
        }
        // if choose special
        case 3:
        {
            // if add new dish to menu
            if (option == 1)
            {
                string name;
                double price;
                cout << "Name of new dish: ";
                cin.ignore(100, '\n');
                getline(cin, name);
                cout << "Price of new dish: ";
                cin >> price;

                special.add_dish(name, price); // add new dish 
                cout << endl;
                // show new menu
                cout << "------------------NEW MENU----------------\n";
                special.display_menu();
                cout << "------------------------------------------";
                cout << endl;
            }
            // if remove dish that do not want to sale no more out of menu
            else if (option == 2)
            {
                int remove_dish;
                special.display_menu();// display special menu
                cout << endl;
                cout << "Choose remove dish: ";
                cin >> remove_dish;// choose number next to the dish that want to remove
                cout << endl;

                special -= remove_dish; // remove the dish
                cout << "------------------NEW MENU----------------\n";
                special.display_menu(); // show new menu
                cout << "------------------------------------------";
                cout << endl;
            }
            // if invalid input
            else
            {
                cout << "Invalid Input for option! Only enter number 1 and 2!\n";
                cout << "Please try again!\n\n";
            }
            break;
        }
        // if choose drink
        case 4:
        {
            // if add new dish to menu
            if (option == 1)
            {
                string name;
                double price;
                cout << "Name of new dish: ";
                cin.ignore(100, '\n');
                getline(cin, name);
                cout << "Price of new dish: ";
                cin >> price;

                drink.add_dish(name, price); // add new dish 
                cout << endl;
                // show new menu
                cout << "------------------NEW MENU----------------\n";
                drink.display_menu();
                cout << "------------------------------------------";
                cout << endl;
            }
            // if remove dish that do not want to sale no more out of menu
            else if (option == 2)
            {
                int remove_dish;
                drink.display_menu();// display special menu
                cout << endl;
                cout << "Choose remove dish: ";// choose number next to the dish that want to remove
                cin >> remove_dish;
                cout << endl;

                drink -= remove_dish; // remove the dish
                cout << "------------------NEW MENU----------------\n";
                drink.display_menu(); // show new menu
                cout << "------------------------------------------";
                cout << endl;
            }
            // if invalid input
            else
            {
                cout << "Invalid Input for option! Only enter number 1 and 2!\n";
                cout << "Please try again!\n\n";
            }
            break;
        }
        // if user DONE and EXIT, 
        // SAVE the new edited menu and renew each menu text files
        case 0:
        {
            MenuIO::menu_outputF(noodle_soup.get_noodle(), "Noodle.txt");
            MenuIO::menu_outputF(rice.get_menulist(), "Rice.txt");
            MenuIO::menu_outputF(special.get_menulist(), "Special.txt");
            MenuIO::menu_outputF(drink.get_menulist(), "Drink.txt");
            loop = false;
            break;
        }
        // if invalide input
        default:
        {
            cout << "Invalid Input! Only input numbers from 0 to 4.\n";
            cout << "Please try again!\n\n";
            break;
        }
        }
    }
}

//------------------------------------------------------------------------------------------
// Function login check if the input ID and Password is in the system
// Then give access to user if ID and Password existed in the system
int login()
{
    cout << "_______________________________VIETNAMESE RESTAUTRANT__________________________\n";
    cout << "ACCESS USER: \n"
        << "1. Employee\n"
        << "2. Manager\n"
        << "0. EXIT\n\n";

    int user;
    string login;
    string pass;
    AccessUser employee({ });
    AccessUser manager({ });
    employee.set_user(AccessIO::access_inputF("Employee.txt"));
    manager.set_user(AccessIO::access_inputF("Manager.txt"));

    cout << "User: ";
    cin >> user;
    // 1 if user is the employee, such as server, bus boy..., of the restaurant
    if (user == 1)
    {
        bool access;
        cout << "ID: ";
        cin >> login;
        cout << "Password: ";
        cin >> pass;
        // check input ID and Password
        // if input is matched with the user vector from AccessUser.h, return True, else False
        access = employee.check_user(login, pass);
        // return 2 if gain access
        if (access == true)
        {
            cout << "Access Granted.\n";
            cout << "--------------------------------------------------\n";
            return 2;
        }
        // return 0 if access deny
        else
        {
            cout << "Access Deny.\n";
            return 0;
        }
    }
    // 2 if user is the high-up position in the restaurant
    // such as Manager, Boss, or Main Chef...
    else if (user == 2)
    {
        bool access;
        cout << "ID: ";
        cin >> login;
        cout << "Password: ";
        cin >> pass;
        // check input ID and Password
        // if input is matched with the user vector from AccessUser.h, return True, else False
        access = manager.check_user(login, pass);
        // return 1 if gain access
        if (access == true)
        {
            cout << "Access Granted.\n";
            cout << "--------------------------------------------------\n";
            return 1;
        }
        // return 0 if access deny
        else
        {
            cout << "Access Deny.\n";
            return 0;
        }
    }
    // 0 is to EXIT out of the system
    else if (user == 0)
    {
        return 3;
    }
    // any input beside number 0 to 2 is invalid
    else
    {
        cout << "Invalid option!\n";
        return 0;
    }
}

//--------------------------------------------------------------------------------------
// edit the out_order list
void edit_out_order_list(NoodleSoup noodle_soup, NoodleDry noodle_dry,
    MenuList rice, MenuList special, MenuList drink, OutOrder out)
{
    int choice_menu;
    bool loop = true;

    while (loop == true)
    {
        cout << "CHOOSE MENU: \n"
            << "1. Noodle soup\n"
            << "2. Noodle dry\n"
            << "3. Rice\n"
            << "4. Special\n"
            << "5. Drink\n\n"
            << "OPTION: \n"
            << "6. Show Out_Order's List\n"
            << "7. Remove dish\n"
            << "8. Clear Whole List\n"
            << "0. EXIT\n\n";

        cout << "Input: ";
        cin >> choice_menu;
        cout << endl;

        switch (choice_menu)
        {
        // take the dish from noodle soup menu
        case 1:
        {
            int choice_food;
            Menu dish;

            noodle_soup.display_noodle();// display noodle soup menu
            cout << endl;
            cout << "Choose runout dish: ";
            cin >> choice_food;// input number that next to the dish's name
            dish = noodle_soup.take_runout_order(choice_food);// return choosed dish based on choice_food
            out.add_out_order(dish);// add dish to out_order vector
            cout << endl;
            break;
        }
        // take the dish from noodle dry menu
        case 2:
        {
            int choice_food;
            Menu dish;

            noodle_dry.display_noodle();// display noodle dry menu
            cout << endl;
            cout << "Choose runout dish: ";
            cin >> choice_food;// input number that next to the dish's name
            dish = noodle_dry.take_runout_order(choice_food);// return choosed dish based on choice_food
            out.add_out_order(dish);// add dish to out_order vector
            cout << endl;
            break;
        }
        // take the dish from rice menu
        case 3:
        {
            int choice_food;
            Menu dish;

            rice.display_menu();// display rice menu
            cout << endl;
            cout << "Choose runout dish: ";
            cin >> choice_food;// input number that next to the dish's name
            dish = rice.take_runout_order(choice_food);// return choosed dish based on choice_food
            out.add_out_order(dish);// add dish to out_order vector
            cout << endl;
            break;
        }
        // take the dish from special menu
        case 4:
        {
            int choice_food;
            Menu dish;

            special.display_menu();// display special menu
            cout << endl;
            cout << "Choose runout dish: ";
            cin >> choice_food;// input number that next to the dish's name
            dish = special.take_runout_order(choice_food);// return choosed dish based on choice_food
            out.add_out_order(dish);// add dish to out_order vector
            cout << endl;
            break;
        }
        // take the dish from drink menu
        case 5:
        {
            int choice_food;
            Menu dish;

            drink.display_menu();// display drink menu
            cout << endl;
            cout << "Choose runout dish: ";
            cin >> choice_food;// input number that next to the dish's name
            dish = drink.take_runout_order(choice_food);// return choosed dish based on choice_food
            out.add_out_order(dish);// add dish to out_order vector
            cout << endl;
            break;
        }
        // display all dishes that is out_order
        case 6:
        {
            display_out_order_list(out);
            cout << endl;
            break;
        }
        // remove dish that got restock
        case 7:
        {
            // if the out_order vector is not empty
            if (!out.get_out_order().empty())
            {
                int edit_food;
                display_out_order_list(out);
                cout << endl;
                cout << "Choose remove dish: ";
                cin >> edit_food;
                out -= edit_food;// remove the dish
                cout << endl;
            }
            // if the out_order vector is empty
            else
            {
                cout << "Cannot remove dish! The list is currently empty!\n\n";
            }
            break;
        }
        // Clear a whole vector, if all foods in it got retock
        case 8:
        {
            // if the vector is not empty
            if (!out.get_out_order().empty())
            {
                clear_out_order_list(out);
                cout << "Now the out_order's list is empty.\n";
            }
            // if ther vector is empty
            else
            {
                cout << "Cannot clear the list! The list is currently empty!\n";
            }
            break;
        }
        // if user EXIT, 
        // SAVE the new edited vector and renew Out_order.txt
        case 0:
        {
            loop = false;
            MenuIO::menu_outputF(out.get_out_order(), "Out_order.txt");
            cout << endl;
            break;
        }
        // if invalid input
        default:
        {
            cout << "Invalid Input! Only input numbers from 0 to 8.\n";
            cout << "Please try again!\n\n";
            break;
        }
        }
    }
}
//--------------------------------------------------------------------------------------
// function that display a WHOLE menu
void show_all_menu(Noodle& noodle, MenuList rice, MenuList special, MenuList drink)
{
    cout << "------------------------------- M E N U ------------------------------\n";
    cout << "NOODLE: \n";
    int i = 1;
    noodle.display_all_noodle();
    cout << endl;

    cout << "RICE: \n";
    rice.display_menu();
    cout << endl;

    cout << "SPECIAL: \n";
    special.display_menu();
    cout << endl;

    cout << "DRINK: \n";
    drink.display_menu();
    cout << "-----------------------------------------------------------------------\n";
    cout << endl;
}

//---------------------------------------------------------------------------------------
// friend function that display ALL out of stock dishes
void display_out_order_list(OutOrder& out)
{
    int i = 1;
    cout << "------------------------------OUT ORDER--------------------------------\n";
    for (Menu m : out.out_order)
    {
        cout << i << ". " << m.get_food() << "\t\t" << m.get_price() << endl;
        i++;
    }
    cout << "-----------------------------------------------------------------------\n";
}
//---------------------------------------------------------------------------------------
// friend function that CLEAR a WHOLE out_order vector
void clear_out_order_list(OutOrder& out)
{
    out.out_order.clear();
}

#endif
