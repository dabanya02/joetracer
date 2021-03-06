#include "onb.h"
#include "Functions.h"
#include <cmath>

// Builds a orthonormal basis with n as the "w"
void onb::buildFromW(Vec n) {
  axis2 = unitVec(n);
  Vec a = (std::fabs(w().x) > 0.9) ? Vec(0, 1, 0) : Vec(1, 0, 0);
  axis1 = unitVec(crossProduct(axis2, a));
  axis0 = crossProduct(axis2, axis1);
}
