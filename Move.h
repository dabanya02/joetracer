#ifndef MOVE_H
#define MOVE_H

#include "Hittable.h"
#include "Vec.h"

// An instance of a hittable object that is moved to an absolute position
class Move : public Hittable {
public:
  Move(Hittable *hittablePtr, const Point &offset);

  virtual bool hit(const Ray &r, hitRecord &rec, double tMin,
                   double tMax) const override;

  virtual bool boundingBox(double t0, double t1,
                           aabb &outputBox) const override;

  Hittable *hittablePtr;
  Point offset;
};

#endif
