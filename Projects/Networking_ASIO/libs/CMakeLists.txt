set(ASIO_INCLUDES ${PROJECT_SOURCE_DIR}/libs/asio-1.18.1/include/)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)   # To prefer use of pthread library on system with multiple thread libraries
set(THREADS_PREFER_PTHREAD_FLAG TRUE)   # To add the -pthread flag during compilation and linking

find_package(Threads REQUIRED)

add_library(ASIO INTERFACE)

target_compile_options(ASIO INTERFACE -DASIO_STANDALONE)

target_include_directories(ASIO INTERFACE ${ASIO_INCLUDES})

target_link_libraries(ASIO INTERFACE Threads::Threads)