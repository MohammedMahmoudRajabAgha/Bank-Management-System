#pragma once
#include<iostream>
#include <string>

using namespace std;

class InterfaceCommunication
{
public:

	virtual bool SendEmail( string Body) = 0;
	virtual bool SendFax( string Body) = 0;
	virtual bool SendSMS( string Body) = 0;

};

