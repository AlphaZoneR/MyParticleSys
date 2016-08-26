#pragma once
#include "MyVec.h"
namespace util{
    class MyPoint{
        public:
        MyVec * position, * previous, * acceleration; // * * *


        MyPoint(float x, float y);
        void accelerate(MyVec foo);
        void correct(MyVec foo);
        void simulate(float delta);


    };


}
