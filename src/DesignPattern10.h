#ifndef DESIGN_PATTERN_10_H
#define DESIGN_PATTERN_10_H

#include <iostream>
using std::cout;
using std::endl;

//����ģʽ
//�ص㣺ʵ���к�ʵ��ʹ��ʱ����Ӧ�������뱻�����ߵ����Ͷ�����Ϊ��������ͬ�̳еĳ�����/�ӿ�����
//�ŵ����ܹ����ڳ�����/�ӿڱ��
namespace my_design_pattern {
	namespace proxy {
		//��̬����
		namespace pattern_1 {
			//������
			class ISubject {
			public:
				virtual void doSomething() = 0;
			};

			//ʵ���࣬����������
			class Subject :public ISubject {
				virtual void doSomething() {
					cout << "do something!" << endl;
				}
			};

			namespace pattern_1_1 {
				class Proxy :public ISubject {
				public:
					//���캯���������Դ��벻ͬ�ı��������
					//���һ����������Դ����������ʵ����
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
					//ÿ���������һ���̶���ʵ����
					Proxy() :subject(new Subject) {}
					virtual void doSomething() {
						//����ڴ˺����д���new Subject���������ڹ��캯���д���
						//��������������ӳٴ�����Ҫ������Ķ���
						//if (this->subject == nullptr) this->subject = new Subject;
						this->subject->doSomething();
					}
				private:
					ISubject *subject;
				};
			}

			//���������Ա�����������һ����װ���Ǿ���װ��ģʽ��
		}

		//ǿ�ƴ���
		//1.ǿ�Ʊ���ʹ�ô���
		//2.ǿ��ʹ�õĴ���������ɱ������������ص�--�ŵ��ǲ���Ҫʹ����֪��Ӧ���������ĸ�������
		//��ģʽ����subject����proxy��ʹ�õ�proxy������subject���������ص�
		namespace pattern_2 {
			class ISubject {
			public:
				virtual void doSomething() = 0;
				//�����ߺͱ������߶����Է��ش������
				//�������߷��صĴ��������Ǵ�����
				//�����߷��صĴ�������������
				//��ȻҲ���Խ�һ�����Ӵ����Σ�������Ҳ�������ˣ�������ص�����һ��������
				virtual ISubject* getProxy() = 0;
			};

			class Proxy :public ISubject {
			public:
				//�����û��Լ������������
				Proxy(ISubject* _s) :subject(_s) {};
				//�����ڵ������溯��ʱ�����subject.request()
				//��subject.request()�л��ж��Ƿ񴴽���proxy
				//���û������Լ������������ȴ��������ʹ��
				virtual void doSomething() {
					this->subject->doSomething();
				}
				//������Ĵ���������Լ�
				//��ȻҲ���Լ������Ӵ���Ĳ��
				virtual ISubject* getProxy() {
					return this;
				}
			private:
				ISubject *subject;
			};

			class Subject :public ISubject {
			public:
				//���캯����û�д����������
				//�����������û��״���ʽ����getProxy�Ǳ�����
				//Ŀ�������Ѳ�ǿ���û�����ʹ�ô���
				Subject() :proxy(nullptr) {};
				virtual void doSomething() {
					if (this->proxy == nullptr)
						//����
						cout << "ERROR: PLEASE USE PROXY!" << endl;
					else
						cout << "do something!" << endl;
				}
				virtual ISubject* getProxy() {
					//�����δ������������򴴽�֮
					if (this->proxy == nullptr)
						this->proxy = new Proxy(this);
					return this->proxy;
				}
			private:
				ISubject *proxy;
			};
		}

		//��̬����
		namespace pattern_3 {
			//����Javaƽ̨�ṩ
			//package��java.lang.reflect----����interface
			//framework��CGLIB----����class
		}
	}
}

#endif