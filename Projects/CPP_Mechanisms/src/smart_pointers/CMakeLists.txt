set(SMART_POINTERS_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/smart_pointers/)

add_library(Temp Temp.cpp ${SMART_POINTERS_INCLUDES_DIR}/Temp.hpp)

target_include_directories(Temp PUBLIC ${SMART_POINTERS_INCLUDES_DIR}/)

target_compile_features(Temp PUBLIC cxx_std_11)