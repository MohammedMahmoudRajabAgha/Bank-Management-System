#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen :protected clsScreen
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

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-) \n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was is NOT Found :-( \n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";;
		short Answer = 1;
		Answer = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
		
		if (Answer == 1)
		{
			cout << "\nPlease Enter CurrencyCode : ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			cout << "\nPlease Enter Country Name : ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}


};

//My Way...

/*

#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{
private:

	enum enFindCurrencyMenueOptions { eCode = 1, eCounrty = 2 };

	static short _ReadFindCurrencyMenueOption()
	{
		cout << "Find By: [1] Code or [2] Country ? ";;
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
		return Choice;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n_________________________\n";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n_________________________\n";
	}

	static void _ShowFindCurrencyByCode()
	{
		////Stub...
		//cout << "\n Find Currency by Code will be here...\n";

		cout << "\nPlease Enter CurrencyCode : ";
		string CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		if (Currency.IsEmpty())
		{
			cout << "\nCurrency is NOT Found :-( \n";
		}
		else
		{
			cout << "\nCurrency Found :-) \n";
		}

		_PrintCurrencyCard(Currency);

	}

	static void _ShowFindCurrencyByCountry()
	{
		////Stub...
		//cout << "\n Find Currency By Country will be here...\n";

		cout << "\nPlease Enter Country Name : ";
		string Country = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(Country);

		if (Currency.IsEmpty())
		{
			cout << "\nCurrency is NOT Found :-( \n";
		}
		else
		{
			cout << "\nCurrency Found :-) \n";
		}

		_PrintCurrencyCard(Currency);
	}

	static void _PerformFindCurrencyMenueOptions(enFindCurrencyMenueOptions FindCurrencyMenueOption)
	{
		switch (FindCurrencyMenueOption)
		{
		case enFindCurrencyMenueOptions::eCode:
		{
			_ShowFindCurrencyByCode();
			break;
		}

		case enFindCurrencyMenueOptions::eCounrty:
		{
			_ShowFindCurrencyByCountry();
			break;
		}

		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		_PerformFindCurrencyMenueOptions(enFindCurrencyMenueOptions(_ReadFindCurrencyMenueOption()));
	}


};

*/