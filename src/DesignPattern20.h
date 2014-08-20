#ifndef DESIGN_PATTERN_20_H
#define DESIGN_PATTERN_20_H

#include <iostream>
using std::cout;
using std::endl;

//模板模式：子类可以不改变一个算法的结构，就可以重定义该算法得某些特定步骤
//具体而言：
//1）“不要给我们打电话，我们会给你打电话”这是著名的好莱坞原则。
//在好莱坞，把简历递交给演艺公司后就只有回家等待。由演艺公司对整个娱乐项的完全控制，
//演员只能被动式的接受公司的差使，在需要的环节中，完成自己的演出。
//模板方法模式充分的体现了“好莱坞”原则。
//2）由父类完全控制着子类的逻辑,这就是控制反转（IoC）。
//子类可以定制可变的细节部份，但主体上必须继承并遵循于父类的业务逻辑。
//3）此模式是对于继承和多态的体现
namespace my_design_pattern {
	namespace template_method {
		//实现方式1
		//子类继承于父类，通过override定义了子过程的相关函数或设置flag，从而定制自己的逻辑细节
		namespace pattern_1 {
			class TemplateMethod {
			public:
				TemplateMethod() :flag(false) {};
				//由父类完全掌控主逻辑execute()
				//在Java语言中，最好将execute函数声明为final，即不可继承
				void execute() {
					this->process1();
					this->process2();
					if (this->flag)
						this->process3();
				}
			protected:
				//以下是构成了整个业务流程的三个子过程
				virtual void process1() {
					cout << "T:process1" << endl;
				};
				virtual void process2() {
					cout << "T:process2" << endl;
				};
				virtual void process3() {
					cout << "T:process3" << endl;
				};
			protected:
				bool flag;
			};

			class SubTemplate :public TemplateMethod {
			public:
				SubTemplate() {
					//定制执行流程
					this->flag = true;
				}
			private:
				//定制子过程的细节
				virtual void process1() {
					cout << "SubT:process1" << endl;
				};
			};
		}

		//实现方式2--一种更为优雅的方式
		//父类与子类不再直接耦合，而是双方都与第三方接口ISubProcess相耦合
		//1.用接口代替继承，子类将变得更加轻量级；
		//2.将“变”与“不变”相互分离，在本例中不变的是process1和process2，变动的是sp->process()；
		//3.通过封装隐藏了Template Method模式，对用户的使用是透明的；
		namespace pattern_2 {
			//接口
			class ISubProcess {
			public:
				virtual void process() = 0;
			};

			class TemplateMethod {
			public:
				//基于上述接口编程，而非具体的实现类
				void execute(ISubProcess *sp) {
					this->process1();
					sp->process();
					this->process2();
				}
			protected:
				virtual void process1() {
					cout << "T:process1" << endl;
				}
				virtual void process2() {
					cout << "T:process2" << endl;
				}
			};

			//实现该接口
			class SubProcess :public ISubProcess {
			public:
				void process() {
					cout << "SubT:process" << endl;
				}
			};
		}
	}
}

#endif