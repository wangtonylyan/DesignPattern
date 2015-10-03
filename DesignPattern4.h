#ifndef DESIGN_PATTERN_4_H
#define DESIGN_PATTERN_4_H

//工厂方法是对于生产单个对象的灵活，可以选择不同的类类型
//抽象工厂是对于多个合作对象的灵活，可以选择不同的搭配方式
namespace my_design_pattern {
	namespace abstract_factory {
		//ProductA和ProductB是两套独立的产品
		//但会配合使用（如一个物体的两个部件）
		//因此需要利用工厂“成套地”生产两者

		//产品族A
		class AbstractProductA {
		public:
			virtual ~AbstractProductA() {};
			virtual int getData() = 0;
		};

		//具体产品A1
		class ProductA1 :public AbstractProductA {
		public:
			ProductA1() :data(1) {};
			virtual int getData() {
				return this->data;
			}
		private:
			int data;
		};

		//具体产品A2
		class ProductA2 :public AbstractProductA {
		public:
			ProductA2() :data(2) {};
			virtual int getData() {
				return this->data;
			}
		private:
			int data;
		};

		//产品族B
		class AbstractProductB {
		public:
			virtual ~AbstractProductB() {};
			virtual double getData() = 0;
		};

		//具体产品B1
		class ProductB1 :public AbstractProductB {
		public:
			ProductB1() :data(1.1) {};
			virtual double getData() {
				return this->data;
			}
		private:
			double data;
		};

		//具体产品B2
		class ProductB2 :public AbstractProductB {
		public:
			ProductB2() :data(2.1) {};
			virtual double getData() {
				return this->data;
			}
		private:
			double data;
		};


		//工厂
		class AbstractFactory {
		public:
			//一个工厂将成套地生产产品族A和B
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