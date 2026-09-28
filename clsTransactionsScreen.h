#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5
        , eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        /*cout << "\n Deposit Screen will be here.\n";*/
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        ////Stub...
        //cout << "\nTransfer Screen will be here...\n";

        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        ////stub...
        //cout << "\nTransfer Log Screen will be here...\n";
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }


public:
    

    static void ShowTransactionsMenue()
    {
        system("cls");

        if (!clsScreen::CeckAccessRights(clsUser::enPermissions::pTransactions))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t\033[35m  Transactions Menue\033[0m\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\033[36m[1] Deposit.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[2] Withdraw.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[3] Total Balances.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[4] Transfer.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[5] Transfer Log.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[31m[6] Main Menue.\033[0m\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};

