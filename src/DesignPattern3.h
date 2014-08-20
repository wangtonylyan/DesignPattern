#ifndef DESIGN_PATTERN_3_H
#define DESIGN_PATTERN_3_H

namespace my_design_pattern {
	namespace factory_method {
		//���������Ĳ�Ʒ��
		class AbstractProduct {
		protected:
			AbstractProduct() :data(0) {}
		public:
			int data;
		};

		class Product1 :public AbstractProduct {
		public:
			Product1() {
				this->data = 1;
			}
		};

		class Product2 :public AbstractProduct {
		public:
			Product2() {
				this->data = 2;
			}
		};

		//ʵ�ַ�ʽ1������������ڳ�Ա�������ж���Ҫ�����Ķ��������
		//java�п��Դ���Class
		//�˷�ʽ��C++��ʵ�ֲ�����open closed principle��������Ʒʱ�ض����޸����г�Ա����
		namespace pattern_1 {
			class AbstractFactoryMethod {
			public:
				virtual AbstractProduct* createProduct(char*) = 0;
			};

			class FactoryMethod :public AbstractFactoryMethod {
			public:
				virtual AbstractProduct* createProduct(char* c) {
					if (*c++ == 'P' && *c++ == 'r' && *c++ == 'o'
						&& *c++ == 'd' && *c++ == 'u' && *c++ == 'c'
						&& *c++ == 't' && *c == '1')
						return new Product1;
					c -= 7;
					if (*c++ == 'P' && *c++ == 'r' && *c++ == 'o'
						&& *c++ == 'd' && *c++ == 'u' && *c++ == 'c'
						&& *c++ == 't' && *c == '2')
						return new Product2;

					//���������ӵĲ�Ʒ����...
					
					return nullptr;
				};
			};
		}

		//ʵ�ַ�ʽ2��һ��product��Ӧһ��factorymethod
		//����һ����Ʒ�ͱ�������һ������
		//�������޸������࣬�������open closed principle
		namespace pattern_2 {
			class AbstractFactoryMethod {
			public:
				virtual AbstractProduct* createProduct() = 0;
			};

			class FactoryMethod1 :public AbstractFactoryMethod {
			public:
				virtual Product1* createProduct() {
					return new Product1;
				};
			};

			class FactoryMethod2 :public AbstractFactoryMethod {
			public:
				virtual Product2* createProduct() {
					return new Product2;
				};
			};
		}
	}
}

#endif