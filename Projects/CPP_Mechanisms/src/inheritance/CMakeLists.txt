set(INHERITANCE_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/inheritance/)

add_library(Square Square.cpp ${INHERITANCE_INCLUDES_DIR}/Square.hpp)
add_library(Rectangle Rectangle.cpp ${INHERITANCE_INCLUDES_DIR}/Rectangle.hpp)
add_library(Block Block.cpp ${INHERITANCE_INCLUDES_DIR}/Block.hpp)

target_link_libraries(Block PUBLIC Square Rectangle)
target_include_directories(Square PUBLIC ${INHERITANCE_INCLUDES_DIR})
target_include_directories(Rectangle PUBLIC ${INHERITANCE_INCLUDES_DIR})
target_include_directories(Block PUBLIC ${INHERITANCE_INCLUDES_DIR})

target_compile_features(Block PUBLIC cxx_std_11)
target_compile_features(Square PUBLIC cxx_std_11)
target_compile_features(Rectangle PUBLIC cxx_std_11)