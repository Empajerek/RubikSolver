cmake_minimum_required(VERSION 3.28.0)
project(Rubik'sSolver VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()

add_subdirectory(FibonacciQueue)

add_executable(RubiksSolver main.cpp)
target_link_libraries(RubiksSolver PRIVATE FibonacciQueue)

add_executable(FibonacciQueueTests ../tests/fibonacci_queue_tests.cpp)
target_link_libraries(FibonacciQueueTests FibonacciQueue)

add_test(NAME FibonacciQueueTests COMMAND FibonacciQueueTests)
