#include <rt/solids/infiniteplane.h>

namespace rt {

InfinitePlane::InfinitePlane(const Point& origin, const Vector& normal, CoordMapper* texMapper, Material* material)
{
    this->origin = origin;
	this->normal = normal;
    /* TODO */
}

BBox InfinitePlane::getBounds() const {
    /* TODO */ NOT_IMPLEMENTED;
}

Intersection InfinitePlane::intersect(const Ray& ray, float previousBestDistance) const {
    /* TODO */ 
    float distance;
    Vector planeOrigin(origin.x, origin.y, origin.z);
    Vector rayOrigin(ray.o.x, ray.o.y, ray.o.z);

    distance = (dot(planeOrigin, normal) - dot(rayOrigin,normal))/dot(ray.d,normal);
	if ((distance >=0) && (distance < previousBestDistance)){
		Point p = ray.o + distance * ray.d;
		Intersection intersection(distance, ray, this, normal, p);
		return intersection;
    }
	else
		return Intersection::failure();
}

Solid::Sample InfinitePlane::sample() const {
    /* TODO */ NOT_IMPLEMENTED;
}

float InfinitePlane::getArea() const {
    /* TODO */ NOT_IMPLEMENTED;
}

}
