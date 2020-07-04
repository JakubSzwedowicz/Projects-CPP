set(DATA_STRUCTURES_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/inc/data_structures/)

add_library(DList Double_Linked_List.cpp ${DATA_STRUCTURES_INCLUDES_DIR}/Double_Linked_List.hpp)
add_library(People People.cpp ${DATA_STRUCTURES_INCLUDES_DIR}/People.hpp)
add_library(Node Node.cpp ${DATA_STRUCTURES_INCLUDES_DIR}/Node.hpp)

target_link_libraries(DList PUBLIC Node People)
target_include_directories(DList PUBLIC ${DATA_STRUCTURES_INCLUDES_DIR})
target_include_directories(Node PUBLIC ${DATA_STRUCTURES_INCLUDES_DIR})
target_include_directories(People PUBLIC ${DATA_STRUCTURES_INCLUDES_DIR})

target_compile_features(DList PUBLIC cxx_std_11)
target_compile_features(Node PUBLIC cxx_std_11)
target_compile_features(People PUBLIC cxx_std_11)