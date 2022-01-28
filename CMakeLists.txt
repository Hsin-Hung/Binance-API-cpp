cmake_minimum_required(VERSION 3.20)

# set the project name and version
project(BinanceAPI)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "system: ${CMAKE_SYSTEM}")
message(STATUS "build_type: ${CMAKE_BUILD_TYPE}")
message(STATUS "paths:")
message(STATUS " - ${PROJECT_SOURCE_DIR}")
message(STATUS " - ${CMAKE_INSTALL_PREFIX}")
message(STATUS " - ${CMAKE_SOURCE_DIR}")
message(STATUS " - ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS)
message(STATUS "compiler:")
message(STATUS " - ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - ${CMAKE_CXX_COMPILER}")
message(STATUS " - ${CMAKE_CXX_FLAGS}")
message(STATUS)
message(STATUS "cmake:")
message(STATUS " - ${CMAKE_VERSION}")
message(STATUS " - ${CMAKE_COMMAND}")
message(STATUS " - ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS " - ${CMAKE_GENERATOR}")
message(STATUS " - ${CMAKE_BUILD_TOOL}")
message(STATUS)

find_package(Boost 1.71.0 REQUIRED)

if(NOT Boost_FOUND)
  message(FATAL_ERROR "Boost not found")
endif()

find_package(OpenSSL REQUIRED)

if(NOT OPENSSL_FOUND)
  message(FATAL_ERROR "OpenSSL not found")
endif()

find_package(CURL REQUIRED)

if(NOT CURL_FOUND)
  message(FATAL_ERROR "Curl not found")
endif()

include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# include_directories(${Boost_INCLUDE_DIRS})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/binance/*.cpp)


add_executable(binanceAPI ${PROJECT_SOURCE_DIR}/src/main.cpp ${SRC_FILES})

target_include_directories(binanceAPI PRIVATE ${PROJECT_SOURCE_DIR}/src/binance ${Boost_INCLUDE_DIRS})
target_link_libraries(binanceAPI ${Boost_LIBRARIES} OpenSSL::SSL CURL::libcurl nlohmann_json::nlohmann_json)