#pragma once

#include "winsock.h"    
#include "mysql.h"  
#include <string>
#include <vector>
using namespace std;

#include "BaseDataStruct.hpp"

class CUseMySQLData
{
public:
	CUseMySQLData(void);
	~CUseMySQLData(void);

	BOOL bConnectFlag;
	MYSQL m_sqlCon;
	BOOL ConnectMySQL();
	BOOL DisConnectMySQL();

	int CheckPassword(string strUserName, string strPassword);  //0����  1�û���������   2�������

	BOOL GetServeFormData(vector<server_form> &vServer_Form);
	BOOL InsertServeDataToMySQL(vector<server_form> vServer_Form);
	BOOL ChangeServeDataToMySQL(vector<server_form> vServer_Form);
	BOOL DeleteServeDataFromMySQL(string strCarId);
	BOOL SearchServeDataFromMySQL(string strSearchKey, string strSearchValue, vector<server_form> &vServer_Form);
};

