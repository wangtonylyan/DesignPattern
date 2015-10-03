#ifndef DESIGN_PATTERN_5_H
#define DESIGN_PATTERN_5_H

//建造者模式：将复杂对象的构建与他的表示相分离，使得同样的表示可以来自不同的构建
//builder & abstract factory
//前者相当于组装工厂，关注一个物体各个部件的配置
//后者是生产工厂，关注一个物体各个部件的数量
namespace my_design_pattern {
	namespace builder {
		//用于组装的产品
		class Product {
		public:
			Product() :data1(0), data2(0), data3(0) {};
		public:
			int data1, data2, data3;
		};

		//此类封装了可对于product的操作集合
		//此类操作一般复杂于product提供的基本接口，类似于DAO层对于数据库访问接口的封装
		//此处为了更显著，因而并没有提供product的接口。
		class AbstractBuilder {
		public:
			//对于product提供的基本接口的进一步封装
			virtual void setPart1(int) = 0;
			virtual void setPart2(int) = 0;
			virtual void setPart3(int) = 0;
		public:
			virtual Product* getProduct() = 0;
		};

		class Builder :public AbstractBuilder {
		public:
			Builder() :product(new Product) {};
			//特地将以下所谓的“高级接口”变得高级了点
			virtual void setPart1(int _i) {
				this->product->data1 += _i;
			}
			virtual void setPart2(int _i) {
				this->product->data2 += _i;
			}
			virtual void setPart3(int _i) {
				this->product->data3 += _i;
			}
			virtual Product* getProduct() {
				return this->product;
			}
		private:
			Product *product;
		};


		//此类用于指导组装的过程
		class AbstractDirector {
		public:
			virtual ~AbstractDirector() {};
			//组装
			virtual Product* getAProduct() = 0;
		protected:
			AbstractDirector() :builder(new Builder) {};
		protected:
			AbstractBuilder *builder;
		};

		//还可以定义多个子类用于指导不同组装过程的
		class Director :public AbstractDirector {
		public:
			virtual Product* getAProduct() {
				//以下是具体的组装过程
				this->builder->setPart1(1);
				this->builder->setPart2(2);
				this->builder->setPart1(2);
				this->builder->setPart3(1);
				//组装完毕
				return this->builder->getProduct();
			}
		};
	}
}

#endif