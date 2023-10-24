#pragma once
#include "Transform.h"
#include "Vector2.h"
#include "Plane.h"

using namespace Planes;

class Camera
{
	Vector3 position;
	Vector3 rotation;
	Transform transform;
	Transform inverseTrans;

	Vector3 ViewRay;
	Vector3 rightAxis;
	Vector3 upAxis;
public:
	double width;
	double height;

	double HFOV;
	double VFOV;

	Camera(Vector3 position, Vector3 rotation);
	Vector3 GetOnPlane(Vector2 point, Plane plane);
};