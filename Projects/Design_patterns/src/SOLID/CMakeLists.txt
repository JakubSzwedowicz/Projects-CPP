set(SOLID_SOURCES
        Single_Responsibility_Principle.cpp
        Opened_closed_principle.cpp)
set(SOLID_INCLUDES_DIR "${PROJECT_SOURCE_DIR}/inc/SOLID/")

add_library(SOLID ${SOLID_SOURCES})

target_include_directories(SOLID PUBLIC ${SOLID_INCLUDES_DIR})
