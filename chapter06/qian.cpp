// 原型模式，用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
// 题目场景，复制简历，其中简历类应该包含姓名、性别、年龄、工作时间和工作单位
// 对于一个求职者来说，他的姓名、性别和年龄基本是一样的，所以我们就抽象出Resume类和WorkExperience类
#include<iostream>
#include<string>
using namespace std;
// WorkExperience类
class WorkExperience
{
private:
    string workDate, company;
public:
    WorkExperience(){}
    ~WorkExperience(){}
    void setWorkDate(string workDate)
    {
        this->workDate = workDate;
    }
    string getWorkDate()
    {
        return this->workDate;
    }
    void setCompany(string company)
    {
        this->company = company;
    }
    string getCompany()
    {
        return this->company;
    }
};
// 原型类，Prototype类，声明一个克隆自身的接口
class Prototype
{
protected:
    string name;
    string sex;
    string age;
    string timeArea;
    string company;
public:
    virtual void SetPersonalInfo(string sex, string age) = 0;
    virtual void SetWorkExperience(string workDate, string company) = 0;
    virtual void Display() = 0;
    virtual Prototype* Clone() = 0;
};
// 具体原型类，ConcretePrototype类，实现一个克隆自身的操作
class Resume: public Prototype
{
private:
    WorkExperience* work; // 引用工作对象
public:
    Resume(string name = "a")
    {
        this->name = name;
        work = new WorkExperience();
    }
    ~Resume()
    {
        if(work != nullptr)
        {
            delete work;
            work = nullptr;
        }
    }
    void SetPersonalInfo(string sex, string age)
    {
        this->sex = sex;
        this->age = age;
    }
    void SetWorkExperience(string workDate, string company)
    {
        work->setWorkDate(workDate);
        work->setCompany(company);
    }
    void Display()
    {
        cout << name << " " << age << " " << sex << endl;
        cout << "工作经历 " << work->getWorkDate() << " " << work->getCompany() << endl;
    }
    // 实现克隆函数
    Resume* Clone()
    {
        return this;
    }
};
// 客户端代码
int main()
{
    // 第一份简历
    Resume* a = new Resume("大鸟");
    a->SetPersonalInfo("Man", "29");
    a->SetWorkExperience("2020-2021", "nullmax");

    // 第二份简历
    Resume* b = a->Clone();
    b->SetWorkExperience("2019-2020", "ali");

    // 第三份简历
    Resume* c = a->Clone();
    c->SetPersonalInfo("Man", "30");
    c->SetWorkExperience("2021-2022", "tongji");

    // 展示简历
    a->Display();
    b->Display();
    c->Display();
    return 0;
}



