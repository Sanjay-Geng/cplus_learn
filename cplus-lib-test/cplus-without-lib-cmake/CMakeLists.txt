cmake_minimum_required(VERSION 3.8)
project(lib-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # 编译选项

set(ROOT_DIR ${PROJECT_SOURCE_DIR})   # 定义根目录变量
set(name lib-test)

include_directories(
  ${ROOT_DIR}/include
)
# file(GLOB_RECURSE SERVER_SRC src/*.cpp include/*.cpp)
aux_source_directory(src SERVER_SRC)
aux_source_directory(include SERVER_SRC)
# message("files: ${SERVER_SRC}")
add_executable(${name} ${SERVER_SRC})

set_target_properties(${name} PROPERTIES
  FOLDER "mylib"
  ARCHIVE_OUTPUT_DIRECTORY ${ROOT_DIR}/bin
  RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin
  LIBRARY_OUTPUT_DIRECTORY ${ROOT_DIR}/bin
)
