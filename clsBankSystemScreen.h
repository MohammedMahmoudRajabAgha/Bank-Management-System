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
			<< "\033[33mChoose what do you want to do ? [1 To 2] ? \033[0m";
		Choice = clsInputValidate::ReadNumberBetween<short>(1, 2, "\033[31mEnter Number between 1 to 2? \033[0m");

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

		_DrawMainScreenHeader("\t\033[34mBank System Screen\033[0m");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\033[36m[1] Bank System.\033[0m\n";
		cout << setw(37) << left << "" << "\t\033[36m[2] ATM.\033[0m\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformBankSystemOptions(enBankSystemOptions(_ReadBankSystemOption()));
	}


};

