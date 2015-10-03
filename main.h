#ifndef MAIN_DESIGN_PATTERN_H
#define MAIN_DESIGN_PATTERN_H

#include <iostream>
using namespace std;

//creational pattern
#include "DesignPattern1.h"//singleton
#include "DesignPattern2.h"//prototype
#include "DesignPattern3.h"//factory method
#include "DesignPattern4.h"//abstract factory
#include "DesignPattern5.h"//builder
//structural pattern
#include "DesignPattern10.h"//proxy
#include "DesignPattern11.h"//decorator
#include "DesignPattern12.h"//facade
//#include "DesignPattern13.h"
//#include "DesignPattern14.h"
//#include "DesignPattern15.h"
//#include "DesignPattern16.h"
//behavioral pattern
#include "DesignPattern20.h"
//#include "DesignPattern21.h"
//#include "DesignPattern22.h"
//#include "DesignPattern23.h"
//#include "DesignPattern24.h"
//#include "DesignPattern25.h"
//#include "DesignPattern26.h"
//#include "DesignPattern27.h"
//#include "DesignPattern28.h"
//#include "DesignPattern29.h"
//#include "DesignPattern30.h"
//#include "DesignPattern31.h"

//reusability flexibility


//object diagram：处理对象之间的关系，决定于运行期。
//class diagram：处理类的关系，决定于在编译期。
//interaction diagram：

//classification by two criteria: purpose(creational,structural,behavioral) & scope(class,object)
/* creational class & creational object, structural class & structural object, behavioral class & behavioral object
Creational class patterns defer some partof object creation to subclasses,
while Creational object patterns defer it to another object.The Structural
class patterns use inheritance to compose classes, while the Structural object
patterns describe ways to assemble objects.The Behavioral class patterns
use inheritance to describe algorithmsand flow of control, whereas the
Behavioral object patterns describe how a group of objects cooperate to
perform a task that no singleobject can carry out alone.
*/

//creational pattern：用来构建对象以便能从实现系统解耦。
namespace my_design_pattern {
	//以两种不同的方式创建单例对象
	void use_singleton() {
		using namespace singleton;
		{
			using namespace pattern_1;
			Singleton& s = Singleton::getSingleton();
		}
		{
			using namespace pattern_2;
			Singleton& s = Singleton::getSingleton();
		}
	}

	//以p1为原型，p2和p3都是通过拷贝创建的
	void use_prototype() {
		using namespace prototype;

		Prototype *p1 = new Prototype;
		p1->length = 5;
		p1->str = "hello";

		Prototype* p2 = p1->clone();
		delete p1;//深拷贝，p2不受影响
		for (int i = 0; i < p2->length; ++i) {
			cout << *(p2->str + i);
		}
		cout << endl;

		Prototype p3(*p2);
		delete p2;//同理，深拷贝，p3不受影响
		for (int i = 0; i < p3.length; ++i) {
			cout << *(p3.str + i);
		}
		cout << endl;
	}

	//目标是生产出产品p，但该类产品有两种类型，利用两种不同的方式分别返回各一种
	void use_factory_method() {
		using namespace factory_method;

		AbstractProduct *p = nullptr;
		//实现方式1
		{
			using namespace pattern_1;
			AbstractFactoryMethod *fm = new FactoryMethod;
			p = fm->createProduct("Product1");
		}
		//实现方式2
		{
			using namespace pattern_2;
			AbstractFactoryMethod *fm = new FactoryMethod2;
			p = fm->createProduct();
		}
		if (p != nullptr)
			cout << p->data << endl;
	}

	//利用一个工厂成套生产出产品A和产品B
	void use_abstract_factory() {
		using namespace abstract_factory;

		AbstractFactory* f1 = new Factory1;
		//成套生产
		AbstractProductA* pA = f1->createProductA();
		AbstractProductB* pB = f1->createProductB();

		cout << pA->getData() << endl << pB->getData() << endl;
	}

	//通过d组装出产品p
	void use_builder() {
		using namespace builder;

		AbstractDirector *d = new Director;
		Product *p = d->getAProduct();
		cout << p->data1 << "\t" << p->data2 << "\t" << p->data3 << endl;
	}
}

//structural pattern：用不同的对象组成大规模的对象结构。
namespace my_design_pattern {
	void use_proxy() {
		//subject和proxy的声明类型都是ISubject*
		using namespace proxy;
		{
			//静态代理
			using namespace pattern_1;
			ISubject *subject = new Subject;
			//pattern_1_1
			ISubject *proxy = new pattern_1_1::Proxy(subject);
			//pattern_1_2
			proxy = new pattern_1_2::Proxy();
			//
			proxy->doSomething();
		}
		{
			//强制代理
			using namespace pattern_2;
			ISubject *subject = new Subject();
			//错误1：没有使用代理
			subject->doSomething();
			//错误2：没有使用subject返回的代理
			ISubject *proxy = new Proxy(subject);
			proxy->doSomething();
			//正确
			proxy = subject->getProxy();
			proxy->doSomething();
		}
	}

	//比较装饰前后的操作结果
	void use_decorator() {
		using namespace decorator;

		AbstractComponent *component = new Component;
		//完全没有被装饰
		component->doSomething();
		//第一次装饰
		component = new Decorator(component);
		component->doSomething();
		//对Decorator类的扩展还可以实现更多次的装饰
	}

	//比较子模块逻辑变更前后对于该系统的访问操作
	void use_facade() {
		using namespace facade;

		IFacade *f = new Facade();
		f->callModule3();
		//调用接口完全一致
		f = new Facade2();
		f->callModule3();
	}

	void use_composite() {

	}

	void use_adapter() {

	}

	void use_bridge() {

	}

	void use_flyweight() {

	}
}

//behavioral pattern：用来在对象中管理算法，关系，和责任。
namespace my_design_pattern {
	//通过两种方式定制父类对象t中定义的执行逻辑
	void use_template_method() {
		using namespace template_method;
		{
			using namespace pattern_1;
			TemplateMethod *t = new TemplateMethod;
			TemplateMethod *st = new SubTemplate;
			//t和st拥有各自不同的执行步骤
			t->execute();
			st->execute();
		}
		{
			using namespace pattern_2;
			TemplateMethod *t = new TemplateMethod;
			ISubProcess *sp = new SubProcess;
			t->execute(sp);
		}
	}

	void use_iterator() {

	}

	void use_observer() {

	}

	void use_command() {

	}

	void use_state() {
	}

	void use_strategy() {

	}

	void use_chain_of_responsibility() {
	}

	void use_mediator() {

	}

	void use_visitor() {
	}

	void use_interpreter() {
	}

	void use_memento() {

	}
}

#endif