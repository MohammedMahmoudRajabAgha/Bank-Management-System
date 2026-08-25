#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
using namespace std;

class clsLoginRegisterScreen :protected clsScreen
{
private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << "\t| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}

public:
	static void ShowLoginRegisterScreen()
	{

		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);
	
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\n\t| " << setw(35) << left << "Date/Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(10) << left << "Permissions";
		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else
		{
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

