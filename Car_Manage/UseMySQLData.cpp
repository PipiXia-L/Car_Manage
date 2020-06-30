#include "stdafx.h"
#include "UseMySQLData.h"


CUseMySQLData::CUseMySQLData(void)
{
	bConnectFlag = FALSE;
	mysql_init(&m_sqlCon);
}


CUseMySQLData::~CUseMySQLData(void)
{
}

BOOL CUseMySQLData::ConnectMySQL()
{
	if(0 != mysql_options(&m_sqlCon, MYSQL_SET_CHARSET_NAME, _T("gb2312"))) 
	{ 
		return FALSE;
	} 

	if(NULL == mysql_real_connect(&m_sqlCon, _T("localhost"), _T("root"), _T("123456"), _T("car_repair_msg"), 3306, NULL, 0))    
	{    
		return FALSE;
	}  
	bConnectFlag = TRUE;

	return TRUE;  
}

BOOL CUseMySQLData::DisConnectMySQL()
{
	mysql_close(&m_sqlCon); 
	mysql_server_end(); 
	return TRUE;
}

int CUseMySQLData::CheckPassword(string strUserName, string strPassword)
{
	CString strSql;
	strSql.Format(_T("select * from user_form where username = \'%s\'"), strUserName.c_str()); 
	MYSQL_RES *resUserName = NULL; 
	if(0 == mysql_query(&m_sqlCon, strSql)) 
	{ 
		resUserName = mysql_store_result(&m_sqlCon); 

		unsigned __int64 rowcount = mysql_num_rows(resUserName); 
		if (rowcount == 0)
		{
			return 1; 
		}	
	}
	mysql_free_result(resUserName); 

	strSql.Format(_T("select * from user_form where username = \'%s\' and password = \'%s\'"), strUserName.c_str(), strPassword.c_str()); 
	MYSQL_RES *resPassword = NULL; 
	if(0 == mysql_query(&m_sqlCon, strSql)) 
	{ 
		resPassword = mysql_store_result(&m_sqlCon); 

		unsigned __int64 rowcount = mysql_num_rows(resPassword); 
		if (rowcount == 0)
		{
			return 2; 
		}	
	}
	mysql_free_result(resPassword); 

	return 0;
}

BOOL CUseMySQLData::GetServeFormData(vector<server_form> &vServer_Form)
{
	CString strSql; 

	strSql = _T("select * from server_form"); 
	MYSQL_RES *result = NULL; 
	if(0 == mysql_query(&m_sqlCon, strSql)) 
	{ 
		result = mysql_store_result(&m_sqlCon); 

		unsigned __int64 rowcount = mysql_num_rows(result); 
		unsigned int fieldcount = mysql_num_fields(result); 

		MYSQL_ROW row = NULL; 
		row = mysql_fetch_row(result); 
		while(NULL != row) 
		{ 
			server_form server_form_data;
			for(unsigned int i=0; i<fieldcount; i++)
			{ 
				string strTemp = mysql_fetch_field_direct(result, i)->name;
				if (strTemp == _T("id"))
				{
					server_form_data.nCarId = atoi(row[i]);
				}
				else if (strTemp == _T("car_num"))
				{
					server_form_data.strCar_Num = row[i];
				}
				else if (strTemp == _T("contact"))
				{
					server_form_data.strContact = row[i];
				}
				else if (strTemp == _T("contact_way"))
				{
					server_form_data.strContact_Way = row[i];
				}
				else if (strTemp == _T("serve_list"))
				{
					server_form_data.strServe_List = row[i];
				}
				else if (strTemp == _T("other"))
				{
					server_form_data.strOther = row[i];
				}
				else if (strTemp == _T("cost"))
				{
					server_form_data.dCost = atof(row[i]);
				}
				else if (strTemp == _T("time"))
				{
					server_form_data.strTime = row[i];
				}
			} 
			vServer_Form.push_back(server_form_data);
			row = mysql_fetch_row(result); 
		} 
	}
	mysql_free_result(result); 
	return TRUE;
}

