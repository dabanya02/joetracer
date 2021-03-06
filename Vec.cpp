#include "Vec.h"
#include <cmath>

Vec::Vec() {
  x = 0;
  y = 0;
  z = 0;
}

Vec::Vec(const float dx, const float dy, const float dz) {
  this->x = dx;
  this->y = dy;
  this->z = dz;
}

Vec Vec::operator-() const {
  Vec v;
  v.x = -x;
  v.y = -y;
  v.z = -z;
  return v;
}

std::ostream &operator<<(std::ostream &out, const Vec &point) {
  out << "Point(" << point.x << ", " << point.y << ", " << point.z
      << ')'; // actual output done here
  return out;
}
