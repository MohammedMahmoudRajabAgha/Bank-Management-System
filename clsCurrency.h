#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"

using namespace std;

class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector<string> vCurrencyData = clsString::Split(Line, Separator);

		return clsCurrency(enMode::UpdateMode,vCurrencyData[0], vCurrencyData[1],
			vCurrencyData[2], stof(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Curency, string Separator = "#//#")
	{
		string stCurrencyRecord = "";

		stCurrencyRecord += Curency.Country() + Separator;
		stCurrencyRecord += Curency.CurrencyCode() + Separator;
		stCurrencyRecord += Curency.CurrencyName() + Separator;
		stCurrencyRecord += to_string(Curency.Rate());

		return stCurrencyRecord;
	}

	static vector<clsCurrency>_LoadCurrencysDataFromFile()
	{
		vector<clsCurrency>vCurrencys;

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrencys;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencies)
	{
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);//overwrite

		if (MyFile.is_open())
		{
			string DataLine = "";

			for (clsCurrency Currency : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(Currency);

				MyFile << DataLine << endl;
			}
		
			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsCurrency> _vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency & Currency : _vCurrencys)
		{
			if (Currency.CurrencyCode() == CurrencyCode())
			{
				Currency = *this;

				break;

			}
		}

		_SaveCurrencyDataToFile(_vCurrencys);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	vector<clsCurrency>GetAllUSDRates()
	{
		return _LoadCurrencysDataFromFile();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;

		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode


		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();

					return Currency;
				}
			}
		
			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode


		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();

					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return (!Currency.IsEmpty());
	}

	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurrencysDataFromFile();
	}

};

