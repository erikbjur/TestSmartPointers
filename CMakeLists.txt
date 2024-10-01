cmake_minimum_required( VERSION 3.28.3 )

project(TestSmartPointers LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 20 )

set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( OutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE}" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OutputDir}/lib" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}" )

set(Sources_SmartPointers
  SmartPointersTest/src/Assembly.cpp
  SmartPointersTest/src/DataStorage.cpp
  SmartPointersTest/src/HasID.cpp
  SmartPointersTest/src/main.cpp
  SmartPointersTest/src/Part.cpp
  SmartPointersTest/src/Utility.cpp
)

add_executable( SmartPointersTest ${Sources_SmartPointers} )

target_include_directories( SmartPointersTest PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/SmartPointersTest/include
)

set(Sources_RawPointers
  RawPointersTest/src/Assembly.cpp
  RawPointersTest/src/DataStorage.cpp
  RawPointersTest/src/HasID.cpp
  RawPointersTest/src/main.cpp
  RawPointersTest/src/Part.cpp
  RawPointersTest/src/Utility.cpp
)

add_executable( RawPointersTest ${Sources_RawPointers} )

target_include_directories( RawPointersTest PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/RawPointersTest/include
)