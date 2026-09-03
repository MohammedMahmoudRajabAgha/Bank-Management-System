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

using namespace std;

class clsManageClientsScreen :protected clsScreen
{


private:
    enum enManageClientsMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eMainMenue = 6
    };

    static short _ReadManageClientsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToManageClientsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowManageClientsMenue();
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


    static void _PerfromManageClientsMenueOption(enManageClientsMenueOptions ManageClientsMenueOption)
    {
        switch (ManageClientsMenueOption)
        {
        case enManageClientsMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToManageClientsMenue();
            break;
        }
        case enManageClientsMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToManageClientsMenue();
            break;

        case enManageClientsMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToManageClientsMenue();
            break;

        case enManageClientsMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToManageClientsMenue();
            break;

        case enManageClientsMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToManageClientsMenue();
            break;

        case enManageClientsMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }  
        }

    }



public:


    static void ShowManageClientsMenue()
    {

        if (!clsScreen::CeckAccessRights(clsUser::enPermissions::pManageClients))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t\tManage Clients Screen");

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t\Manage Clients Menue\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerfromManageClientsMenueOption((enManageClientsMenueOptions)_ReadManageClientsMenueOption());
    }

};

