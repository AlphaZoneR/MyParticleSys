#include "MyVec.h"
#include <math.h>

namespace util{
    MyVec::MyVec(float a, float b){
        x = a;
        y = b;
    }
    MyVec * MyVec::isub(MyVec foo){
        x -= foo.x;
        y -= foo.y;
        return this;
    }

    MyVec * MyVec::sub(MyVec foo){
        MyVec * mFool = new MyVec(x - foo.x, y - foo.y);
        return mFool;
    }

    MyVec * MyVec::iadd(MyVec foo){
        x += foo.x;
        y += foo.y;
        return this;
    }

    MyVec * MyVec::add(MyVec foo){
        return (new MyVec(x + foo.x, y + foo.y));
    }

    MyVec * MyVec::imul(float scalar){
        x *= scalar;
        y *= scalar;
        return this;
    }

    MyVec * MyVec::mul(float scalar){
        return (new MyVec(x*scalar,y*scalar));
    }

    MyVec * MyVec::idiv(float scalar){
        x /= scalar;
        y /= scalar;
        return this;
    }

    MyVec * MyVec::div(float scalar){
        return (new MyVec(x/scalar,y/scalar));
    }

    MyVec * MyVec::normalized(){
        float tempX,tempY;
        tempX = x;
        tempY = y;
        float length = sqrt(x*x + y*y);
        if(length > 0){
            return new MyVec(x/length,y/length);
        }else{
            return new MyVec(0,0);
        }
    }

    MyVec * MyVec::normalize(){
        float tempX,tempY;
        tempX = x;
        tempY = y;
        float length = sqrt(x*x + y*y);
        if(length > 0){
            x = x/length;
            y = y/length;
        }
        return this;
    }

    float MyVec::length(){
        return sqrt(x * x + y * y);
    }

    float MyVec::distance(MyVec foo){
        float tempX = x - foo.x;
        float tempY = y - foo.y;
        return sqrt(tempX * tempX +tempY * tempY);
    }
    MyVec * MyVec::copy(){
        return new MyVec(x,y);
    }

    void MyVec::zero(){
        x = 0;
        y = 0;
    }
};
