#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsBankLoginScreen.h"
#include"clsATMLoginScreen.h"
#include"Global.h"

using namespace std;

class clsBankSystemScreen :protected clsScreen
{
private:

	enum enBankSystemOptions { eBankSystem = 1, eATM = 2 };

	static short _ReadBankSystemOption()
	{
		short Choice;
		cout << setw(37) << left << ""
			<< "Choose what do you want to do ? [1 To 2] ? ";
		Choice = clsInputValidate::ReadNumberBetween<short>(1, 2, "Enter Number between 1 to 2? ");

		return Choice;
	}

	static void _ShowBankSystemLoginScreen()
	{
		////Stub...
		//cout << "\n Bank System Login Screen will be here..\n";
		//system("pause>0");

		clsBankLoginScreen::ShowBankLoginScreen();
	}

	static void _ShowATMLoginScren()
	{
		////Stub...
		//cout << "\n ATM Login Screen will be here..\n";
		//system("pause>0");
		
		clsATMLoginScreen::ShowATMLoginScreen();
	}


	static void _PerformBankSystemOptions(enBankSystemOptions BankSystemOption)
	{
		switch (BankSystemOption)
		{
		case enBankSystemOptions::eBankSystem:
		{
			system("cls");
			_ShowBankSystemLoginScreen();

			break;
		}

		case enBankSystemOptions::eATM:
		{
			system("cls");
			_ShowATMLoginScren();

			break;
		}

		}
	}

public:

	static void ShowBankSystemScreen()
	{
		system("cls");

		_DrawMainScreenHeader("\tBank System Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Bank System.\n";
		cout << setw(37) << left << "" << "\t[2] ATM.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformBankSystemOptions(enBankSystemOptions(_ReadBankSystemOption()));
	}


};

