#pragma once]
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"

using namespace std;

class clsQuickWithdrawScreen :protected clsScreen
{
private:

	static short _ReadQuickWithdrawOption()
	{
		short Choice = 0;

		cout << "Choose what do you want to do? [1 to 9]? ";
		Choice = clsInputValidate::ReadNumberBetween<short>(1, 9, "Enter Number between 1 to 9? ");

		return Choice;
	}

	static short _GetQuickWithdrawAmount(short QuickWithdrawOption)
	{
		short arrQuickWithdarwAmount[] = { 20,50,100,200,400,600,800,1000 };

		return arrQuickWithdarwAmount[QuickWithdrawOption - 1];
	}

	static void _PerformQuickWithdrawOption(short QuickWithdrawOption)
	{
		if (QuickWithdrawOption == 9)//Exit
		{
			return;
		}

		short WithdrawBalance = _GetQuickWithdrawAmount(QuickWithdrawOption);

		if (WithdrawBalance > CurrentClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the balance, make another choice.\n";
			cout << "Press Anykey To Continue...";
			system("pause>0");
			ShowQuickWithdrawScreen();
			return;
		}

		cout << "\nAre you sure you want to perform this transactions [y/n] ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (CurrentClient.Withdraw(WithdrawBalance))
			{
				cout << "\n\nAmount Withdraw Successfully :-)\n";
				cout << "\nNew Balance Is : " << CurrentClient.AccountBalance;
			}
			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is : " << WithdrawBalance;
				cout << "\n Your Balance is : " << CurrentClient.AccountBalance;
			}

		}
		else
		{
			cout << "\nOperation was Cancelled :-(\n";
		}

	}


public:
	static void ShowQuickWithdrawScreen()
	{
		system("cls");
		_DrawATMScreenHeader("\t\tQuick Withdraw Screen");

		cout << "==============================================\n";
		cout << "\t\tQuick Withdraw Menue\n";
		cout << "==============================================\n";
		cout << "\t[1] 20  \t[2] 50\n";
		cout << "\t[3] 100 \t[4] 200\n";
		cout << "\t[5] 400 \t[6] 600\n";
		cout << "\t[7] 800 \t[8] 1000\n";
		cout << "\t[9] Exit\n";
		cout << "==============================================\n";
		cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";

		_PerformQuickWithdrawOption(_ReadQuickWithdrawOption());
	}


};

