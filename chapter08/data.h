#ifndef _DATA_H_
#define _DATA_H_H

#include "mainproduct.h"

class DataAccess 
{
private:
    static std::string db;
public:
    static CIUser* CreateUser()
    {
        CIUser* ret = nullptr;
        if(db == "Sqlserver")
            ret = new SqlServerUser();
        else
            ret = new AccessUser();
        return ret;
    }
    static CIDepartment* CreateDepartment()
    {
        CIDepartment* ret = nullptr;
        if(db == "Sqlserver")
            ret = new SqlServerDepartment();
        else
            ret = new AccessDepartment();
        return ret;
    }
};

std::string DataAccess::db = "Sqlserver"; // 类内静态成员定义

#endif