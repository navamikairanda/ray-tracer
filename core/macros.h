#ifndef CG1RAYTRACER_MACROS_HEADER
#define CG1RAYTRACER_MACROS_HEADER



#ifdef _MSC_VER
#define ALIGN(n) __declspec(align(n))
#define THREADLOCAL __declspec(thread)
#else
#define ALIGN(n) __attribute__((aligned(n)))
#define THREADLOCAL __thread
#endif

#define EPSILON 0.0000001f
#endif