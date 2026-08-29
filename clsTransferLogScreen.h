#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>

using namespace std;

class clsTransferLogScreen :protected clsScreen
{
private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << TransferLogRecord.Amount;
		cout << "| " << setw(10) << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(10) << TransferLogRecord.destBalanceAfter;
		cout << "| " << setw(8) << TransferLogRecord.UserName;
	}

public:
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord>vTransferLog = clsBankClient::GetTransferLogList();
		
		string Title = "Transfer Log List Screen";
		string subtitle = "\t(" + to_string(vTransferLog.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(Title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(23) << "Date/Time";
		cout << "| " << setw(8) << "s.Acct";
		cout << "| " << setw(8) << "d.Acct";
		cout << "| " << setw(8) << "Amount";
		cout << "| " << setw(10) << "s.Balance";
		cout << "| " << setw(10) << "d.Balance";
		cout << "| " << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vTransferLog.size() == 0)
			cout << "\t\t\t\tNo Transfer Available In the System!";

		else
		{
			for (clsBankClient::stTransferLogRecord TransferLogRecord : vTransferLog)
			{
				_PrintTransferLogRecordLine(TransferLogRecord);
				cout << "\n";
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}


};

