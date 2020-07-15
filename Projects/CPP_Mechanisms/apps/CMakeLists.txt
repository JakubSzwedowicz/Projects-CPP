add_executable(app main.cpp Global_Functions.hpp)

target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE String)
target_link_libraries(app PRIVATE Block)
target_link_libraries(app PRIVATE Temp)
target_link_libraries(app PRIVATE DList)

set(INCLUDES_DIR
        ${INHERITANCE_INCLUDES_DIR}
        ${TEMPLATES_INCLUDES_DIR}
        ${SMART_POINTERS_INCLUDES_DIR}
        ${DATA_STRUCTURES_INCLUDES_DIR}
        )

target_include_directories(app PRIVATE ${INCLUDES_DIR})
