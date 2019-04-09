cmake_minimum_required(VERSION 3.5)
project(gl-car)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(main ./src/main.cpp)

target_link_libraries(main
	${GLUT_LIBRARIES}
	${OPENGL_LIBRARIES}
)

set(CMAKE_BUILD_TYPE Release)