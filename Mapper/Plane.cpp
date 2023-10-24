#include "Plane.h"

Planes::Plane::Plane(Vector3 origin, Vector3 normal) : origin{origin}, normal{normal}
{
	this->normal.Normalize();
}

Vector3 Planes::Plane::GetIntersection(Vector3 p1, Vector3 p2)
{
	double Yx = (p2.y - p1.y) / (p2.x - p1.x);
	double Zx = (p2.z - p1.z) / (p2.x - p1.x);

	double A = Yx * normal.y + Zx * normal.z;
	double B = normal.y * (p1.y - origin.y);
	double C = normal.z * (p1.z - origin.z);

	double _x = (origin.x * normal.x + p1.x * A - B - C) / (normal.x + A);
	double _y = Yx * (_x - p1.x) + p1.y;
	double _z = Zx * (_x - p1.x) + p1.z;
	return Vector3(_x, _y, _z);
}
