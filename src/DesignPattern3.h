#ifndef DESIGN_PATTERN_3_H
#define DESIGN_PATTERN_3_H

namespace my_design_pattern {
	namespace factory_method {
		//生产出来的产品类
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

		//实现方式1：传入参数，在成员函数中判断需要创建的对象的类型
		//java中可以传入Class
		//此方式以C++的实现不满足open closed principle，新增产品时必定会修改现有成员函数
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

					//将来新增加的产品代码...
					
					return nullptr;
				};
			};
		}

		//实现方式2：一个product对应一个factorymethod
		//新增一个产品就必须新增一个子类
		//但不用修改现有类，因此满足open closed principle
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