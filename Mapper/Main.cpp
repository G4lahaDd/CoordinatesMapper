#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Camera.h"

using namespace std;

void main() {
	Camera camera = Camera(Vector3(0,0,3), Vector3(-37, 0, 10));
	camera.height = 1080;
	camera.width = 1920;
	camera.HFOV = 60;
	camera.VFOV = 40;

	Vector2 points[10] = {
		Vector2(1117,1080),
		Vector2(1161,523),
		Vector2(1015,303),
		Vector2(991,174),
		Vector2(1161,523),
		Vector2(1161,523),
		Vector2(1054,98),
		Vector2(1167,70),
		Vector2(1189,32),
		Vector2(1160,0),
	};

	for (size_t i = 0; i < 10; i++)
	{
		cout << "POINT: " << points[i].ToString() << " --> " << camera.GetOnPlane(points[i], XY).ToString() << endl;
	}

}