#ifndef DESIGN_PATTERN_4_H
#define DESIGN_PATTERN_4_H

//���������Ƕ����������������������ѡ��ͬ��������
//���󹤳��Ƕ��ڶ�����������������ѡ��ͬ�Ĵ��䷽ʽ
namespace my_design_pattern {
	namespace abstract_factory {
		//ProductA��ProductB�����׶����Ĳ�Ʒ
		//�������ʹ�ã���һ�����������������
		//�����Ҫ���ù��������׵ء���������

		//��Ʒ��A
		class AbstractProductA {
		public:
			virtual ~AbstractProductA() {};
			virtual int getData() = 0;
		};

		//�����ƷA1
		class ProductA1 :public AbstractProductA {
		public:
			ProductA1() :data(1) {};
			virtual int getData() {
				return this->data;
			}
		private:
			int data;
		};

		//�����ƷA2
		class ProductA2 :public AbstractProductA {
		public:
			ProductA2() :data(2) {};
			virtual int getData() {
				return this->data;
			}
		private:
			int data;
		};

		//��Ʒ��B
		class AbstractProductB {
		public:
			virtual ~AbstractProductB() {};
			virtual double getData() = 0;
		};

		//�����ƷB1
		class ProductB1 :public AbstractProductB {
		public:
			ProductB1() :data(1.1) {};
			virtual double getData() {
				return this->data;
			}
		private:
			double data;
		};

		//�����ƷB2
		class ProductB2 :public AbstractProductB {
		public:
			ProductB2() :data(2.1) {};
			virtual double getData() {
				return this->data;
			}
		private:
			double data;
		};


		//����
		class AbstractFactory {
		public:
			//һ�����������׵�������Ʒ��A��B
			virtual AbstractProductA* createProductA() = 0;
			virtual AbstractProductB* createProductB() = 0;
		};

		class Factory1 :public AbstractFactory {
			virtual ProductA1* createProductA() {
				return new ProductA1;
			}
			virtual ProductB1* createProductB() {
				return new ProductB1;
			}
		};

		class Factory2 :public AbstractFactory {
			virtual ProductA2* createProductA() {
				return new ProductA2;
			}
			virtual ProductB2* createProductB() {
				return new ProductB2;
			}
		};
	}
}

#endif