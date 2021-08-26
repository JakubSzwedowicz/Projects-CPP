set(APP_SOURCES main.cpp)
set(LIBS SOLID)

add_executable(APP ${APP_SOURCES})
target_link_libraries(APP ${LIBS})

add_subdirectory(${LIBS})