#pragma once
#include<iostream>
#include"clsMainScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsDepositScreen :public clsScreen
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
	
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t     Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] does not exist.";

			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);
		
		//You Can Use...
		// 1) INT_MIN ,INT_MAX
		// 2) FLT_MIN ,FLT_MAX
		// 3) DBL_MIN ,DBL_MAX

		double Amount;
		cout << "\nPlease enter deposit amount ? ";
		Amount = clsInputValidate::ReadDblNumberBetween(1,DBL_MAX);

		cout << "\nAre you sure you want to perform this transactions [y/n] ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			
			Client1.Deposit(Amount);
			
			cout << "\n\nAmount Deposit Successfully :-)\n";
			cout << "\nNew Balance Is : " << Client1.AccountBalance;
			
		}
		else
		{
			cout << "\nOperation was Cancelled :-(\n";
		}
	}



};

