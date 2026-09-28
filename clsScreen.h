#pragma once
#include <iostream>
#include<string>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t\033[33m________________________________________\033[0m";
        cout << "\n\n\t\t\t\t\t\033[33m  " << Title << "\033[0m";
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t\033[33m________________________________________\033[0m\n";
        cout << "\n\n\t\t\t\t\t\033[34mUser: \033[0m" << CurrentUser.GetUserName();
        cout << "\n\t\t\t\t\tDate: " << clsDate::GetSystemDateTimeString();
        //cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());
        cout << "\n";
    }

    static void _DrawMainScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t\033[33m________________________________________\033[0m";
        cout << "\n\n\t\t\t\t\t\033[33m  " << Title << "\033[0m";
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t\033[33m________________________________________\033[0m\n";
        cout << "\n\t\t\t\t\tDate: " << clsDate::GetSystemDateTimeString();
        //cout << "\n\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());
        cout << "\n";
    }

    static void _DrawATMScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t\033[33m________________________________________\033[0m";
        cout << "\n\n\t\t\t\t\t\033[33m  " << Title << "\033[0m";
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t\033[33m________________________________________\033[0m\n";
        cout << "\n\n\t\t\t\t\t\033[34mClient: \033[0m" << CurrentClient.FullName();
        cout << "\n\t\t\t\t\tDate: " << clsDate::GetSystemDateTimeString();
        //cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());
        cout << "\n";
    }

    static bool CeckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";

            return false;
        }
        else
        {
            return true;
        }

    }
};

