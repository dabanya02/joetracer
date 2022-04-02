#include "PinholeCamera.h"
#include "utils/Ray.h"
#include "utils/VectorOps.h"

using namespace utils;

#define PI 3.14159265358979323846264338327950288419716939937510582097

PinholeCamera::PinholeCamera()
{
}

PinholeCamera::PinholeCamera(float z_near, float verticalFOV, Point location, Point lookat)
{
    this->z_near = z_near;
    this->verticalFOV = verticalFOV;
    this->location = location;
    this->lookat = lookat;
}

void PinholeCamera::getPrimaryRay(float x, float y, int width, int height, Ray &r) const
{
    // the scaling that depends on the fov of the camera; greater values means that the rays are projected farther away from the centre of the screen
    const float halfHeight = tan(verticalFOV * PI / 360.0f);
    const float halfWidth = halfHeight * width / height;

    Vec u, v, w;

    Vec vUp = Vec(0, 1, 0);

    w = math::getUnitVec(math::sub(location, lookat).direction());
    u = math::getUnitVec(math::crossProduct(vUp, w));
    v = math::crossProduct(w, u);

    Point origin = location;

    Point topLeft = origin;
    topLeft = math::sub(topLeft, math::point(math::scale(halfWidth, u)));
    topLeft = math::add(topLeft, math::point(math::scale(halfHeight, v)));
    topLeft = math::sub(topLeft, math::point(w));

    Vec horizontal = math::scale(2 * halfWidth, u);
    Vec vertical = math::scale(2 * halfHeight, v);

    r.origin = origin;

    Point xloc = math::point(math::scale(x, horizontal));
    Point yloc = math::point(math::scale(y, vertical));
    Point loc = math::sub(xloc, yloc);
    r.direction = math::sub(math::add(topLeft, loc), origin).direction();
}

void PinholeCamera::changeLocation(Point p)
{
    location = p;
}