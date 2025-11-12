#include <cmath>
struct Vector2D{
    double x;
    double y;
//Here is the basic vector constructor
    Vector2D(double _x, double _y ):x(_x),y(_y) {}//passed in values equal member vars(initializer)

    //We need to fix the way the program does math to match vectors not scalars
     Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D operator-(const Vector2D& other)const {
        return  Vector2D(x+ other.x, y- other.y);
    }
    Vector2D operator*(const Vector2D& other)const {
        return  Vector2D(x* other.x, y* other.y);
    }
};