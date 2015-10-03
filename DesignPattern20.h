#ifndef DESIGN_PATTERN_20_H
#define DESIGN_PATTERN_20_H

#include <iostream>
using std::cout;
using std::endl;

//ģ��ģʽ��������Բ��ı�һ���㷨�Ľṹ���Ϳ����ض�����㷨��ĳЩ�ض�����
//������ԣ�
//1������Ҫ�����Ǵ�绰�����ǻ�����绰�����������ĺ�����ԭ��
//�ں����룬�Ѽ����ݽ������չ�˾���ֻ�лؼҵȴ��������չ�˾���������������ȫ���ƣ�
//��Աֻ�ܱ���ʽ�Ľ��ܹ�˾�Ĳ�ʹ������Ҫ�Ļ����У�����Լ����ݳ���
//ģ�巽��ģʽ��ֵ������ˡ������롱ԭ��
//2���ɸ�����ȫ������������߼�,����ǿ��Ʒ�ת��IoC����
//������Զ��ƿɱ��ϸ�ڲ��ݣ��������ϱ���̳в���ѭ�ڸ����ҵ���߼���
//3����ģʽ�Ƕ��ڼ̳кͶ�̬������
namespace my_design_pattern {
	namespace template_method {
		//ʵ�ַ�ʽ1
		//����̳��ڸ��࣬ͨ��override�������ӹ��̵���غ���������flag���Ӷ������Լ����߼�ϸ��
		namespace pattern_1 {
			class TemplateMethod {
			public:
				TemplateMethod() :flag(false) {};
				//�ɸ�����ȫ�ƿ����߼�execute()
				//��Java�����У���ý�execute��������Ϊfinal�������ɼ̳�
				void execute() {
					this->process1();
					this->process2();
					if (this->flag)
						this->process3();
				}
			protected:
				//�����ǹ���������ҵ�����̵������ӹ���
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
					//����ִ������
					this->flag = true;
				}
			private:
				//�����ӹ��̵�ϸ��
				virtual void process1() {
					cout << "SubT:process1" << endl;
				};
			};
		}

		//ʵ�ַ�ʽ2--һ�ָ�Ϊ���ŵķ�ʽ
		//���������಻��ֱ����ϣ�����˫������������ӿ�ISubProcess�����
		//1.�ýӿڴ���̳У����ཫ��ø�����������
		//2.�����䡱�롰���䡱�໥���룬�ڱ����в������process1��process2���䶯����sp->process()��
		//3.ͨ����װ������Template Methodģʽ�����û���ʹ����͸���ģ�
		namespace pattern_2 {
			//�ӿ�
			class ISubProcess {
			public:
				virtual void process() = 0;
			};

			class TemplateMethod {
			public:
				//���������ӿڱ�̣����Ǿ����ʵ����
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

			//ʵ�ָýӿ�
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