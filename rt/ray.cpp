#include <core/assert.h>
#include <core/macros.h>
#include <rt/ray.h>

namespace rt {

Ray::Ray(const Point& o, const Vector& d)
{
    assert(d != Vector::rep(0.0f));
    this->o = o;
    this->d = d;
}

Point Ray::getPoint(float distance) const {
    /* TODO */ 
    Point res = o + (distance * d);
    return res;
}

}
