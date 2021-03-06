装饰模式
动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更加灵活
1、一般来说，装饰模式会包含四种类，分别是Component类、ConcreteComponent类、Decorator类和ConcreteDecorator类，
其中Component类定义一个对象接口，可以给这些对象动态地添加职责；ConcreteComponent类定义了一个具体的对象，也
可以给这个对象添加一些职责；Decorator类是装饰抽象类，继承了Component，从外类来扩展Component类的功能，但对于
Component类来说是无需知道Decorator类的存在的；ConcreteDecorator类就是具体的装饰对象，起到了给Component类
添加职责的功能。
2、装饰模式是利用Decorator类的SetComponent来对对象进行包装的，这样每个装饰对象的实现就和如何使用这个对象
分离了，每个装饰对象只关心自己的功能，不需要关系如何被添加到对象链当中了。
3、如果只有一个ConcreteComponent类而没有抽象的Component类，那么Decorator类可以是ConcreteComponent类的
一个子类，同样道理，如果只要一个具体装饰类ConcreteDecorator，那么就没有必要建立一个单独的Decorator类，而
可以把Decorator类和ConcreteDecorator的责任合并成一个类。
4、装饰模式提供了一个非常好的解决方案，它把每个要装饰的功能放在单独的类中，并让这个类包装它所要装饰的对象，
因此，当需要执行特殊行为时，客户代码就可以在运行时根据需要有选择地、按顺序地使用装饰功能包装对象了。
5、总结一下装饰模式的优点：第一，把类中的装饰功能从类中搬移去除，这样就可以简化原有的类；第二，有效地把类
的核心职责和装饰功能区分开了，而且可以去除相关类中重复的装饰逻辑。