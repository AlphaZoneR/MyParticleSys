class MyVec2D {
public:
	float x, y;

	MyVec2D();
	MyVec2D(const MyVec2D & copy);
};

MyVec2D operator +(const MyVec2D & a, const MyVec2D & b);

MyVec2D::MyVec2D() : x(0), y(0) {
}

MyVec2D::MyVec2D(const MyVec2D & copy) : x(copy.x), y(copy.y) {
}

MyVec2D operator +(const MyVec2D & a, const MyVec2D & b) {
	return MyVec2D(a.x + b.x, a.y + b.y);
}

MyVec2D operator *(const MyVec2D & a, float b) {
	return MyVec2D(a.x * f, a.y * f);
}

MyVec2D operator *(float a, const MyVec2D & b) {
	return MyVec2D(f * b.x, f * b.y);
}

void operator +=(MyVec2D & a, const MyVec2D & b) {
	a = a + b;
}
