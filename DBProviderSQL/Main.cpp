#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>



using namespace std;

class SQLBDConnection
{
    enum {
        SQL_RESULT_LEN = 240,
        SQL_RETURN_CODE_LEN = 1000
    };
    //define handles and variables
    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLHANDLE sqlEnvHandle;
    SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
    //initializations
    SQLBDConnection() : sqlConnHandle(0), sqlStmtHandle(0) {};
    ~SQLBDConnection() { Completed(); }
    void CheckResult(int result);
    //allocations
    void Allocations()
    {
        int result = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle);
        CheckResult(result);
        result = SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
        CheckResult(result);
        result = SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle);
        CheckResult(result);
        //output
        cout << "Attempting connection to SQL Server...";
        cout << "\n";
    }
    //connect to SQL Server  
    //I am using a trusted connection and port 14808
    //it does not matter if you are using default or named instance
    //just make sure you define the server name and the port
    //You have the option to use a username/password instead of a trusted     connection
    //but is more secure to use a trusted connection
    void connectToSQLServer()
    {
        int result = SQLDriverConnectW(sqlConnHandle, NULL,
            (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=DataBaseName;UID=DataBaseUserName;PWD=PassWord;",
            //(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;Trusted=true;",
            SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT);

        CheckResult(result);

        //if there is a problem connecting then exit application
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
        {
            Completed();
        }
        //output
        cout << "\n";
        cout << "Executing T-SQL query...";
        cout << "\n";
        //if there is a problem executing the query then exit application
        //else display query result
        if (SQL_SUCCESS != SQLExecDirectW(sqlStmtHandle, (SQLWCHAR*)L"SELECT @@VERSION", SQL_NTS)) 
        {
            cout << "Error querying SQL Server";
            cout << "\n";
            Completed();
        }
        else 
        {
            //declare output variable and pointer
            SQLCHAR sqlVersion[SQL_RESULT_LEN];
            SQLINTEGER ptrSqlVersion;
            while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) 
            {
                SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
                //display query result
                cout << "\nQuery Result:\n\n";
                cout << sqlVersion << endl;
            }
        }
    }
   
    void CheckResult(int result)
    {
        switch (result)
        {
        case SQL_SUCCESS:
            cout << "Successfully connected to SQL Server";
            cout << "\n";
            break;
        case SQL_SUCCESS_WITH_INFO:
            cout << "Successfully connected to SQL Server";
            cout << "\n";
            break;
        case SQL_INVALID_HANDLE:
            cout << "Could not connect to SQL Server";
            cout << "\n";
            Completed();
        case SQL_ERROR:
            cout << "Could not connect to SQL Server";
            cout << "\n";
            Completed();
        default:
            break;
        }
    }
    //close connection and free resources
    void Completed()
    {
        SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
        SQLDisconnect(sqlConnHandle);
        SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
        SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
        //pause the console window - exit when key is pressed
        cout << "\nPress any key to exit...";
        getchar();
    }
};

