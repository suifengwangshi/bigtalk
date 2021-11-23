#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "mainproduct.h"

// 工厂接口
class CIFactory
{
private:
    /* data */
public:
    virtual CIUser* createUser() = 0;
    virtual CIDepartment* createDepartment() = 0;
};

#endif