BOOL CUseMySQLData::InsertServeDataToMySQL(vector<server_form> vServer_Form)
{
	for (unsigned int i=0; i<vServer_Form.size(); i++)
	{
		CString strSql;

		strSql.Format(_T("insert into server_form(id, car_num, contact, contact_way, serve_list, other, cost, time) values (%d, \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', %.2f, \'%s\')"),
				 vServer_Form[i].nCarId, vServer_Form[i].strCar_Num.c_str(), vServer_Form[i].strContact.c_str(), vServer_Form[i].strContact_Way.c_str(),
				 vServer_Form[i].strServe_List.c_str(), vServer_Form[i].strOther.c_str(), vServer_Form[i].dCost, vServer_Form[i].strTime.c_str());

		if(0 != mysql_query(&m_sqlCon, strSql))
		{ 
			CString strTips;
			strTips.Format(_T("第%d条数据插入失败!"), i+1);
			AfxMessageBox(strTips);
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CUseMySQLData::ChangeServeDataToMySQL(vector<server_form> vServer_Form)
{
	for (unsigned int i=0; i<vServer_Form.size(); i++)
	{
		CString strSql;

		strSql.Format(_T("update server_form set car_num = \'%s\',contact = \'%s\',contact_way = \'%s\',serve_list = \'%s\',other = \'%s\',cost = %.2f,time = \'%s\' where id = %d"),
			vServer_Form[i].strCar_Num.c_str(), vServer_Form[i].strContact.c_str(), vServer_Form[i].strContact_Way.c_str(),
			vServer_Form[i].strServe_List.c_str(), vServer_Form[i].strOther.c_str(), vServer_Form[i].dCost, vServer_Form[i].strTime.c_str(), vServer_Form[i].nCarId);

		if(0 != mysql_query(&m_sqlCon, strSql))
		{ 
			CString strTips;
			strTips.Format(_T("第%d条数据修改失败!"), i+1);
			AfxMessageBox(strTips);
			return FALSE;
		}
	}
	return TRUE;
}

BOOL CUseMySQLData::DeleteServeDataFromMySQL(string strCarId)
{
	CString strSql;

	strSql.Format(_T("delete from server_form where id = %d"), atoi(strCarId.c_str()));

	if(0 != mysql_query(&m_sqlCon, strSql))
	{ 
		CString strTips;
		strTips.Format(_T("数据删除失败!"));
		AfxMessageBox(strTips);
		return FALSE;
	}
	return TRUE;
}

BOOL CUseMySQLData::SearchServeDataFromMySQL(string strSearchKey, string strSearchValue, vector<server_form> &vServer_Form)
{
	CString strSql; 

	strSql.Format(_T("select * from server_form where %s = \'%s\'"), strSearchKey.c_str(), strSearchValue.c_str()); 
	MYSQL_RES *result = NULL; 
	if(0 == mysql_query(&m_sqlCon, strSql)) 
	{ 
		result = mysql_store_result(&m_sqlCon); 

		unsigned __int64 rowcount = mysql_num_rows(result); 
		unsigned int fieldcount = mysql_num_fields(result); 

		MYSQL_ROW row = NULL; 
		row = mysql_fetch_row(result); 
		while(NULL != row) 
		{ 
			server_form server_form_data;
			for(unsigned int i=0; i<fieldcount; i++)
			{ 
				string strTemp = mysql_fetch_field_direct(result, i)->name;
				if (strTemp == _T("id"))
				{
					server_form_data.nCarId = atoi(row[i]);
				}
				else if (strTemp == _T("car_num"))
				{
					server_form_data.strCar_Num = row[i];
				}
				else if (strTemp == _T("contact"))
				{
					server_form_data.strContact = row[i];
				}
				else if (strTemp == _T("contact_way"))
				{
					server_form_data.strContact_Way = row[i];
				}
				else if (strTemp == _T("serve_list"))
				{
					server_form_data.strServe_List = row[i];
				}
				else if (strTemp == _T("other"))
				{
					server_form_data.strOther = row[i];
				}
				else if (strTemp == _T("cost"))
				{
					server_form_data.dCost = atof(row[i]);
				}
				else if (strTemp == _T("time"))
				{
					server_form_data.strTime = row[i];
				}
			} 
			vServer_Form.push_back(server_form_data);
			row = mysql_fetch_row(result); 
		} 
	}
	mysql_free_result(result); 
	return TRUE;
}
