// 在 simple.cpp 文件中，包含一个抽象工厂类CIFactory、sql数据库工厂类SqlServerFactory和Access数据库工厂类AccessFactory，
// 这时如果要加入一个新的数据库表，就需要修改这三个类了，这里就使用简单工厂方法模式将这三个类集成一个

#include "mainproduct.h"
#include "product.h"
#include "data.h"
#include <iostream>

using namespace std;

int main()
{
    User* user = new User();
    Department* department = new Department();

    // 使用简单工厂模式中的工厂类生成具体产品实例
    CIUser* iu = DataAccess::CreateUser();

    iu->Insert(*user);
    iu->getUser(1);

    CIDepartment* id = DataAccess::CreateDepartment();
    id->Insert(*department);
    id->getDepartment(1);

    return 0;
}