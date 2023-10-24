#pragma once
#include <math.h>
#include "Vector3.h"

class Transform {
    void InitializeMatrix();
public:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

    double** matrix;

    Transform();
    Transform(Vector3 position, Vector3 rotation, Vector3 scale);

    double** getMatrix();
    Vector3 operator *(Vector3 vector);
};

