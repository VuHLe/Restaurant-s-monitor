/*
Vu Hong Le
COP3331.002S21.22079
Flex Project
4/25/2021
*/
#include "Menu.h"
#include "MenuIO.h"
#include "MenuList.h"
#include "Order.h"
#include "Noodle.h"
#include "NoodleSoup.h"
#include "NoodleDry.h"
#include "OutOrder.h"
#include "Function.h"
#include "Access.h"
#include "AccessIO.h"
#include "AccessUser.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        int access;
        access = login();// login to the system
        //--------------------------------------EMPLOYEE ACCESS------------------------------------------
        if (access == 2)
        {
            bool loop1 = true;
            while (loop1 == true)
            {
                MenuList rice({ });
                MenuList special({ });
                MenuList drink({ });
                Order order({ }, { });
                NoodleSoup noodle_soup({ }, { });
                NoodleDry noodle_dry({ }, { });

                noodle_soup.set_noodle();
                noodle_soup.set_noodlesoup();
                noodle_dry.set_noodle();
                noodle_dry.set_noodledry();
                rice.set_menulist(MenuIO::menu_inputF("Rice.txt"));
                special.set_menulist(MenuIO::menu_inputF("Special.txt"));
                drink.set_menulist(MenuIO::menu_inputF("Drink.txt"));

                int option;
                cout << "OPTION: \n"
                    << "1. Write Check\n"
                    << "2. Show All Menu\n"
                    << "3. Show Out_Order's List\n"
                    << "0. EXIT\n\n";

                cout << "Option: ";
                cin >> option;
                switch (option)
                {
                // write payment bill to customer
                case 1:
                    writing_check(noodle_soup, noodle_dry, rice, special, drink, order);
                    cout << "_________________________________________________________________\n";
                    break;
                // show ALL dishes in menu
                case 2:
                    show_all_menu(noodle_soup, rice, special, drink);
                    cout << "_________________________________________________________________\n";
                    break;
                // show ALL out of order dishes
                case 3:
                {
                    OutOrder out({ });
                    out.set_out_order();
                    // if the vector is not empty
                    if (!out.get_out_order().empty())
                    {
                        display_out_order_list(out);
                        cout << endl;
                    }
                    // if the vector is empty
                    else
                    {
                        cout << "There are currently no run out dishes!\n";
                    }
                    cout << "_________________________________________________________________\n";
                    break;
                }
                // EXIT
                case 0:
                    loop1 = false;
                    break;
                // invalid input 
                default:
                    cout << "Invalid Option! Only input number from 0 to 3!\n\n";
                    break;
                }
            }
        }
        //----------------------------------------MANAGER ACCESS-------------------------------------------
        else if (access == 1)
        {
            bool loop2 = true;
            while (loop2 == true)
            {
                MenuList rice({ });
                MenuList special({ });
                MenuList drink({ });
                Order order({ }, { });
                NoodleSoup noodle_soup({ }, { });
                NoodleDry noodle_dry({ }, { });

                noodle_soup.set_noodle();
                noodle_soup.set_noodlesoup();
                noodle_dry.set_noodle();
                noodle_dry.set_noodledry();
                rice.set_menulist(MenuIO::menu_inputF("Rice.txt"));
                special.set_menulist(MenuIO::menu_inputF("Special.txt"));
                drink.set_menulist(MenuIO::menu_inputF("Drink.txt"));

                int option;
                cout << "OPTION: \n"
                    << "1. Write Check\n"
                    << "2. Edit Menu\n"
                    << "3. Edit Out Order's List\n"
                    << "4. Show All Menu\n"
                    << "5. Show Out_Order's List\n"
                    << "0. EXIT\n\n";

                cout << "Option: ";
                cin >> option;
                switch (option)
                {
                // writing payment bill to customer
                case 1:
                    writing_check(noodle_soup, noodle_dry, rice, special, drink, order);
                    cout << "_________________________________________________________________\n";
                    break;
                // edit the menu
                case 2:
                    edit_menu(noodle_soup, rice, special, drink);
                    cout << "_________________________________________________________________\n";
                    break;
                // edit out of stock list
                case 3:
                {
                    OutOrder out({ });
                    out.set_out_order();
                    edit_out_order_list(noodle_soup, noodle_dry, rice, special, drink, out);
                    cout << "_________________________________________________________________\n";
                    break;
                }
                // display ALL dishes in menu
                case 4:
                    show_all_menu(noodle_soup, rice, special, drink);
                    cout << "_________________________________________________________________\n";
                    break;
                // display ALL out of stock dishes
                case 5:
                {
                    OutOrder out({ });
                    out.set_out_order();
                    // if the vector is not empty
                    if (!out.get_out_order().empty())
                    {
                        display_out_order_list(out);
                        cout << endl;
                    }
                    // if the vector is empty
                    else
                    {
                        cout << "There are currently no run_out dishes exist!\n\n";
                    }
                    cout << "_________________________________________________________________\n";
                    break;
                }
                // EXIT
                case 0:
                    loop2 = false;
                    break;
                // invalid input
                default:
                    cout << "Invalid Option! Only input number from 0 to 5!\n\n";
                    break;
                }
            }
        }
        // EXIT the system
        else if (access == 3)
        {
            cout << "Bye!\n";
            break;
        }
        // invalid input
        else if (access == 0)
        {
            cout << "Please Try Again!\n";
        }
    }
    return EXIT_SUCCESS;
}

