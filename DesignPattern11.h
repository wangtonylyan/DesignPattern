#ifndef DESIGN_PATTERN_11_H
#define DESIGN_PATTERN_11_H

#include <iostream>
using std::cout;
using std::endl;

//装饰模式，特殊的代理模式，继承的替代方案
//代理模式更注重于替代，装饰模式更注重于扩展
//装饰模式可以用于扩展一个实现类，这比通过继承该实现类来达到扩展的方式更为灵活
//且装饰类与实现类可以在同一层，避免了继承层次过深
namespace my_design_pattern {
	namespace decorator {
		//抽象类
		class AbstractComponent {
		public:
			virtual void doSomething() = 0;
		};

		//实现类
		class Component : public AbstractComponent {
		public:
			Component() {}
			virtual void doSomething() {
				cout << "do something!" << endl;
			}
		};

		//对于实现类的进一步扩展（装饰），继承层次与实现类平行
		class Decorator : public AbstractComponent {
		public:
			Decorator(AbstractComponent* _c) :component(_c) {}
			//对于实现类接口的扩展
			virtual void doSomething() {
				this->component->doSomething();
				this->doSomethingMore();
			}
		private:
			void doSomethingMore() {
				cout << "do something more !" << endl;
			};
		private:
			AbstractComponent *component;
		};

		//还可以进一步对Decorator类进行扩展，即对Component做进一步的装饰
	}
}

#endif