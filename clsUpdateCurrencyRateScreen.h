#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

using namespace std;

class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n_________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_________________________\n";
	}

	static float _ReadRate()
	{
		cout << "\nEnter New Rate : ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n Currency Is NOT Found, Choose another One : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);


		cout << "\nAre you sure you want to update the rate of this Currency ? y/n ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			cout << "\n\nUpdate Currency Rate: ";
			cout << "\n_____________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency);


		}
		

	}

};

