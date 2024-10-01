cmake_minimum_required( VERSION 3.28.3 )

project(TestSmartPointers LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 20 )

set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( OutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE}" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OutputDir}/lib" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}" )

set(Sources
  src/Assembly.cpp
  src/DataStorage.cpp
  src/HasID.cpp
  src/main.cpp
  src/Part.cpp
  src/Utility.cpp
)

add_executable( ${PROJECT_NAME} ${Sources} )

target_include_directories( ${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)