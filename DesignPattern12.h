#ifndef DESIGN_PATTERN_12_H
#define DESIGN_PATTERN_12_H

#include <iostream>
using std::cout;
using std::endl;

//1）Facade模式完全可以理解为是Java中的interface
//由于GoF提出23种设计模式是在1994年左右，其基于的语言还停留在Smalltalk和C++
//随着Java语言的诞生，其将class与interface两者在概念上做了更为细致的分化
//因此interface机制本质上就是Facade模式的具体实现
//2）Facade Pattern对应的中文翻译为门面模式
//从字面上即可知，该模式是关注于对一个系统进行封装，目的是对外提供统一的访问接口
//尤其注意的是，门面类中不能包装任何业务逻辑的内容，其应仅是对于子模块的直接封装
//即专注于做一个“门面”的角色
namespace my_design_pattern {
	namespace facade {
		//子模块1
		class Module1 {
		public:
			void doSomething() {
				cout << "Module1 do something!" << endl;
			}
		};
		//子模块2
		class Module2 {
		public:
			void doSomething() {
				cout << "Module2 do something!" << endl;
			}
		};
		//子模块3
		class Module3 {
		public:
			void doSomething() {
				cout << "Module3 do something!" << endl;
			}
		};

		//对外接口
		class IFacade {
		public:
			virtual void callModule1() = 0;
			virtual void callModule2() = 0;
			virtual void callModule3() = 0;
		};

		class Facade :public IFacade {
		public:
			Facade() :m1(new Module1), m2(new Module2), m3(new Module3) {}
		public:
			//不能封装任何业务逻辑
			virtual void callModule1() {
				this->m1->doSomething();
			}
			virtual void callModule2() {
				this->m2->doSomething();
			}
			virtual void callModule3() {
				this->m3->doSomething();
			}
		private:
			Module1 *m1;
			Module2 *m2;
			Module3 *m3;
		};

		//当业务逻辑发生变化时需新增一个封装了变更逻辑的类
		class ComplexModule {
		public:
			ComplexModule() :m2(new Module2), m3(new Module3){}
			void callModule3() {
				this->m2->doSomething();
				this->m3->doSomething();
			}
		private:
			Module2 *m2;
			Module3 *m3;
		};

		//对外接口要保持稳定
		class Facade2 :public Facade {
		public:
			Facade2() :cm(new ComplexModule){}
			//override需求变更后的调用接口
			virtual void callModule3() {
				this->cm->callModule3();
			}
		private:
			ComplexModule *cm;
		};
	}
}

#endif