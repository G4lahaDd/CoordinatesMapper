#pragma once
#include <cmath>
#include <string>

class Vector3 {
public:
	double x;
	double y;
	double z;

	Vector3() : x(0), y(0), z(0) {}

	Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

	Vector3 operator+(const Vector3& vector2) const {
		return Vector3(x + vector2.x, y + vector2.y, z + vector2.z);
	}

	Vector3 operator-(const Vector3& vector2) const {
		return Vector3(x - vector2.x, y - vector2.y, z - vector2.z);
	}

	double operator*(const Vector3& vector2) const {
		return x * vector2.x + y * vector2.y + z * vector2.z;
	}

	Vector3 operator*(double a) {
		return Vector3(x * a, y * a, z * a);
	}

	Vector3 operator/(double a) {
		return Vector3(x / a, y / a, z / a);
	}

	Vector3 operator*(double** matrix) {
		double _x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
		double _y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
		double _z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];

		return Vector3(_x, _y, _z);
	}

	double Abs() {
		return sqrt(x * x + y * y + z * z);
	}

	void Normalize() {
		double abs = Abs();
		x /= abs;
		y /= abs;
		z /= abs;
	}

	static double GetAngleBetween(Vector3 a, Vector3 b) {
		return acos((a.x * b.x + a.y * b.y + a.z * b.z) / (a.Abs() * b.Abs()));
	}

	static Vector3 Product(Vector3 a, Vector3 b) {
		return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}

	std::string ToString() {
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}
};

