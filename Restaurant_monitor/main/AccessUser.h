#ifndef ACCESSUSER_H
#define ACCESSUSER_H
#include "Access.h"
#include "AccessIO.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AccessUser
{
private:
    vector<Access> user;
public:
    AccessUser(vector<Access> user_param)
    {
        user = user_param;
    }

    void set_user(vector<Access> user_param)
    {
        user = user_param;
    }

    vector<Access> get_user() const
    {
        return user;
    }
    // check the input ID and password from user
    bool check_user(string id, string pass)
    {
        int id_check = 0;
        int pass_check = 0;
        for (Access a : user)
        {
            // check ID by loop throught user vector
            if (id == a.get_id())
            {
                id_check++; // add 1 to id_check when matched ID found in user vector
                // check password that match the password that equivalent to previous ID
                if (pass == a.get_pass())
                {
                    pass_check++; // add 1 to id_check when matched password found in user vector
                }

                break;
            }
        }
        // if ID is NOT found in user vector
        if (id_check == 0)
        {
            cout << "The ID is not exist in the system!\n";
            return false;
        }
        // if ID is found in user vector, now check for password
        else
        {
            // if password is NOT matched with the password that equivalent to the previous ID
            if (pass_check == 0)
            {
                cout << "Wrong Password!\n";
                return false;
            }
            // if password is matched with the password that equivalent to the previous ID
            else
            {
                return true;
            }
        }
    }
};


#endif
