#ifndef DESIGN_PATTERN_5_H
#define DESIGN_PATTERN_5_H

//������ģʽ�������Ӷ���Ĺ��������ı�ʾ����룬ʹ��ͬ���ı�ʾ�������Բ�ͬ�Ĺ���
//builder & abstract factory
//ǰ���൱����װ��������עһ�������������������
//������������������עһ�������������������
namespace my_design_pattern {
	namespace builder {
		//������װ�Ĳ�Ʒ
		class Product {
		public:
			Product() :data1(0), data2(0), data3(0) {};
		public:
			int data1, data2, data3;
		};

		//�����װ�˿ɶ���product�Ĳ�������
		//�������һ�㸴����product�ṩ�Ļ����ӿڣ�������DAO��������ݿ���ʽӿڵķ�װ
		//�˴�Ϊ�˸������������û���ṩproduct�Ľӿڡ�
		class AbstractBuilder {
		public:
			//����product�ṩ�Ļ����ӿڵĽ�һ����װ
			virtual void setPart1(int) = 0;
			virtual void setPart2(int) = 0;
			virtual void setPart3(int) = 0;
		public:
			virtual Product* getProduct() = 0;
		};

		class Builder :public AbstractBuilder {
		public:
			Builder() :product(new Product) {};
			//�صؽ�������ν�ġ��߼��ӿڡ���ø߼��˵�
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


		//��������ָ����װ�Ĺ���
		class AbstractDirector {
		public:
			virtual ~AbstractDirector() {};
			//��װ
			virtual Product* getAProduct() = 0;
		protected:
			AbstractDirector() :builder(new Builder) {};
		protected:
			AbstractBuilder *builder;
		};

		//�����Զ�������������ָ����ͬ��װ���̵�
		class Director :public AbstractDirector {
		public:
			virtual Product* getAProduct() {
				//�����Ǿ������װ����
				this->builder->setPart1(1);
				this->builder->setPart2(2);
				this->builder->setPart1(2);
				this->builder->setPart3(1);
				//��װ���
				return this->builder->getProduct();
			}
		};
	}
}

#endif