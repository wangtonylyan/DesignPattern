#ifndef DESIGN_PATTERN_1_H
#define DESIGN_PATTERN_1_H

namespace my_design_pattern {
	namespace singleton {
		//对于无论哪种方式中的getSingleton()
		//注意返回值不能是类类型，那样的话编译器会拷贝出一个新的对象
		//因此必须是指针或引用，这里仅以引用为例（即还存在2种与之对应的、以指针为例的实现方式）

		//实现方式1
		//推荐此方式，简单有效，来源于《Modern C++ Design》
		//存在的单例对象是函数级static
		namespace pattern_1 {
			class Singleton {
			public:
				static Singleton& getSingleton() {
					static Singleton singleton;
					return singleton;
				}
			private:
				//禁止一切可以从外部实例化此类的方式（除getSingleton外）
				Singleton() {};//必须定义否则单例对象无法创建
				Singleton(const Singleton&);//不定义
				Singleton& operator=(const Singleton&);//不定义
				~Singleton() {};
			};
		}

		//实现方式2
		//存在的单例对象的类级static
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
				//C++中static成员必须被显式地初始化
				static Singleton singleton;
				//而在Java中允许未初始化的static成员
				//那么该成员可以在getSingleton()函数中被初始化，如下：
				//if (singleton == null) singleton = new Singleton();
				//但是注意上述方式在多线程环境下必须进行同步
				//例如将getSingleton()声明为synchronized;
			};

			//无论C++还是Java，为应对多线程环境，推荐该单例对象的创建利用类的初始化机制
			Singleton Singleton::singleton = Singleton();
		}
	}
}

#endif