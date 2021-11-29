#include "mainproduct.h"
#include "product.h"
#include "factory.h"
#include "mainfactory.h"
#include <iostream>

using namespace std;

int main()
{
    User* user = new User();
    Department* department = new Department();

    // 使用那个具体工厂
    CIFactory* factory = new SqlServerFactory();

    CIUser* iu = factory->createUser();

    iu->Insert(*user);
    iu->getUser(1);

    return 0;
}