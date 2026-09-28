#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsQuickWithdrawScreen.h"
#include"clsNormalWithdrawScreen.h"
#include"clsATMDepositScreen.h"
#include"clsCheckBalanceScreen.h"

using namespace std;

class clsATMMainScreen :protected clsScreen
{
private:

    enum enATMMainMenueOptions
    {
        eQuickWithdraw = 1, eNormalWithdraw = 2,
        eDeposit = 3, eCheckBalance = 4, eExit = 5
    };

	static short _ReadATMMainMenueOption()
	{
		short Choice = 0;

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
		
		return Choice;

	}

	static void _ShowQuickWithdrawScreen()
	{
		////Stub
		//cout << "\nQuick Withdraw Screen will be here...\n";

		clsQuickWithdrawScreen::ShowQuickWithdrawScreen();
	}

	static void _ShowNormalWithdrawScreen()
	{
		////Stub
		//cout << "\nNormal Withdraw Screen will be here...\n";
	
		clsNormalWithdrawScreen::ShowNormalWithdrawScreen();
	}

	static void _ShowDepositScreen()
	{
		////Stub
		//cout << "\nDeposit Screen will be here...\n";

		clsATMDepositScreen::ShowATMDepositScreen();
	}

	static void _ShowCheckBalanceScreen()
	{
		////Stub...
		//cout << "\nCheck Balance Screen will be here...\n";

		clsCheckBalanceScreen::ShowCheckBalanceScreen();
	}

	static void _Logout()
	{
		CurrentClient = clsBankClient::Find("", "");

		//then it will go back to main function
	}

	static void _GoBackToATMMainMenue()
	{
		cout << "\n\nPress Anykey To go back To Main Menue...";
		system("pause>0");
		ShowATMMainMenue();
	}

	static void _PerformATMMainMenueOption(enATMMainMenueOptions ATMMainMenueOption)
	{
		switch (ATMMainMenueOption)
		{
		case enATMMainMenueOptions::eQuickWithdraw:
		{
			system("cls");
			_ShowQuickWithdrawScreen();
			_GoBackToATMMainMenue();
			break;

		}

		case enATMMainMenueOptions::eNormalWithdraw:
		{
			system("cls");
			_ShowNormalWithdrawScreen();
			_GoBackToATMMainMenue();
			break;
		}

		case enATMMainMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToATMMainMenue();
			break;
		}

		case enATMMainMenueOptions::eCheckBalance:
		{
			system("cls");
			_ShowCheckBalanceScreen();
			_GoBackToATMMainMenue();
			break;
		}

		case enATMMainMenueOptions::eExit:
		{
			system("cls");
			_Logout();

			break;
		}

		}
	}

public:
	static void ShowATMMainMenue()
	{
        system("cls");
        _DrawATMScreenHeader("\tATM Main Menue Screen");
	
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\t    ATM Main Menue\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\033[36m[1] Quick Withdraw.\033[0m\n";
		cout << setw(37) << left << "" << "\t\033[36m[2] Normal Withdraw.\033[0m\n";
		cout << setw(37) << left << "" << "\t\033[36m[3] Deposit.\033[0m\n";
		cout << setw(37) << left << "" << "\t\033[36m[4] Check Balance.\033[0m\n";
		cout << setw(37) << left << "" << "\t\033[31m[5] Logout.\033[0m\n";
		cout << setw(37) << left << "" << "==============================================\n";

		_PerformATMMainMenueOption((enATMMainMenueOptions)_ReadATMMainMenueOption());
	}
};

