#pragma once
#include<iostream>
#include"clsScreen.h"

#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManageUsersScreen:protected clsScreen
{
	enum enManageUsersMenueOptios {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		short Choice;
		cout << setw(37) << left << "" 
			<< "Choose what do you want to do ? [1 To 6] ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");

		return Choice;
	}

	void static _ShowListUsersScrenn()
	{
		/*cout << "\nList Users Screen will be here.\n";*/
		clsListUsersScreen::ShowUsersList();
	}

	void static _ShowAddNewUserScreen()
	{
		/*cout << "\nAdd New User Screen will be here.\n";*/
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	void static _ShowDeleteUserScreen()
	{
		/*cout << "\nDelete User Screen will be here.\n";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	void static _ShowUpdateUserScreen()
	{
		/*cout << "\nUpdate User Screen will be here.\n";*/
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	void static _ShowFindUserScreen()
	{
		/*cout << "\nFind User Screen will be here.\n";*/
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();

	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOptios ManageUserOption)
	{
		switch (ManageUserOption)
		{
		case enManageUsersMenueOptios::eListUsers:
		{
			system("cls");
			_ShowListUsersScrenn();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptios::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptios::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptios::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptios::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enManageUsersMenueOptios::eMainMenue:
		{

		}

		}
	}

public:

	static void ShowManageUsersMenue()
	{
		system("cls");

		if (!clsScreen::CeckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\t   Manage Users Screnn");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t   Manage Users Menue\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptios)_ReadManageUsersMenueOption());
		
	}

};

