#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>

using namespace std;

class clsCheckBalanceScreen:protected clsScreen
{
private:



public:

	static void ShowCheckBalanceScreen()
	{
		system("cls");
		_DrawATMScreenHeader("\t\tCheck Balance Screen\n");
		cout << setw(37) << left << "" << "==============================================\n";;
		cout << setw(37) << left << "" 
			 << "\tYour Balance is : " << CurrentClient.AccountBalance << "\n";
	}

};

