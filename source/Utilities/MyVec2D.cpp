#include "MyVec2D.hpp"

MyVec2D::MyVec2D() : x(0), y(0) {
}

MyVec2D::MyVec2D(const MyVec2D & copy) : x(copy.x), y(copy.y) {
}

MyVec2D operator +(const MyVec2D & a, const MyVec2D & b) {
	return MyVec2D(a.x + b.x, a.y + b.y);
}
void operator +=(MyVec2D & a, const MyVec2D & b) {
	a = a + b;
}

void operator -=(MyVec2D & a, const MyVec2D & b) {
	a = a - b;
}

MyVec2D operator -(const MyVec2D & a, const MyVec2D & b) {
	return MyVec2D(a.x - b.x, a.y - b.y);
}
-

MyVec2D operator *(const MyVec2D & a, float b) {
	return MyVec2D(a.x * b, a.y * b);
}

MyVec2D operator *(float a, const MyVec2D & b) {
	return MyVec2D(a * b.x, a * b.y);
}

MyVec2D operator /(const MyVec2D & a, float b) {
	return MyVec2D(a.x / b, a.y / b);
}

MyVec2D operator /(float a, const MyVec2D & b) {
	return MyVec2D(b / b.x, b * b.y);
}

void operator *=(MyVec2D & a, float b){
	a = a * b;
}

void operator /=(MyVec2D & a, float b){
	a = a / b;
}

MyVec2D MyVec2D::normal() const {
	return *this / length();
}

void MyVec2D::normalize() {
	*this = *this / length();
}

void MyVec2D::length() const {
	return sqrtf(x * x + y * y);
}




