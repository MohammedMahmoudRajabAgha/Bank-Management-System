#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
using namespace std;

class clsLogoutRegisterScreen :protected clsScreen
{
private:

	static void _PrintLogoutRegisterRecordLine(clsUser::stLogoutRegisterRecord LogoutRegisterRecord)
	{
		cout << "\t| " << setw(35) << left << LogoutRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LogoutRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LogoutRegisterRecord.Password;
		cout << "| " << setw(10) << left << LogoutRegisterRecord.Permissions;
	}

public:
	static void ShowLogoutRegisterScreen()
	{
		if (!clsScreen::CeckAccessRights(clsUser::enPermissions::pShowLogoutRegister))
		{
			return;
		}

		vector<clsUser::stLogoutRegisterRecord> vLogoutRegisterRecord = clsUser::GetLogoutRegisterList();

		string Title = "\tLogout Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLogoutRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\n\t| " << setw(35) << left << "Date/Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLogoutRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logouts Available In the System!";
		else
		{
			for (clsUser::stLogoutRegisterRecord Record : vLogoutRegisterRecord)
			{
				_PrintLogoutRegisterRecordLine(Record);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

