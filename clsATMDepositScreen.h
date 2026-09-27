#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"Global.h"

using namespace std;

class clsATMDepositScreen :protected clsScreen
{
private:

	static double ReadDepositAmount()
	{
		double Amount = 0;

		cout << "\nEnter a Positive Deposit Amount ? ";
		Amount = clsInputValidate::ReadNumberBetween<double>(0, DBL_MAX, "Enter Number between 1 to 5? ");

		return Amount;
	}

	static void _PerformDepositOption()
	{
		double DepositBalance = ReadDepositAmount();

		cout << "\nAre you sure you want to perform this transactions [y/n] ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (CurrentClient.Deposit(DepositBalance))
			{
				cout << "\n\nAmount Deposit Successfully :-)\n";
				cout << "\nNew Balance Is : " << CurrentClient.AccountBalance;
			}

			else
			{
				cout << "\nOperation is not possible :-(\n";
			}
		}
		else
		{
			cout << "\nOperation was Cancelled :-(\n";
		}

	}


public:
	static void ShowATMDepositScreen()
	{
		system("cls");
		_DrawATMScreenHeader("\t\tDeposit Screen\n");
		cout << setw(37) << left << "" << "==============================================\n";;
		_PerformDepositOption();

	}

};

