cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(FractalStudio
    src/App.cpp
    src/AppState.cpp
    src/Projection.cpp
    src/ProjectionSource.cpp
    src/State.cpp)

target_compile_features(FractalStudio PRIVATE cxx_std_17)
target_link_libraries(FractalStudio PRIVATE SFML::Graphics)

if(WIN32)
    set_target_properties(FractalStudio PROPERTIES WIN32_EXECUTABLE TRUE)
endif()