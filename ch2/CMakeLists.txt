cmake_minimum_required(VERSION 3.10)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(Tinylang)
  find_package(LLVM REQUIRED HINTS "${LLVM_CMAKE_PATH}")
  list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})
  message("LLVM_DIR=${LLVM_DIR}")

  include(AddLLVM)
  include(HandleLLVMOptions)

  include_directories("${LLVM_BINARY_DIR}/include" "${LLVM_INCLUDE_DIR}")
  link_directories("${LLVM_LIBRARY_DIR}")
  set(TINYLANG BUILT STANDALONE 1)  #表示这个项目是独立构建的
endif()

# 添加自己的cmake模块
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
  
# 用来控制tinylang的版本
# configure_file 会把版本号写入文件
set(TINYLANG_VERSION_STRING "0.1")
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/tinylang/Basic/Version.inc.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/tinylang/Basic/Version.inc)
# 添加cmake模块
include(AddTinylang)

# 将我们自己的include目录添加到搜索路径的开头
include_directories(BEFORE
  ${CMAKE_CURRENT_BINARY_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(lib)
add_subdirectory(tools)

message("CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
message("LLVM_DIR=${LLVM_DIR}")
message("LLVM_INCLUDE_DIR=${LLVM_INCLUDE_DIR}")
message("LLVM_LINK_DIR=${LLVM_LIBRARY_DIR}")


