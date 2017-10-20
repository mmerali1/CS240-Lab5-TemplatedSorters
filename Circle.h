#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;
#include <math.h>

class Circle{
	private:
		float radius;
		float area;
	public:
		Circle();
		Circle(float d);
		float getArea();
		bool operator<(const Circle& circIn);
		bool operator>(const Circle& circIn);
		friend ostream & operator<<(ostream &out, const Circle &circ);
};

#endif
