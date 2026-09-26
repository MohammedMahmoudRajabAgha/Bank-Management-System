#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << "\n" << Message << "\n";
		CurrencyCode = clsInputValidate::ReadString();
		
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Is NOT Found, Please Enter another One ? \n";
			CurrencyCode = clsInputValidate::ReadString();

		}
		
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		double Amount = clsInputValidate::ReadDblNumberBetween(0, DBL_MAX);

		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card")
	{
		cout << "\n" << Title << "\n";
		cout << "\n_________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_________________________\n";
	}
	
	static void _PrintCalculationsResults(float Amount,clsCurrency Currency1,clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " " << "USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting From USD to : \n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
	
		cout << "\n" << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << "\n";
	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		
		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("Please Enter Currency1 Code:");
			clsCurrency Currency2 = _GetCurrency("Please Enter Currency2 Code:");

			/*if (Currency1.CurrencyCode() == Currency2.CurrencyCode())
			{
				cout << "\nThe two Currencies are the same. No conversion is needed :-(";

				return;
			}*/

		
			double Amount = _ReadAmount();

		
			_PrintCalculationsResults(Amount,Currency1, Currency2);

			cout << "\n\n\nDo You want To Perform a nother Calculation ? y/n ? ";
			cin >> Continue;

		} 
	}
};


//   My Solution...

//#pragma once
//#include<iostream>
//#include"clsScreen.h"
//#include"clsCurrency.h"
//#include"clsInputValidate.h"
//
//using namespace std;
//
//class clsCurrencyCalculatorScreen :protected clsScreen
//{
//private:
//
//	static clsCurrency _GetCurrency(string Message)
//	{
//		cout << "\n" << Message << "\n";
//		string CurrencyCode = clsInputValidate::ReadString();
//
//		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
//		{
//			cout << "\nCurrency Is NOT Found, Please Enter another One ? \n";
//			CurrencyCode = clsInputValidate::ReadString();
//
//		}
//
//		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
//
//		return Currency;
//	}
//
//	static float _ReadAmount()
//	{
//		cout << "\nEnter Amount to Exchange: ";
//		double Amount = clsInputValidate::ReadDblNumberBetween(0, DBL_MAX);
//
//		return Amount;
//	}
//
//	static void _PrintCurrency(clsCurrency Currency, string Title = "Currency Card")
//	{
//		cout << "\n" << Title;
//		cout << "\n_________________________\n";
//		cout << "\nCountry    : " << Currency.Country();
//		cout << "\nCode       : " << Currency.CurrencyCode();
//		cout << "\nName       : " << Currency.CurrencyName();
//		cout << "\nRate(1$) = : " << Currency.Rate();
//		cout << "\n_________________________\n";
//	}
//
//	static void _PrintExchangeResultLine(clsCurrency Currency1, clsCurrency Currency2, double AmountBeforeExchange, double AmountAfterExchange)
//	{
//		cout << fixed << setprecision(3);
//
//		cout << "\n" << AmountBeforeExchange << " " << Currency1.CurrencyCode()
//			<< " = " << AmountAfterExchange << " " << Currency2.CurrencyCode() << "\n";
//	}
//
//	static void _PerformExchangeFromUSD(clsCurrency Currency1, clsCurrency Currency2, double Amount)
//	{
//		cout << "\nConvert From USD To :\n";
//		_PrintCurrency(Currency2, "To:");
//
//		double AmountAfterExchange = Currency1.ConvertToOtherCurrency(Amount, Currency2);
//
//		_PrintExchangeResultLine(Currency1, Currency2, Amount, AmountAfterExchange);
//	}
//
//	static void _PerformExchangeToUSD(clsCurrency Currency1, clsCurrency Currency2, double Amount)
//	{
//		_PrintCurrency(Currency1, "Convert From:");
//
//		double AmountInUSD = Currency1.ConvertToUSD(Amount);
//
//		_PrintExchangeResultLine(Currency1, Currency2, Amount, AmountInUSD);
//	}
//
//	static void _PrintCalculationsResults(clsCurrency Currency1, clsCurrency Currency2, double Amount)
//	{
//		if (Currency1.CurrencyCode() == "USD")
//		{
//			_PerformExchangeFromUSD(Currency1, Currency2, Amount);
//		}
//
//		else if (Currency2.CurrencyCode() == "USD")
//		{
//			_PerformExchangeToUSD(Currency1, Currency2, Amount);
//		}
//
//		else
//		{
//			_PerformExchangeToUSD(Currency1, clsCurrency::FindByCode("USD"), Amount);
//			_PerformExchangeFromUSD(clsCurrency::FindByCode("USD"), Currency2, Currency1.ConvertToUSD(Amount));
//		}
//	}
//
//
//public:
//
//	static void ShowCurrencyCalculatorScreen()
//	{
//		char Continue = 'y';
//
//		while (Continue == 'y' || Continue == 'Y')
//		{
//			system("cls");
//			_DrawScreenHeader("\tCurrency Calculator Screen");
//
//			clsCurrency Currency1 = _GetCurrency("Please Enter Currency1 Code:");
//			clsCurrency Currency2 = _GetCurrency("Please Enter Currency2 Code:");
//
//			if (Currency1.CurrencyCode() == Currency2.CurrencyCode())
//			{
//				cout << "\nThe two Currencies are the same. No conversion is needed :-(";
//
//				return;
//			}
//
//			
//			double Amount = _ReadAmount();
//
//
//			_PrintCalculationsResults(Currency1, Currency2, Amount);
//
//			cout << "\n\n\nDo You want To Perform a nother Calculation ? y/n ? ";
//			cin >> Continue;
//
//		}
//
//	}
//};