#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>

using namespace std;

class clsTransactionLogScreen :protected clsScreen
{
private:

	static string _GetOpTypeString(clsBankClient::enOpType OpType)
	{
		string OpTypeStringArr[] = { "Deposit","Withdraw" };

		return OpTypeStringArr[OpType];
	}

	static void _PrintTransactionLogRecordLine(clsBankClient::stTransactionLogRecord TransactionLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << TransactionLogRecord.DateTime;
		cout << "| " << setw(10) << TransactionLogRecord.AccountNumber;
		cout << "| " << setw(8) << _GetOpTypeString(TransactionLogRecord.OpType);
		cout << "| " << setw(8) << TransactionLogRecord.Amount;
		cout << "| " << setw(10) << TransactionLogRecord.BalanceAfter;
		cout << "| " << setw(8) << TransactionLogRecord.UserName;
	}

public:
	static void ShowTransactionLogScreen()
	{
		vector<clsBankClient::stTransactionLogRecord>vTransactionLog = clsBankClient::GetTransactionLogList();

		string Title = "Transaction Log List Screen";
		string subtitle = "\t(" + to_string(vTransactionLog.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(Title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(23) << "Date/Time";
		cout << "| " << setw(10) << "Account Number";
		cout << "| " << setw(8) << "Op Type";
		cout << "| " << setw(8) << "Amount";
		cout << "| " << setw(10) << "Account Balance";
		cout << "| " << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vTransactionLog.size() == 0)
			cout << "\t\t\t\tNo Transaction Available In the System!";

		else
		{
			for (clsBankClient::stTransactionLogRecord TransactionLogRecord : vTransactionLog)
			{
				_PrintTransactionLogRecordLine(TransactionLogRecord);
				cout << "\n";
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}


};

