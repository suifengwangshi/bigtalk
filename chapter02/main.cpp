// 策略模式实现商场收银系统
#include<iostream>
#include<string>
using namespace std;
// Strategy类，定义了所有支持的算法的公共接口
class Strategy
{
private:
    /* data */
public:
    virtual double acceptCash(double money) = 0; // 纯虚函数
};
// ConcreteStrategy类，封装了具体的策略算法或行为
class CashNormal: public Strategy
{
private:
    /* data */
public:
    double acceptCash(double money)
    {
        return money;
    }
};
class CashRebate: public Strategy
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
class CashReturn: public Strategy
{
private:
    double moneyCondition, moneyReturn;
public:
    CashReturn(double moneyCondition, double moneyReturn)
        :moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    double acceptCash(double money)
    {
        int n = int(money / moneyCondition);
        return money - n * moneyReturn;
    }
};
// Context类，用一个ConcreteStrategy对象类配置，维护一个对Strategy对象的引用
class Context
{
private:
    Strategy* strategy;
public:
    Context(string type)
    {
        if(type == "正常收费")
        {
            strategy = new CashNormal();
        }
        else if(type == "满300返100")
        {
            strategy = new CashReturn(300, 100);
        }
        else if(type == "打8折")
        {
            strategy = new CashRebate(0.8);
        }
    }
    double getResult(double money)
    {
        double ret = 0.0;
        if(strategy != nullptr)
        {
            ret = strategy->acceptCash(money);
            delete strategy;
            strategy = nullptr;
        }
        return ret;
    }
};
// 客户端程序
void btnOK_Click()
{
    string type;
    cin >> type;
    double totalPrice = 1000;
    Context* cs = new Context(type);
    double shouldCash = cs->getResult(totalPrice);
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



