#pragma once
#include<iostream>
#include"clsMainScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsWithdrawScreen :protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		string _AccountNumber;

		cout << "\n Plesea enter Account Number : ";
		_AccountNumber = clsInputValidate::ReadString();

		return _AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t     Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] does not exist.";

			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		double Amount;
		cout << "\nPlease enter Withdraw amount ? ";
		Amount = clsInputValidate::ReadDblNumberBetween(0, DBL_MAX);

		//Validate That the amount does not esceeds the balance
		while (Amount > Client1.AccountBalance)
		{
			cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client1.AccountBalance;

			cout << "\nPlease enter Withdraw amount ? ";
			cin >> Amount;
		}

		cout << "\nAre you sure you want to perform this transactions [y/n] ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Client1.Withdraw(Amount))
			{
				cout << "\n\nAmount Withdraw Successfully :-)\n";
				cout << "\nNew Balance Is : " << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is : " << Amount;
				cout << "\n Your Balance is : " << Client1.AccountBalance;
			}

		}
		else
		{
			cout << "\nOperation was Cancelled :-(\n";
		}
	}



};

