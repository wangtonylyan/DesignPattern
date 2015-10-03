#ifndef DESIGN_PATTERN_11_H
#define DESIGN_PATTERN_11_H

#include <iostream>
using std::cout;
using std::endl;

//װ��ģʽ������Ĵ���ģʽ���̳е��������
//����ģʽ��ע���������װ��ģʽ��ע������չ
//װ��ģʽ����������չһ��ʵ���࣬���ͨ���̳и�ʵ�������ﵽ��չ�ķ�ʽ��Ϊ���
//��װ������ʵ���������ͬһ�㣬�����˼̳в�ι���
namespace my_design_pattern {
	namespace decorator {
		//������
		class AbstractComponent {
		public:
			virtual void doSomething() = 0;
		};

		//ʵ����
		class Component : public AbstractComponent {
		public:
			Component() {}
			virtual void doSomething() {
				cout << "do something!" << endl;
			}
		};

		//����ʵ����Ľ�һ����չ��װ�Σ����̳в����ʵ����ƽ��
		class Decorator : public AbstractComponent {
		public:
			Decorator(AbstractComponent* _c) :component(_c) {}
			//����ʵ����ӿڵ���չ
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

		//�����Խ�һ����Decorator�������չ������Component����һ����װ��
	}
}

#endif