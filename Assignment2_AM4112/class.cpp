#include "class.h"

//ta overloads

Vector2 operator+(const Vector2 &c1, const Vector2 &c2) //operator + overload
{
	return Vector2(c1.x + c2.x , c1.y + c2.y);
}

Vector2 operator-(const Vector2 &c1, const Vector2 &c2) //operator - overload
{
	return Vector2(c1.x - c2.x , c1.y - c2.y);
}

Vector2 operator*(const Vector2 &c1, const float &c2) //operator * overload
{
	return Vector2(c1.x * c2 , c1.y * c2);
}

Vector2 operator/(const Vector2 &c1, const float &c2)  //operator / overload
{
	return Vector2(c1.x / c2 , c1.y / c2);
}

ostream & operator << (ostream &out, const Vector2 &c)  //operator << overload
{
    out <<"("<<c.x<<","<<c.y<<")"<<endl;
    return out;
}

istream & operator >> (istream &in,  Vector2 &c)  //operator >> overload
{
    in >> c.x;
    in >> c.y;
    return in;
}
