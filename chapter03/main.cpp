// 采用简单的类实现时，每次都会将过程展示在客户端面前，
// 现在使用装饰模式，内部组装好了再统一显示出来
#include<iostream>
#include<string>
using namespace std;
// ConcreteComponent类
class Person
{
private:
    string name;
public:
    Person(string name = "小菜")
    :name(name){}
    virtual void Show()
    {
        cout << "装扮的" << name;
    }
};
// Decorator类
class Finery: public Person
{
protected:
    Person* component; // 定义一个父类对象实例用于调用父类中的方法
private:
    /* data */
public:
    Finery() {};
    void Decorator(Person* component)
    {
        this->component = component;
    }
    void Show()
    {
        if(component != nullptr)
        {
            component->Show();
        }
    } 
};
// 具体服饰类 ConcreteDecorator类
// T恤类
class TShirts: public Finery
{
private:
    /* data */
public:
    void Show()
    {
        cout << "大T恤 " ;
        Finery::Show(); // 调用父类中的同名函数
    }
};
// 垮裤类
class BigTrouser: public Finery
{
private:
    /* data */
public:
    void Show()
    {
        cout << "垮裤 " ;
        Finery::Show(); // 调用父类中的同名函数
    }
};
// 破球鞋
class Sneakers: public Finery
{
private:
    /* data */
public:
    void Show()
    {
        cout << "破球鞋 " ;
        Finery::Show(); // 调用父类中的同名函数
    }
};
// 西装
class Suit: public Finery
{
private:
    /* data */
public:
    void Show()
    {
        cout << "西装 " ;
        Finery::Show(); // 调用父类中的同名函数
    }
};
// 领带
class Tie: public Finery
{
private:
    /* data */
public:
    void Show()
    {
        cout << "领带 " ;
        Finery::Show(); // 调用父类中的同名函数
    }
};
// 皮鞋
class LeatherShoes: public Finery
{
private:
    /* data */
public:
    void Show()
    {
        cout << "皮鞋 " ;
        Finery::Show(); // 调用父类中的同名函数
    }
};
// 客户端
int main()
{
    Person* xc = new Person("小菜");
    cout << "第一种装扮: " << endl;
    Sneakers* pqx = new Sneakers();
    BigTrouser* kk = new BigTrouser();
    TShirts* dtx = new TShirts();
    
    pqx->Decorator(xc);
    kk->Decorator(pqx);
    dtx->Decorator(kk);
    dtx->Show();
    
    cout << endl;


    cout << "第二种装扮: " << endl;
    LeatherShoes* px = new LeatherShoes();
    Tie* ld = new Tie();
    Suit* xz = new Suit();
    
    

    px->Decorator(xc);
    ld->Decorator(px);
    xz->Decorator(ld);
    xz->Show();

    cout << endl;
    return 0;
}




