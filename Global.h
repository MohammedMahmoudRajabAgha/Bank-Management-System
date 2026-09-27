#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsBankClient.h"

clsBankClient CurrentClient = clsBankClient::Find("", "");
clsUser CurrentUser = clsUser::Find("", "");
