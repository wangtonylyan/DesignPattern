#ifndef DESIGN_PATTERN_2_H
#define DESIGN_PATTERN_2_H

namespace my_design_pattern {
	namespace prototype {
		class Prototype {
		public:
			Prototype() :length(0), str(nullptr) {};
		public:
			//copy constructor
			Prototype(const Prototype& _pt) {
				this->length = _pt.length;

				//ǳ����
				//this->str = _pt.str;

				//���
				this->str = new char[this->length];
				for (int i = 0; i < this->length; ++i) {
					*(this->str + i) = *(_pt.str + i);
				}
			}
			Prototype* clone() {
				return new Prototype(*this);
			}
		public:
			int length;
			char *str;
		};
	}
}

#endif