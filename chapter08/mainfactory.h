#ifndef _MAINFACTORY_H_
#define _MAINFACTORY_H_H

#include "factory.h"
#include "mainproduct.h"

// sql 具体工厂
class SqlServerFactory : public CIFactory
{
private:
    /* data */
public:
    CIUser* createUser()
    {
        return new SqlServerUser();
    }
    CIDepartment* createDepartment()
    {
        return new SqlServerDepartment();
    }
};
// access 具体工厂
class AccessFactory: public CIFactory
{
private:
    /* data */
public:
    CIUser* createUser()
    {
        return new AccessUser();
    }
    CIDepartment* createDepartment()
    {
        return new AccessDepartment();
    }
};

#endif