#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsATMMainScreen.h"
#include "Global.h"

class clsATMLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;
			cout << "Invalid Account Number/Pin Code !.\n";
                cout << "\nYou have " << (3 - FaildLoginCount) << " Trial(s) To Login.\n\n";

            }
            if (FaildLoginCount == 3)
            {
                cout << "\nYou are Locked after 3 faild Trials \n\n";
                return false;
            }

            cout << "Enter Account Number? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentClient = clsBankClient::Find(Username, Password);

            LoginFaild = CurrentClient.IsEmpty();

        } while (LoginFaild);

        //CurrentUser.RegisterLogIn();

        clsATMMainScreen::ShowATMMainMenue();
        return true;
    }

public:


    static bool ShowATMLoginScreen()
    {
        system("cls");
        _DrawATMScreenHeader("\t ATM Login Screen");
        return _Login();

    }

};

