#include "MyVec2D.hpp"

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
