#include <rt/integrators/recraytrace.h>
#include <rt/intersection.h>
#include <rt/lights/light.h>
#include <rt/world.h>
#include <rt/solids/solid.h>
#include <rt/materials/material.h>
#include <rt/coordmappers/coordmapper.h>
namespace rt {

RGBColor RecursiveRayTracingIntegrator::getRadiance(const Ray& ray) const {
    /* TODO */
    int maxDepth = 6;
    return getRecursiveRadiance(ray, maxDepth);
}

RGBColor RecursiveRayTracingIntegrator::getRecursiveRadiance(const Ray& ray, int& depth) const {
    /* TODO */
    RGBColor totalRadiance = RGBColor::rep(0.0f);

    depth--;
    if(depth == 0 )
        return totalRadiance;

    RGBColor emission, reflectance, intensity;
    Point texPoint;
    Intersection intersection = world->scene->intersect(ray);

    if(intersection){
        texPoint = intersection.solid->texMapper->getCoords(intersection);
        Material::Sampling sampling = intersection.solid->material->useSampling();
    
        if(sampling == Material::SAMPLING_NOT_NEEDED || sampling == Material::SAMPLING_SECONDARY){
            emission = intersection.solid->material->getEmission(texPoint, intersection.normal(), -ray.d);
            totalRadiance = totalRadiance + emission;
            
            for(int i = 0; i < world->light.size(); i++){
                LightHit lightHit = world->light[i]->getLightHit(intersection.hitPoint());
                //Shift the ray origin towards it's direction by an offset, to avoid self intersection
                Ray shadowRay(intersection.hitPoint() + intersection.normal() * offset, lightHit.direction, intersection.ray.time);
                if(dot(intersection.normal(), shadowRay.d) > 0.0f){
                    Intersection shaIntersec = world->scene->intersect(shadowRay, lightHit.distance);
                    //If no intersection of shadow ray, or the intersection distance greater than distance to light source, update radiance
                    if(!shaIntersec){
                        intensity = world->light[i]->getIntensity(lightHit);
                        reflectance = intersection.solid->material->getReflectance(texPoint, intersection.normal(),  -ray.d, -shadowRay.d);
                        totalRadiance = totalRadiance + intensity * reflectance;
                    }
                }
            }
        }
        
        if(sampling == Material::SAMPLING_ALL || sampling == Material::SAMPLING_SECONDARY){
            Material::SampleReflectance sampleReflectance = intersection.solid->material->getSampleReflectance(texPoint, intersection.normal(),  -ray.d);
            //Offset in the direction of sampleReflectance, as this would handle all cases 
            //refraction and reflection when entering or leaving the surface
            Ray secondaryRay(intersection.hitPoint() + sampleReflectance.direction * offset, sampleReflectance.direction, intersection.ray.time);
            RGBColor radiance = getRecursiveRadiance(secondaryRay, depth);
            totalRadiance =  totalRadiance + sampleReflectance.reflectance * radiance; 
        }
    } 
    return totalRadiance;
}

}