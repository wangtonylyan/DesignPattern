#ifndef DESIGN_PATTERN_10_H
#define DESIGN_PATTERN_10_H

#include <iostream>
using std::cout;
using std::endl;

//代理模式
//重点：实现中和实际使用时，将应代理者与被代理者的类型都声明为两者所共同继承的抽象类/接口类型
//优点是能够基于抽象类/接口编程
namespace my_design_pattern {
	namespace proxy {
		//静态代理
		namespace pattern_1 {
			//抽象类
			class ISubject {
			public:
				virtual void doSomething() = 0;
			};

			//实现类，即被代理者
			class Subject :public ISubject {
				virtual void doSomething() {
					cout << "do something!" << endl;
				}
			};

			namespace pattern_1_1 {
				class Proxy :public ISubject {
				public:
					//构造函数参数可以传入不同的被代理对象
					//因此一个代理类可以代理多个具体的实现类
					Proxy(ISubject* _s) :subject(_s) {}
					virtual void doSomething() {
						this->subject->doSomething();
					}
				private:
					ISubject *subject;
				};
			}

			namespace pattern_1_2 {
				class Proxy :public ISubject {
				public:
					//每个代理类绑定一个固定的实现类
					Proxy() :subject(new Subject) {}
					virtual void doSomething() {
						//如果在此函数中创建new Subject，而不是在构造函数中创建
						//就是虚拟代理，即延迟创建需要被代理的对象
						//if (this->subject == nullptr) this->subject = new Subject;
						this->subject->doSomething();
					}
				private:
					ISubject *subject;
				};
			}

			//如果代理类对被代理类作进一步封装，那就是装饰模式了
		}

		//强制代理
		//1.强制必须使用代理
		//2.强制使用的代理必须是由被代理者所返回的--优点是不需要使用者知道应怎样调用哪个代理类
		//此模式中由subject主导proxy：使用的proxy必须是subject创建并返回的
		namespace pattern_2 {
			class ISubject {
			public:
				virtual void doSomething() = 0;
				//代理者和被代理者都可以返回代理对象
				//被代理者返回的代理对象就是代理者
				//代理者返回的代理对象就是自身
				//当然也可以进一步增加代理层次：代理者也被代理了，因而返回的是另一个代理者
				virtual ISubject* getProxy() = 0;
			};

			class Proxy :public ISubject {
			public:
				//允许用户自己创建代理对象
				Proxy(ISubject* _s) :subject(_s) {};
				//但是在调用下面函数时会调用subject.request()
				//在subject.request()中会判断是否创建了proxy
				//即用户虽能自己创建代理对象却不能正常使用
				virtual void doSomething() {
					this->subject->doSomething();
				}
				//代理类的代理就是其自己
				//当然也可以继续增加代理的层次
				virtual ISubject* getProxy() {
					return this;
				}
			private:
				ISubject *subject;
			};

			class Subject :public ISubject {
			public:
				//构造函数并没有创建代理对象
				//代理对象会在用户首次显式调用getProxy是被创建
				//目的是提醒并强制用户必须使用代理
				Subject() :proxy(nullptr) {};
				virtual void doSomething() {
					if (this->proxy == nullptr)
						//报错！
						cout << "ERROR: PLEASE USE PROXY!" << endl;
					else
						cout << "do something!" << endl;
				}
				virtual ISubject* getProxy() {
					//如果还未创建代理对象则创建之
					if (this->proxy == nullptr)
						this->proxy = new Proxy(this);
					return this->proxy;
				}
			private:
				ISubject *proxy;
			};
		}

		//动态代理
		namespace pattern_3 {
			//仅由Java平台提供
			//package：java.lang.reflect----面向interface
			//framework：CGLIB----面向class
		}
	}
}

#endif