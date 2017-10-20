#include "Circle.h"

Circle::Circle(){
	radius=0;
	area=0;
}

Circle::Circle(float r){
	radius = r;
	area = (3.141592 * pow(radius,2));
}

float Circle::getArea(){
	return area;
}

bool Circle::operator<(const Circle& circIn){
	if (this->area < circIn.area){
		return true;
	}
	else{
		return false;
	}
}

bool Circle::operator>(const Circle& circIn){
	if (this->area > circIn.area){
		return true;
	}
	else{
		return false;
	}

}

ostream &operator<< (ostream &out, const Circle &circ){
	out << circ.area;
	return out;
}
