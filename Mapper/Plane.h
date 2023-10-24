#pragma once
#include "Vector3.h"

namespace Planes {

	class Plane {
		Vector3 origin;
		Vector3 normal;
	public:
		Plane(Vector3 origin, Vector3 normal);
		Vector3 GetIntersection(Vector3 p1, Vector3 p2);
	};

	static Plane XY = Plane(Vector3(), Vector3(0, 0, 1));
	static Plane YZ = Plane(Vector3(), Vector3(1, 0, 0));
	static Plane XZ = Plane(Vector3(), Vector3(0, 1, 0));
}




