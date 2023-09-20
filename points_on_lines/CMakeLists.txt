cmake_minimum_required(VERSION 3.0.0)
project(points_on_lines VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(points_on_lines main.cpp geom_primitives.h input_provider/input_provider.h input_provider/input_provider.cpp problem_solver/problem_solver.h  problem_solver/problem_solver.cpp output_provider/output_provider.h output_provider/output_provider.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
