set(APP_SOURCES main.cpp)

add_executable(APP ${APP_SOURCES})

target_compile_features(APP PRIVATE cxx_std_17)

target_link_libraries(APP PRIVATE SRC_LIBS)