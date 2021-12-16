cmake_minimum_required(VERSION 3.16)
project(avs5)

add_executable(avs5 main.cpp workers/worker.cpp workers/worker.h needle.h workers/firstWorker.cpp workers/firstWorker.h workers/secondWorker.cpp workers/secondWorker.h workers/thirdWorker.cpp workers/thirdWorker.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(avs5 PRIVATE Threads::Threads)

set(CMAKE_CXX_STANDARD 17)
