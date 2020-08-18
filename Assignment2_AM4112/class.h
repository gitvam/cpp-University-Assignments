#include "std_lib_facilities.h"

class Vector2
{
private:
    float x, y;
public:
    Vector2(float _x = 0, float _y =0)  //xrisi constructor enanti twn sets giati einai pio praktiko twra
    {
        x = _x;
        y = _y;
    }

    float getx(){  //h get tou x
        return x;
    }

    float gety(){  //h get tou y
        return y;
    }

    float metro_dianusmatos(){  //euresh metrou dianusmatos
        double result;
        result = sqrt((x*x)+(y*y));
        return result;
    }

    float eswteriko_ginomeno(Vector2 a){  //vriskoume to eswteriko ginomeno ton dianusmatwn px c1.function(c2)
        double result;
        result = ((x*a.x)+(y*a.y));
        return result;
    }

    //dhlwsh twn constructors gia ta overloads pou tha ginoun sthn class.cpp
    friend ostream & operator << (ostream &out, const Vector2 &c);
    friend istream & operator >> (istream &in,  Vector2 &c);
    friend Vector2 operator+(const Vector2 &c1, const Vector2 &c2);
    friend Vector2 operator-(const Vector2 &c1, const Vector2 &c2);
    friend Vector2 operator*(const Vector2 &c1, const float &c2);
    friend Vector2 operator/(const Vector2 &c1, const float &c2);
};
