#include "Transform.h"
void Transform::InitializeMatrix() {
    matrix = (double**)(calloc(4, sizeof(double*)));
    for (size_t i = 0; i < 4; i++)
    {
        matrix[i] = (double*)(calloc(4, sizeof(double)));
    }
}

Transform::Transform() {
    position = Vector3();
    rotation = Vector3();
    scale = Vector3(1, 1, 1);

    InitializeMatrix();
}

Transform::Transform(Vector3 position, Vector3 rotation, Vector3 scale) {
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

    InitializeMatrix();
}

double** Transform::getMatrix() {
    const double deg = 3.1415 / 180;
    double cosX = cos(rotation.x * deg);
    double sinX = sin(rotation.x * deg);
    double cosY = cos(rotation.y * deg);
    double sinY = sin(rotation.y * deg);
    double cosZ = cos(rotation.z * deg);
    double sinZ = sin(rotation.z * deg);

    matrix[0][0] = scale.x * cosY * cosZ;
    matrix[0][1] = sinY * sinX - cosY * cosX * sinZ;
    matrix[0][2] = cosY * sinZ * sinX + sinY * cosX;
    matrix[0][3] = position.x;

    matrix[1][0] = sinZ;
    matrix[1][1] = scale.y * cosZ * cosX;
    matrix[1][2] = -cosZ * sinX;
    matrix[1][3] = position.y;

    matrix[2][0] = -sinY * cosZ;
    matrix[2][1] = sinY * sinZ * cosX + cosY * sinX;
    matrix[2][2] = scale.z * (cosY * cosX - sinY * sinZ * sinX);
    matrix[2][3] = position.z;

    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;

    return matrix;
}

Vector3 Transform::operator *(Vector3 vector)
{
    double x = matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z + matrix[0][3];
    double y = matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z + matrix[1][3];
    double z = matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z + matrix[2][3];
    return Vector3(x, y, z);
}