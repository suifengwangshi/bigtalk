#include<iostream>
using namespace std;
// 抽象产品类
class Operation
{
protected:
    double _numberA, _numberB;
public:
    double getA()
    {
        return _numberA;
    }
    double getB()
    {
        return _numberB;
    }
    void setA(double value)
    {
        _numberA = value;
    }
    void setB(double value)
    {
        _numberB = value;
    }
    virtual double GetResult()
    {
        double result = 0;
        return result;
    }
};
// 具体产品类
class OperationAdd:public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        result = _numberA + _numberB;
        return result;
    }
};
class OperationSub:public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        result = _numberA - _numberB;
        return result;
    }
};
class OperationMul:public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        result = _numberA * _numberB;
        return result;
    }
};
class OperationDiv:public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = 0;
        if(_numberB != 0)
            result = _numberA / _numberB;
        return result;
    }
};
// 简单工厂类
class Factory
{
private:
    /* data */
public:
    static Operation* createOperation(char op)
    {
        Operation* oper = nullptr;
        switch(op)
        {
            case '+':
                oper = new OperationAdd();
                break;
            case '-':
                oper = new OperationSub();
                break;
            case '*':
                oper = new OperationMul();
                break;
            case '/':
                oper = new OperationDiv();
                break;
        }
        return oper;
    }
};

// 主函数
int main()
{
    Operation* oper = Factory::createOperation('+'); // 直接调用抽象工厂类中的静态成员函数生成具体产品实例
    oper->setA(1);
    oper->setB(2);
    cout << oper->getA() << " + " << oper->getB() << " = " << oper->GetResult() << endl;
    if(oper != nullptr)
    {
        delete oper;
        oper = nullptr;
    }
    return 0;
}
