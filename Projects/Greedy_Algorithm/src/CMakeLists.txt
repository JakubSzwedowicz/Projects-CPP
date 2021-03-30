add_library(MONEY_CHANGE Money_Change.cpp)

set(INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/)

target_include_directories(MONEY_CHANGE PUBLIC ${INCLUDES_DIR}/)

target_compile_features(MONEY_CHANGE PUBLIC cxx_std_14)
