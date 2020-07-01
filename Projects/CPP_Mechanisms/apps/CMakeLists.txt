add_executable(app main.cpp Global_Functions.hpp)

target_compile_features(app PRIVATE cxx_std_11)

target_link_libraries(app PRIVATE String)
target_link_libraries(app PRIVATE Square)
target_link_libraries(app PRIVATE Rectangle)
target_link_libraries(app PRIVATE Block)

set(INCLUDES_DIR
        ${PROJECT_SOURCE_DIR}/inc/inheritance/
        ${PROJECT_SOURCE_DIR}/inc/templates/
        )

#target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/inc/inheritance/)
#target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/inc/templates/)
target_include_directories(app PRIVATE ${INCLUDES_DIR})
