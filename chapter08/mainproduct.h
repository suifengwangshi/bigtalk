#ifndef _MAINPRODUCT_H_
#define _MAINPRODUCT_H_

#include "product.h"
#include <iostream>

using std::cout;
using std::endl;

// 具体产品类 SqlServer User
class SqlServerUser: public CIUser
{
private:
    /* data */
public:
    void Insert(User user)
    {
        cout << "sql server insert a record!" << endl;
    }
    User getUser(int id) 
    {
        cout << "get user from sql server!" << endl;
        return User();
    }
};
// 具体产品类 SqlServer Department
class SqlServerDepartment: public CIDepartment
{
private:
    /* data */
public:
    void Insert(Department department)
    {
        cout << "sql server insert a record!" << endl;
    }
    Department getDepartment(int id) 
    {
        cout << "get department from sql server!" << endl;
        return Department();
    }
};
// 具体产品类 Access User
class AccessUser: public CIUser
{
private:
    /* data */
public:
    void Insert(User user)
    {
        cout << "sql server insert a record!" << endl;
    }
    User getUser(int id) 
    {
        cout << "get user from sql server!" << endl;
        return User();
    }
};
// 具体产品类 Access Department
class AccessDepartment: public CIDepartment
{
private:
    /* data */
public:
    void Insert(Department department)
    {
        cout << "sql server insert a record!" << endl;
    }
    Department getDepartment(int id) 
    {
        cout << "get department from sql server!" << endl;
        return Department();
    }
};

#endif