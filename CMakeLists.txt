cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)

project(mlbfgs VERSION 0.0.2 LANGUAGES C)

# Initialize some default paths
include(GNUInstallDirs)
include(ExternalProject)

ExternalProject_Add(liblbfgs
  GIT_REPOSITORY https://github.com/chokkan/liblbfgs
  GIT_TAG master
  UPDATE_COMMAND ""
  INSTALL_COMMAND ""

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/liblbfgs"
  CMAKE_ARGS -DLBFGS_USE_DOUBLE=1 -DLBFGS_USE_SSE=1 -DLBFGS_BUILD_SHARED_LIBS=1 -DLBFGS_BUILD_EXAMPLES=0
  
  TEST_COMMAND ""
)

find_package(Matlab)
matlab_add_mex(NAME mlbfgs SRC src/mlbfgs.c)

add_dependencies(mlbfgs liblbfgs)
include_directories(liblbfgs/include)
target_include_directories(mlbfgs PUBLIC
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)



# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)

