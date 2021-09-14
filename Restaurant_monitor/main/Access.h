#ifndef ACCESS_H
#define ACCESS_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Access
{
private:
    string id;
    string pass;
public:
    Access(string id_param, string pass_param)
    {
        id = id_param;
        pass = pass_param;
    }

    void set_id(string id_param)
    {
        id = id_param;
    }

    string get_id() const
    {
        return id;
    }

    void set_pass(string pass_param)
    {
        pass = pass_param;
    }

    string get_pass() const
    {
        return pass;
    }
};

#endif
