// 简单工厂模式实现
#include<iostream>
#include<string>
using namespace std;
// 抽象产品类，从具体产品类中抽象出相同部分，抽象基类，作用类似于JAVA中的接口
class CashSuper
{
private:
    /* data */
public:
    virtual double acceptCash(double money) = 0; // 纯虚函数
};
// 具体产品类，表示各种促销方法，比如打几折、满xx减xx等
// 正常收费子类
class CashNormal: public CashSuper
{
private:
    /* data */
public:
    double acceptCash(double money)
    {
        return money;
    }
};
// 打折收费子类，需要传入打折比例
class CashRebate: public CashSuper
{
private:
    double moneyRebate;
public:
    CashRebate(double moneyRebate)
        :moneyRebate(moneyRebate) {}
    double acceptCash(double money)
    {
        return money * moneyRebate;
    }
};
// 满减收费子类，需要传入满减参数
class CashReturn: public CashSuper
{
private:
    /* data */
    double moneyCondition, moneyReturn;
public:
    CashReturn(double moneyCondition, double moneyReturn)
        :moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    double acceptCash(double money)
    {
        int n = int(money/moneyCondition);
        return money - moneyReturn * n;
    }
};

// 工厂类，用于根据要求创建不同的具体产品类
class Factory
{
private:
    /* data */
public:
    static CashSuper* createCashAccept(string type)
    {
        CashSuper* cs = nullptr;
        if(type == "正常收费")
        {
            cs = new CashNormal();
        }
        else if(type == "满300返100")
        {
            cs = new CashReturn(300, 100);
        }
        else if(type == "打8折")
        {
            cs = new CashRebate(0.8);
        }
        return cs;
    }
};
// 客户端程序
void btnOK_Click()
{
    string type;
    cin >> type;
    double totalPrice = 1000;
    CashSuper* cs = Factory::createCashAccept(type);
    double shouldCash = cs->acceptCash(totalPrice);
    cout << "总价" << totalPrice << ", 参加活动最后应付" << shouldCash << endl;
    if(cs != nullptr)
    {
        delete cs;
        cs = nullptr;
    }
}
int main()
{
    btnOK_Click();
    return 0;
}
