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


//object diagram���������֮��Ĺ�ϵ�������������ڡ�
//class diagram��������Ĺ�ϵ���������ڱ����ڡ�
//interaction diagram��

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

//creational pattern���������������Ա��ܴ�ʵ��ϵͳ���
namespace my_design_pattern {
	//�����ֲ�ͬ�ķ�ʽ������������
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

	//��p1Ϊԭ�ͣ�p2��p3����ͨ������������
	void use_prototype() {
		using namespace prototype;

		Prototype *p1 = new Prototype;
		p1->length = 5;
		p1->str = "hello";

		Prototype* p2 = p1->clone();
		delete p1;//�����p2����Ӱ��
		for (int i = 0; i < p2->length; ++i) {
			cout << *(p2->str + i);
		}
		cout << endl;

		Prototype p3(*p2);
		delete p2;//ͬ�������p3����Ӱ��
		for (int i = 0; i < p3.length; ++i) {
			cout << *(p3.str + i);
		}
		cout << endl;
	}

	//Ŀ������������Ʒp���������Ʒ���������ͣ��������ֲ�ͬ�ķ�ʽ�ֱ𷵻ظ�һ��
	void use_factory_method() {
		using namespace factory_method;

		AbstractProduct *p = nullptr;
		//ʵ�ַ�ʽ1
		{
			using namespace pattern_1;
			AbstractFactoryMethod *fm = new FactoryMethod;
			p = fm->createProduct("Product1");
		}
		//ʵ�ַ�ʽ2
		{
			using namespace pattern_2;
			AbstractFactoryMethod *fm = new FactoryMethod2;
			p = fm->createProduct();
		}
		if (p != nullptr)
			cout << p->data << endl;
	}

	//����һ������������������ƷA�Ͳ�ƷB
	void use_abstract_factory() {
		using namespace abstract_factory;

		AbstractFactory* f1 = new Factory1;
		//��������
		AbstractProductA* pA = f1->createProductA();
		AbstractProductB* pB = f1->createProductB();

		cout << pA->getData() << endl << pB->getData() << endl;
	}

	//ͨ��d��װ����Ʒp
	void use_builder() {
		using namespace builder;

		AbstractDirector *d = new Director;
		Product *p = d->getAProduct();
		cout << p->data1 << "\t" << p->data2 << "\t" << p->data3 << endl;
	}
}

//structural pattern���ò�ͬ�Ķ�����ɴ��ģ�Ķ���ṹ��
namespace my_design_pattern {
	void use_proxy() {
		//subject��proxy���������Ͷ���ISubject*
		using namespace proxy;
		{
			//��̬����
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
			//ǿ�ƴ���
			using namespace pattern_2;
			ISubject *subject = new Subject();
			//����1��û��ʹ�ô���
			subject->doSomething();
			//����2��û��ʹ��subject���صĴ���
			ISubject *proxy = new Proxy(subject);
			proxy->doSomething();
			//��ȷ
			proxy = subject->getProxy();
			proxy->doSomething();
		}
	}

	//�Ƚ�װ��ǰ��Ĳ������
	void use_decorator() {
		using namespace decorator;

		AbstractComponent *component = new Component;
		//��ȫû�б�װ��
		component->doSomething();
		//��һ��װ��
		component = new Decorator(component);
		component->doSomething();
		//��Decorator�����չ������ʵ�ָ���ε�װ��
	}

	//�Ƚ���ģ���߼����ǰ����ڸ�ϵͳ�ķ��ʲ���
	void use_facade() {
		using namespace facade;

		IFacade *f = new Facade();
		f->callModule3();
		//���ýӿ���ȫһ��
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

//behavioral pattern�������ڶ����й����㷨����ϵ�������Ρ�
namespace my_design_pattern {
	//ͨ�����ַ�ʽ���Ƹ������t�ж����ִ���߼�
	void use_template_method() {
		using namespace template_method;
		{
			using namespace pattern_1;
			TemplateMethod *t = new TemplateMethod;
			TemplateMethod *st = new SubTemplate;
			//t��stӵ�и��Բ�ͬ��ִ�в���
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