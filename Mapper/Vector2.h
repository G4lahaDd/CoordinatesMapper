#pragma once
#include <cmath>
#include <string>

class Vector2
{
public:
    double x;
    double y;

    Vector2(): x(0), y(0){}

    Vector2(double x, double y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& vector) const
    {
        return Vector2(x + vector.x, y + vector.y);
    }

    Vector2 operator-(const Vector2& vector) const
    {
        return Vector2(x - vector.x, y - vector.y);
    }

    double operator*(const Vector2& vector) const
    {
        return x * vector.x + y * vector.y;
    }

    Vector2 operator*(double a) const
    {
        return Vector2(x * a, y * a);
    }

    double Abs() const
    {
        return sqrt(x * x + y * y);
    }

    static double GetAngleBetween(const Vector2& a, const Vector2& b)
    {
        return acos(a * b / (a.Abs() * b.Abs()));
    }

    std::string ToString() {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

