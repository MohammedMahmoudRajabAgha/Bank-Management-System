#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;

class clsDeleteUserScreen :protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


public:

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Is NOT Found, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you Sure Do you want to Delete this User y/n: ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (User1.Delete())
            {
                cout << "\nUser Deleted Succeessfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError, User Wasn't Deleted :-(\n";
            }
        }
    }


};

