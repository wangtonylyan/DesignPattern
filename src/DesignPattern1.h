#ifndef DESIGN_PATTERN_1_H
#define DESIGN_PATTERN_1_H

namespace my_design_pattern {
	namespace singleton {
		//�����������ַ�ʽ�е�getSingleton()
		//ע�ⷵ��ֵ�����������ͣ������Ļ��������´����һ���µĶ���
		//��˱�����ָ������ã������������Ϊ������������2����֮��Ӧ�ġ���ָ��Ϊ����ʵ�ַ�ʽ��

		//ʵ�ַ�ʽ1
		//�Ƽ��˷�ʽ������Ч����Դ�ڡ�Modern C++ Design��
		//���ڵĵ��������Ǻ�����static
		namespace pattern_1 {
			class Singleton {
			public:
				static Singleton& getSingleton() {
					static Singleton singleton;
					return singleton;
				}
			private:
				//��ֹһ�п��Դ��ⲿʵ��������ķ�ʽ����getSingleton�⣩
				Singleton() {};//���붨������������޷�����
				Singleton(const Singleton&);//������
				Singleton& operator=(const Singleton&);//������
				~Singleton() {};
			};
		}

		//ʵ�ַ�ʽ2
		//���ڵĵ���������༶static
		namespace pattern_2 {
			class Singleton {
			public:
				static Singleton& getSingleton() {
					return singleton;
				}
			private:
				Singleton() {};
				Singleton(const Singleton&);
				Singleton& operator=(const Singleton&);
				~Singleton() {};
			public:
				//C++��static��Ա���뱻��ʽ�س�ʼ��
				static Singleton singleton;
				//����Java������δ��ʼ����static��Ա
				//��ô�ó�Ա������getSingleton()�����б���ʼ�������£�
				//if (singleton == null) singleton = new Singleton();
				//����ע��������ʽ�ڶ��̻߳����±������ͬ��
				//���罫getSingleton()����Ϊsynchronized;
			};

			//����C++����Java��ΪӦ�Զ��̻߳������Ƽ��õ�������Ĵ���������ĳ�ʼ������
			Singleton Singleton::singleton = Singleton();
		}
	}
}

#endif