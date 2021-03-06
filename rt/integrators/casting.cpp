#include <rt/integrators/casting.h>
#include <rt/world.h>

namespace rt {

RGBColor RayCastingIntegrator::getRadiance(const Ray& ray) const {
    /* TODO */ 
    Intersection intersection = world->scene->intersect(ray);
    if(intersection){
        float value = -1.0f * dot(ray.d, intersection.normal()); 
        RGBColor grayValue = RGBColor::rep(value);
        return grayValue;
    }
    else
        return RGBColor::rep(0.0f);
    
}

}
