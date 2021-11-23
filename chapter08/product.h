#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include<string>
// user表数据结构
class User
{
private:
    int _id;
    std::string _name;
public:
    void setId(int val)
    {
        _id = val;
    }
    int getId()
    {
        return _id;
    }
    void setName(std::string val)
    {
        _name = val;
    }
    std::string getName()
    {
        return _name;
    }
};
// 抽象产品类 user表
class CIUser
{
private:
    /* data */
public:
    virtual void Insert(User user) = 0;
    virtual User getUser(int id) = 0;
};

// department表数据结构
class Department
{
private:
    int _id;
    std::string _name;
public:
    void setId(int val)
    {
        _id = val;
    }
    int getId()
    {
        return _id;
    }
    void setName(std::string val)
    {
        _name = val;
    }
    std::string getName()
    {
        return _name;
    }
};
// 抽象产品类 department表
class CIDepartment
{
private:
    /* data */
public:
    virtual void Insert(Department user) = 0;
    virtual Department getDepartment(int id) = 0;
};

#endif
