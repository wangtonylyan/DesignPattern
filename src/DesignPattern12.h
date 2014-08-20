#ifndef DESIGN_PATTERN_12_H
#define DESIGN_PATTERN_12_H

#include <iostream>
using std::cout;
using std::endl;

//1��Facadeģʽ��ȫ�������Ϊ��Java�е�interface
//����GoF���23�����ģʽ����1994�����ң�����ڵ����Ի�ͣ����Smalltalk��C++
//����Java���Եĵ������佫class��interface�����ڸ��������˸�Ϊϸ�µķֻ�
//���interface���Ʊ����Ͼ���Facadeģʽ�ľ���ʵ��
//2��Facade Pattern��Ӧ�����ķ���Ϊ����ģʽ
//�������ϼ���֪����ģʽ�ǹ�ע�ڶ�һ��ϵͳ���з�װ��Ŀ���Ƕ����ṩͳһ�ķ��ʽӿ�
//����ע����ǣ��������в��ܰ�װ�κ�ҵ���߼������ݣ���Ӧ���Ƕ�����ģ���ֱ�ӷ�װ
//��רע����һ�������桱�Ľ�ɫ
namespace my_design_pattern {
	namespace facade {
		//��ģ��1
		class Module1 {
		public:
			void doSomething() {
				cout << "Module1 do something!" << endl;
			}
		};
		//��ģ��2
		class Module2 {
		public:
			void doSomething() {
				cout << "Module2 do something!" << endl;
			}
		};
		//��ģ��3
		class Module3 {
		public:
			void doSomething() {
				cout << "Module3 do something!" << endl;
			}
		};

		//����ӿ�
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
			//���ܷ�װ�κ�ҵ���߼�
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

		//��ҵ���߼������仯ʱ������һ����װ�˱���߼�����
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

		//����ӿ�Ҫ�����ȶ�
		class Facade2 :public Facade {
		public:
			Facade2() :cm(new ComplexModule){}
			//override��������ĵ��ýӿ�
			virtual void callModule3() {
				this->cm->callModule3();
			}
		private:
			ComplexModule *cm;
		};
	}
}

#endif