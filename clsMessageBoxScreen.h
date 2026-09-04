#pragma once
#include<iostream>
#include"clsScreen.h"
#include"iomanip"
#include"Global.h"

using namespace std;

class clsMessageBoxScreen:protected clsScreen
{
	static void _PrintMessageRecordLine(clsUser::stMessageRecord MessageRecord)
	{
		cout << "\t| " << setw(23) << left << MessageRecord.DateTime;
		cout << "| " << setw(15) << left << MessageRecord.srcUserName;
		cout << "| " << setw(50) << left << MessageRecord.Message;
	}

public:
	 
	static void ShowMessageBoxScreen()
	{
		vector <clsUser::stMessageRecord> vMessagesRecord = clsUser::GetMessageRecordList(CurrentUser.UserName);

		string Title = "\t  Message Box Screen";
		string SubTitle = "\t    (" + to_string(vMessagesRecord.size()) + ") Message(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\n\t| " << setw(23) << left << "Date/Time";
		cout << "| " << setw(15) << left << "srcUserName";
		cout << "| " << setw(50) << left << "Message";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vMessagesRecord.size() == 0)
			cout << "\t\t\t\tNo Messages Available In the Post Box!";
		else
		{
			for (clsUser::stMessageRecord Record : vMessagesRecord)
			{
				_PrintMessageRecordLine(Record);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};


