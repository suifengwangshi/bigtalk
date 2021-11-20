// 代理模式，为其他对象提供一种代理以控制对这个对象的访问。
#include<iostream>
#include<string>
using namespace std;
// Client类，也就是代理类和实体类操作的对象类
class Client
{
private:
    string name;
public:
    Client(string nm)
        :name(nm) {}
    string getName()
    {
        return name;
    }
};
// 代理类和实体类的公用接口，抽象类
class Subject
{
private:
    /* data */
public:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};
// 实体类
class RealSubject: public Subject
{
private:
    Client* mm;
public:
    RealSubject(Client* c)
        :mm(c) {}
    void GiveDolls()
    {
        cout << mm->getName() << ", 送你洋娃娃" << endl;
    }
    void GiveFlowers()
    {
        cout << mm->getName() << ", 送你鲜花" << endl;
    }
    void GiveChocolate()
    {
        cout << mm->getName() << ", 送你巧克力" << endl;
    }
};
// 代理类
class Proxy: public Subject
{
private:
    RealSubject* gg;
public:
    Proxy(Client* c)
    {
        gg = new RealSubject(c);
    }
    void GiveDolls()
    {
        gg->GiveDolls(); // 代理类实现实体类的方法
    }
    void GiveFlowers()
    {
        gg->GiveFlowers();
    }
    void GiveChocolate()
    {
        gg->GiveChocolate();
    }
};
// 客户端
int main()
{
    Client* jj = new Client("jj");

    Proxy* daili = new Proxy(jj);

    daili->GiveDolls();
    daili->GiveFlowers();
    daili->GiveChocolate();
    
    return 0;
}




