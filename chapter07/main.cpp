// 模板方法模式，定义一个操作中算法的骨架，而将一些步骤延迟到子类当中，使得子类可以不改变算法的结构即可重定义该算法的某些特定步骤
#include<iostream>
#include<string>
using namespace std;
// AbstrackClass类，实现一个模板方法，定义算法的骨架
class TestPaper
{
private:
    /* data */
public:
    void TestQuestion1()
    {
        cout << "杨过得到，后来给力郭靖，练成倚天剑、屠龙刀的玄铁可能是[ ] a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维 " << endl;
        cout << "答案: " << Answer1() << endl;
    }
    void TestQuestion2()
    {
        cout << "杨过、程英、陆无双铲除了情花，造成[ ] a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破环了那个生物圈的生态平衡 d.造成该地区沙漠化 " << endl;
        cout << "答案: " << Answer2() << endl;
    }
    void TestQuestion3()
    {
        cout << "蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药[ ] a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们大量喝牛奶 " << endl;
        cout << "答案: " << Answer3() << endl;
    }
    virtual string Answer1() = 0;
    virtual string Answer2() = 0;
    virtual string Answer3() = 0;
};
// ConcreteClass类，给出父类当中抽象方法的具体实现，这样不同子类就可以使得父类中算法的实现各不相同了
class TestPaperA : public TestPaper 
{
private:

public:
    string Answer1()
    {
        return "b";
    }
    string Answer2()
    {
        return "c";
    }
    string Answer3()
    {
        return "a";
    }
};
class TestPaperB : public TestPaper 
{
private:

public:
    string Answer1()
    {
        return "c";
    }
    string Answer2()
    {
        return "a";
    }
    string Answer3()
    {
        return "a";
    }
};
// 客户端代码
int main()
{
    cout << "学生甲抄的试卷:" << endl;
    TestPaper* StudentA = new TestPaperA();
    StudentA->TestQuestion1();
    StudentA->TestQuestion2();
    StudentA->TestQuestion3();

    cout << "学生乙抄的试卷:" << endl;
    TestPaper* StudentB = new TestPaperB();
    StudentB->TestQuestion1();
    StudentB->TestQuestion2();
    StudentB->TestQuestion3();
    return 0;
}
