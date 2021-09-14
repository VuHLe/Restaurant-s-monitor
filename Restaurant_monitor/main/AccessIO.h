#ifndef ACCESSIO_H
#define ACCESSIO_H
#include "Access.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class AccessIO
{
public:
    // input file for Employee.txt and Manager.txt
    static vector<Access> access_inputF(string txt_name)
    {
        vector<Access> templist;
        ifstream inputF(txt_name);
        if (inputF)
        {
            Access access("a", "b");
            string temp_id;
            string temp_pass;
            string line;

            while (getline(inputF, line))
            {
                stringstream ss(line);
                getline(ss, temp_id, '\t');
                getline(ss, temp_pass);
                access.set_id(temp_id);
                access.set_pass(temp_pass);
                templist.push_back(access);
            }
            inputF.close();
        }
        else
        {
            cout << "Error! Unable to open file: " << txt_name << endl;
        }
        return templist;
    }
};

#endif
