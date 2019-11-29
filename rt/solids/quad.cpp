#include <rt/solids/quad.h>

namespace rt {

Quad::Quad(const Point& origin, const Vector& span1, const Vector& span2, CoordMapper* texMapper, Material* material)
{
    /* TODO */
    this->span1 = span1;
    this->span2 = span2;
    this->v1 = origin;
    this->v2 = origin + span1;
    this->v3 = origin + span2;
    this->v4 = origin + span1 + span2;
    this->t1 = new Triangle(v1, v2, v3, nullptr, nullptr);
    this->t2 = new Triangle(v3, v2, v4, nullptr, nullptr);
    this->material = material;
}

BBox Quad::getBounds() const {
    /* TODO */
    BBox b1 = t1->getBounds();
    BBox b2 = t2->getBounds();
    b1.extend(b2);
    return b1;
}

Intersection Quad::intersect(const Ray& ray, float previousBestDistance) const {
    /* TODO */ 
    Intersection i1 = t1->intersect(ray, previousBestDistance);
    if(i1)
        return i1;
    else{
        Intersection i2 = t2->intersect(ray, previousBestDistance);
        return i2;
    }
}

Solid::Sample Quad::sample() const {
    /* TODO */ NOT_IMPLEMENTED;
}

float Quad::getArea() const {
    /* TODO */ 
    return t1->getArea() + t2->getArea();
}

}
