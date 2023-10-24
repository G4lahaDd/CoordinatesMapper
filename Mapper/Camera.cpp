#include "Camera.h"
#define degToRad 3.1415/180

Camera::Camera(Vector3 position, Vector3 rotation) : position(position), rotation(rotation)
{
	transform = Transform(position, rotation, Vector3(1,1,1));

	double** matrix = transform.getMatrix();
	ViewRay = Vector3(0, 1, 0) * matrix;
	rightAxis = Vector3(1, 0, 0) * matrix;
	upAxis = Vector3(0, 0, 1) * matrix;

	height = 1080;
	width = 1920;
	HFOV = 60;
	VFOV = 40;
}

Vector3 Camera::GetOnPlane(Vector2 point, Plane plane)
{
	double pixel2unitHeight = tan(VFOV * degToRad / 2) / (height / 2.0);
	double pixel2unitWidth = tan(HFOV * degToRad / 2) / (width / 2.0);

	Vector3 point3d =
		ViewRay
		+ rightAxis * ((point.x - width / 2.0) * pixel2unitWidth)
		+ upAxis * ((point.y - height / 2.0) * pixel2unitHeight);

	point3d = plane.GetIntersection(position, point3d);

	return point3d;
}