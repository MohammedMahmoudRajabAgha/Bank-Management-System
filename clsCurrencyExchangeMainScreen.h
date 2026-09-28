#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

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
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
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
        ////Stub...
        //cout << "\n Find Currency Screen will be here...\n";

        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        ////Stub...
        //cout << "\n Update Rate Screen will be here...\n";

        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        ////Stub...
        //cout << "\n Curency Calculator Screen will be here...\n";

        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
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
        cout << setw(37) << left << "" << "\t\t\033[35m  Currency Exchange Menue\033[0m\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\033[36m[1] List Currencies.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[2] Find Currency.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[3] Update Rate.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[36m[4] Currency Calculator.\033[0m\n";
        cout << setw(37) << left << "" << "\t\033[31m[5] Main Menue.\033[0m\n";
        cout << setw(37) << left << "" << "============================================\n";

        _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions(_ReadCurrencyMenueOption()));
    }
};

