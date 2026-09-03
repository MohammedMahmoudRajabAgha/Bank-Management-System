#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsUser.h"

#include"clsManageClientsScreen.h"
#include"clsLogoutRegisterScreen.h"

using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eShowTransactionsMenue = 1, eManageClients = 2
        , eManageUsers = 3, eLoginRegister = 4, eLogoutRegister = 5, eExit = 6
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowTransactionsMenue()
    {
        ////Stub...
        //cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageClientsMenue()
    {
        ////Stub...
        //cout << "\Clientts Menue Will be here...\n";
        clsManageClientsScreen::ShowManageClientsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        ////Stub...
        //cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        ////Stub...
        //cout << "\nLogin Register Screen will be here...\n";
        
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowLogoutRegisterScreen()
    {
        ////Stub...
        //cout << "\nLogout Register Screen will be here...\n";
        clsLogoutRegisterScreen::ShowLogoutRegisterScreen();
    }


    //static void _ShowEndScreen()
    //{
    //    //Stub...
    //    cout << "\nEnd Screen Will be here...\n";
    //}

    static void _Logout()
    {
        CurrentUser.RegisterLogOut();

        CurrentUser = clsUser::Find("", "");

        //then it will go back to main function
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageClients:
            system("cls");
            _ShowManageClientsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLogoutRegister:
            system("cls");
            _ShowLogoutRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Transactions.\n";
        cout << setw(37) << left << "" << "\t[2] Manage Clients.\n";
        cout << setw(37) << left << "" << "\t[3] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[4] Login Register.\n";
        cout << setw(37) << left << "" << "\t[5] Logout Register.\n";
        cout << setw(37) << left << "" << "\t[6] Logout.\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

