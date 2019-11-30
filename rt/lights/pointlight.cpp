#include <rt/lights/pointlight.h>

namespace rt {

PointLight::PointLight(const Point& position, const RGBColor& intensity)
{
    /* TODO */
    this->position = position;
    this->intensity = intensity;
}

LightHit PointLight::getLightHit(const Point& p) const {
    /* TODO */
    LightHit lightHit;
    Vector hitPointToLight = position - p;
    lightHit.distance = hitPointToLight.length();
    lightHit.direction = hitPointToLight.normalize();
    lightHit.normal = Vector::rep(0.0f); //Normal for point light is irrelevant
    return lightHit;
}

RGBColor PointLight::getIntensity(const LightHit& irr) const {
    /* TODO */
    return intensity * (1.f / (irr.distance*irr.distance)); //4 pi term needed?
}

}