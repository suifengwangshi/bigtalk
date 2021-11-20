// 采用简单的类来实现不同的功能，也就是从不同的功能当中提取出共同的部分作为抽象基类，然后不同的具体功能类继承即可
// 采用这种方式可以看到，我们将装饰的顺序暴露在了客户端面前，正常应该在内部就组织好，然后显示出来
#include<iostream>
#include<string>
using namespace std;
// 抽象类  服饰类
class Finery
{
private:
    /* data */
public:
    virtual void Show() = 0; // 纯虚函数
};
// 具体功能类
// T恤类
class TShirts: public Finery
{
private:
    /* data */
public:
    void Show()
    {
        cout << "大T恤 " ;
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
    }
};

// Person类，用于生成使用各种功能的对象实例
class Person
{
private:
    string name;
public:
    Person(string name)
        :name(name) {}
    void Show()
    {
        cout << "装扮的" << name ;
    }
};
// 客户端
int main()
{
    Person* xc = new Person("小菜");
    cout << "第一种装扮: " << endl;
    Finery* dtx = new TShirts();
    Finery* kk = new BigTrouser();
    Finery* pqx = new Sneakers();

    dtx->Show();
    kk->Show();
    dtx->Show();
    xc->Show();

    cout << endl;


    cout << "第二种装扮: " << endl;
    Finery* xz = new Suit();
    Finery* ld = new Tie();
    Finery* px = new LeatherShoes();

    xz->Show();
    ld->Show();
    px->Show();
    xc->Show();

    cout << endl;
    return 0;
}



