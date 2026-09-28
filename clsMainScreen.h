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
#include"clsCurrencyExchangeMainScreen.h"

using namespace std;

class clsMainScreen :protected clsScreen
{

private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        ////Stub...
        //cout << "\nClient List Screen Will be here...\n";

        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        ////Stub...
        //cout << "\nAdd New Client Screen Will be here...\n";

        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        ////Stub...
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        ////Stub...
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        ////Stub...
        //cout << "\nFind Client Screen Will be here...\n";

        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        ////Stub...
        //cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();

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
     
    static void _ShowCurrencyExchangeMainScreen()
    {
        ////Stub...
        //cout << "\n Currency Main Menue will be here...\n";
    
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

    //static void _ShowEndScreen()
    //{
    //    //Stub...
    //    cout << "\nEnd Screen Will be here...\n";
    //}

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");

        //then it will go back to main function
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
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

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
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
        cout << setw(37) << left << "" << "\t\t\t\033[35mMain Menue\033[0m\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\033[36m[1] Show Client List.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[2] Add New Client.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[3] Delete Client.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[4] Update Client Info.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[5] Find Client.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[6] Transactions.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[7] Manage Users.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[8] Login Register.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[9] Currency Exchange.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[31m[10] Logout.\033[0m\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

