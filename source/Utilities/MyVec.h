#pragma once

namespace util{
    class MyVec{
    public:
        float x,y;
        MyVec(float a, float b);
        MyVec * isub(MyVec foo);
        MyVec * sub (MyVec foo);
        MyVec * iadd (MyVec foo);
        MyVec * add (MyVec foo);
        MyVec * imul (float scalar);
        MyVec * mul (float scalar);
        MyVec * div (float scalar);
        MyVec * idiv (float scalar);
        MyVec * normalized();
        MyVec * normalize();
        float distance(MyVec foo);
        float length();
        MyVec * copy();
        void zero();
    };

};
