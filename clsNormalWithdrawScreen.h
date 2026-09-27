#pragma once
#include<iostream>
#include"clsScreen.h"

using namespace std;

class clsNormalWithdrawScreen :protected clsScreen
{
private:
	static int _ReadNormalWithdrawAmount()
	{
		int Amount = 0;
		
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\tAccount Balance Is : " << CurrentClient.GetAccountBalance() << endl;

		do
		{
			cout << "\nEnter an amount multiple of 5's ? ";
			Amount = clsInputValidate::ReadNumber<int>();

		} while (Amount % 5 != 0);


		return Amount;
	}

	static void _PerformNormalWithdrawOption()
	{
		int WithdrawBalance = _ReadNormalWithdrawAmount();

		if (WithdrawBalance > CurrentClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the balance, make another choice.\n";
			cout << "Press Anykey To Continue...";
			system("pause>0");
			ShowNormalWithdrawScreen();
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

	static void ShowNormalWithdrawScreen()
	{
		system("cls");
		_DrawATMScreenHeader("\tNormal Withdraw Screen");
		
		_PerformNormalWithdrawOption();
	}


};

