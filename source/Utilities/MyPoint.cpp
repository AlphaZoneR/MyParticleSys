#include "MyPoint.h"
#include "MyVec.h"

using namespace util;

namespace util{
    MyPoint::MyPoint(float x, float y){
        position = new MyVec(x,y);
        previous = new MyVec(x,y);
        acceleration = new MyVec(0,0);
    }

    void MyPoint::accelerate(MyVec * foo){
        acceleration.iadd(foo);
    }

}
