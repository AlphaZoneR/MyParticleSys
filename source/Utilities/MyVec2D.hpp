class MyVec2D {
public:
	float x, y;

	MyVec2D();
	MyVec2D(float x, float y);
	MyVec2D(const MyVec2D & copy);
	MyVec2D normal() const;
	void normalize();
	float length() const;
};

MyVec2D operator +(const MyVec2D & a, const MyVec2D & b);
MyVec2D operator -(const MyVec2D & a, const MyVec2D & b);

void operator +=(MyVec2D & a, const MyVec2D & b);
void operator -=(MyVec2D & a, const MyVec2D & b);

MyVec2D operator *(const MyVec2D & a, float b);
MyVec2D operator *(float a, const MyVec2D & b);

MyVec2D operator /(const MyVec2D & a, float b);

void operator *=(const MyVec2D & a, float b);
void operator /=(const MyVec2D & a, float b);
