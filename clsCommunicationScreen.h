#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include <iomanip>

class clsCommunicationScreen :protected clsScreen
{
	enum enCommunuicationOptions
	{
		eMessageBox = 1, eSendMessage = 2, eClearMessageBox = 3 ,
		eMainMenue = 4
	};

	static short _ReadCommunicationMenueOption()
	{
		short Choice;
		cout << setw(37) << left << ""
			<< "Choose what do you want to do ? [1 To 4] ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");

		return Choice;
	}

	static void _ShowMessageBoxScreen()
	{
		//Stub...
		cout << "\nMessage Box Screen will be here...\n";
	}
	
	static void _ShowSendMessageScreen()
	{
		//Stub...
		cout << "\nSend Message Screen will be here...\n";
	}

	static void _ShowClearMessageScreen()
	{
		//Stub...
		cout << "\nClear Message Screen will be here...\n";
	}

	static void _GoBackToCommunicationMenue()
	{
		cout << "\n\nPress any key to go back to Communication Menue...";
		system("pause>0");
		ShowCommunicationMenue();
	}

	static void _PerformCommunicationMenueOption(enCommunuicationOptions CommunicationOption)
	{
		switch (CommunicationOption)
		{
		case enCommunuicationOptions::eMessageBox:
		{
			system("cls");
			_ShowMessageBoxScreen();
			_GoBackToCommunicationMenue();
			break;
		}

		case enCommunuicationOptions::eSendMessage:
		{
			system("cls");
			_ShowSendMessageScreen();
			_GoBackToCommunicationMenue();
			break;
		}

		case enCommunuicationOptions::eClearMessageBox:
		{
			system("cls");
			_ShowClearMessageScreen();
			_GoBackToCommunicationMenue();
			break;
		}

		case enCommunuicationOptions::eMainMenue:
		{

		}

		}
	}

public:

	static void ShowCommunicationMenue()
	{
		system("cls");

	

		_DrawScreenHeader("\t   Communication Screnn");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t   Communicaion Menue\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Message Box.\n";
		cout << setw(37) << left << "" << "\t[2] Send Message.\n";
		cout << setw(37) << left << "" << "\t[3] Clear Message Box\n";
		cout << setw(37) << left << "" << "\t[4] Manage Users.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformCommunicationMenueOption((enCommunuicationOptions)_ReadCommunicationMenueOption());

	}

};

