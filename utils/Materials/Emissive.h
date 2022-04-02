#include "../Hittable.h"
#include "../Vec.h"
#include "../Ray.h"
#include "../VectorOps.h"
#include "../Functions.h"

class Emissive : public prims::Materials
{
public:
    Emissive(const Point &a) : power(a) {}
        virtual bool scatter(const Ray& ray, const prims::hitRecord& rec, Point& attenuation, Ray& scattered) const {
            return false;
        }

    Point power;
};