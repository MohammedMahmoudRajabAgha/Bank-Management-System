#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsTransferScreen :protected clsScreen
{
private:

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber = "";
		cout << "\n" << Message;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not Found, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0;
		cout << "\nEnter Transfer Amount ? ";
		Amount = clsInputValidate::ReadDblNumberBetween(0, SourceClient.AccountBalance, "Number is not a range, Enter Number between [0," + to_string(SourceClient.AccountBalance) + "] ? ");


		return Amount;

	}

public:

	static void ShowTransferScreen()
	{
		clsScreen::_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer From: "));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer To: "));
		_PrintClient(DestinationClient);

		
		double Amount = _ReadAmount(SourceClient);


		char Answer;
		cout << "\nAre you sure you want to perform this operation ? [y/n] ?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				cout << "\nTransfer Done Successfully\n";	
			}

			else
			{
				cout << "\nTransfer Faild\n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

