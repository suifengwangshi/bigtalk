// 工厂方法模式，定义一个用于创建对象的接口，让子类决定实例化哪一个类，工厂方法使一个类的实例化延迟到其子类
#include<iostream>
using namespace std;

// Product类，定义工厂方法所创建的对象的接口
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
// ConcreteProduct类，具体的产品，实现了Product接口
class OperationAdd: public Operation
{
private:
    /* data */
public:
    double GetResult()
    {
        double result = _numberA + _numberB;
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
// Creator类，声明工厂方法，该方法返回一个Product类型的对象
class Factory
{
private:
    /* data */
public:
    virtual Operation* createOperation() = 0;
};
// ConcreteCreator类，重定义工厂方法以返回一个ConcreteProduct实例
class AddFactory: public Factory
{
private:
    /* data */
public:
    Operation* createOperation()
    {
        return new OperationAdd();
    }
};
class SubFactory: public Factory
{
private:
    /* data */
public:
    Operation* createOperation()
    {
        return new OperationSub();
    }
};
class MulFactory: public Factory
{
private:
    /* data */
public:
    Operation* createOperation()
    {
        return new OperationMul();
    }
};
class DivFactory: public Factory
{
private:
    /* data */
public:
    Operation* createOperation()
    {
        return new OperationDiv();
    }
};

// 客户端代码
int main()
{
    Factory* operFactory = new AddFactory();
    Operation* oper = operFactory->createOperation();
    oper->setA(1);
    oper->setB(2);
    double result = oper->GetResult();
    cout << oper->getA() << " + " << oper->getB() << " = " << result << endl;
    delete oper;
    delete operFactory;
    oper = nullptr;
    operFactory = nullptr;
    return 0;
}




