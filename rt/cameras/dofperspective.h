#ifndef CG1RAYTRACER_CAMERAS_DOFPERSPECTIVE_HEADER
#define CG1RAYTRACER_CAMERAS_DOFPERSPECTIVE_HEADER

#include <rt/cameras/camera.h>

namespace rt {

class Point;
class Vector;

class DOFPerspectiveCamera : public Camera {
public:
    DOFPerspectiveCamera(
        const Point& center,
        const Vector& forward,
        const Vector& up,
        float verticalOpeningAngle,
        float horizonalOpeningAngle,
        float focalDistance,
        float apertureRadius,
        float time0=0.f,
        float time1=0.f
    );

    virtual Ray getPrimaryRay(float x, float y) const;

private:
    Point center;
    Vector forward, up;
    float verticalOpeningAngle;
    float horizontalOpeningAngle;
    float focalDistance, apertureRadius;

    Vector spanX, spanY;
    float time0, time1;
};

}

#endif