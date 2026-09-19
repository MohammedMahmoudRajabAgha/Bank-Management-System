#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen :protected clsScreen
{
private:

    enum enCurrenciesMainMenueOptions
    {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateCurrencyRate = 3, eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short _ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _ShowCurrenciesListScreen()
    {
        ////Stub...
        //cout << "\n List Currencies Screen will be here...\n";

        clsCurrenciesListScreen::ShowCurrencysListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //Stub...
        cout << "\n Find Currency Screen will be here...\n";
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        //Stub...
        cout << "\n Update Rate Screen will be here...\n";
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //Stub...
        cout << "\n Curency Calculator Screen will be here...\n";
    }

    static void _GoBackToCurrencyMenue()
    {
        cout << "\n\nPress any key to go back to Currency Menue...";
        system("pause>0");
        ShowCurrenciesMenue();
    }

    static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrencyMenueOption)
    {
        switch (CurrencyMenueOption)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }

        }
    }

public:

    static void ShowCurrenciesMenue()
    {
        system("cls");

        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions(_ReadCurrencyMenueOption()));
    }
};

