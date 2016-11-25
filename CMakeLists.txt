cmake_minimum_required (VERSION 3.5)

# Using experimental C++ features, including c++14 and c++17.
#set(CMAKE_CXX_FLAGS "-std=c++1z")
set(CMAKE_CXX_FLAGS "-std=c++14")

project(zenfabric)

# Don't build in this directory; do something like this instead:
# mkdir ../zen-fabric-build
# cd ../zen-fabric-build
# cmake ../zen-fabric
# make
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

find_package(Boost REQUIRED unit_test_framework)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(SOURCES
    lib/Container.cpp
    lib/SpacesConnection.cpp
    lib/ZeroReactor.cpp
)

set(HEADERS
    include/Zen/Fabric/blockingconcurrentqueue.hpp
    include/Zen/Fabric/concurrentqueue.hpp
    include/Zen/Fabric/Container.hpp
    include/Zen/Fabric/SpacesConnection.hpp
    include/Zen/Fabric/ZeroReactor.hpp
)

add_definitions(-DZEN_FABRIC_EXPORTS)

add_library(zen-fabric ${SOURCES})

install(TARGETS zen-fabric DESTINATION /usr/local/lib)
install(DIRECTORY include DESTINATION /usr/local)
