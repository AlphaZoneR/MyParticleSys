class MyPoint2D {
public:
	MyVec2D position;
	MyVec2D previous;
	MyVec2D acceleration;

	MyPoint2D();
	MyPoint2D(const MyVec2D & position);

	void accelerate(const MyVec2D & vec);
	void correct(const MyVec2D & vec);
	void simulate(float delta);
};

MyPoint2D::MyPoint2D() {
}

MyPoint2D::MyPoint2D(const MyVec2D & position) : position(position), previous(position) {
}

void MyPoint2D::accelerate(const MyVec2D & vec) {
	acceleration += vec;
}

void MyPoint2D::correct(const MyVec2D & vec) {
	position += vec;
}

void MyPoint2D::simulate(float delta) {
	MyVec2D new_position = position * 2 - previous + acceleration * delta * delta;
	previous = position;
	position = new_position;
	acceleration = MyVec2D();
}
