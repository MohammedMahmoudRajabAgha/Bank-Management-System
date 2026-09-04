#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsMessageBoxScreen.h"

using namespace std;

class clsClearMessageBoxScreen :protected clsScreen
{
private:






public:
	static void ShowClearMessagBoxScreen()
	{
		_DrawScreenHeader("\t Clear Message Box Screen");

		clsMessageBoxScreen::ShowMessageBoxScreen();

		cout << "\n\nAre You sure you want to Delete Message Box ? [ y/n ] ? ";
		char Answer;
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (CurrentUser.ClearMessageBox())
			{
				cout << "\n Message Box Deleted Successfully :-)";
			}

			else
			{
				cout << "\n Message Box Deleted Faild :-(";

			}
		}


	}


};

