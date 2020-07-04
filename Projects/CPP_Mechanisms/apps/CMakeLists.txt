add_executable(app main.cpp Global_Functions.hpp)

target_compile_features(app PRIVATE cxx_std_11)

target_link_libraries(app PRIVATE String)
#target_link_libraries(app PRIVATE Square)
#target_link_libraries(app PRIVATE Rectangle)
target_link_libraries(app PRIVATE Block)
target_link_libraries(app PRIVATE Temp)
#target_link_libraries(app PRIVATE People)
target_link_libraries(app PRIVATE DList)

set(INCLUDES_DIR
#        ${PROJECT_SOURCE_DIR}/inc/inheritance/
#        ${PROJECT_SOURCE_DIR}/inc/smart_pointers/
#        ${PROJECT_SOURCE_DIR}/inc/templates/
        ${INHERITANCE_INCLUDES_DIR}
        ${TEMPLATES_INCLUDES_DIR}
        ${SMART_POINTERS_INCLUDES_DIR}
        ${DATA_STRUCTURES_INCLUDES_DIR}
#        ${PROJECT_SOURCE_DIR}/inc/data_structures/
        )

#target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/inc/inheritance/)
#target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/inc/templates/)
target_include_directories(app PRIVATE ${INCLUDES_DIR})
