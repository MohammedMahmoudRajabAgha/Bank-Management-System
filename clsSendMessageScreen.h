#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"Global.h"

using namespace std;

class clsSendMessageScreen :protected clsScreen
{
private:

	static void _PrintUserCard(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\n___________________\n";

	}

public:

	static void ShowSendMessageScreen()
	{
		_DrawScreenHeader("\t Send Message Screen");

		cout << "\nPlease Enter User Name ? ";
		string DestinationUserName = clsInputValidate::ReadString();
	
		clsUser DestinationUser = clsUser::Find(DestinationUserName);

		while (DestinationUser.IsEmpty())
		{
			cout << "\nThis User is NOT Found, Please Enter another one ? ";
			string DestinationUserName = clsInputValidate::ReadString();

			 DestinationUser = clsUser::Find(DestinationUserName);


		}

		cout << "\nEnter The Message : ";
		string Message = clsInputValidate::ReadString();

		if (CurrentUser.SendMessage(DestinationUser, Message))
		{
			cout << "\n Message Sent Successfuly To : ";
			cout << "\n__________________________________________\n";
			
			_PrintUserCard(DestinationUser);
			
		}
		else
		{
			cout << "\n Message Sent Faild To " << DestinationUser.UserName << ":-(\n";

		}


	}


};

