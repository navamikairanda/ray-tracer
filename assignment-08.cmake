cmake_minimum_required(VERSION 3.0)

set(MY_ADDITIONAL_SOURCES
    main/a_volume.cpp
    rt/integrators/volumetrace_a.h
    rt/integrators/volumetrace_a.cpp
    rt/integrators/volumetrace_b.h
    rt/integrators/volumetrace_b.cpp
    rt/integrators/volumetrace_c.h
    rt/integrators/volumetrace_c.cpp
    # Please add your source files here
)

set(ASSIGNMENT_SOURCES
    rt/primmod/bmap.cpp
    rt/primmod/bmap.h
    ${MY_ADDITIONAL_SOURCES}
    main/a_bump.cpp
)

file(COPY
    models/stones_bump.png
    models/stones_spec.png
    DESTINATION ${CMAKE_BINARY_DIR}/models
)
