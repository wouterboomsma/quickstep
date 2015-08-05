# Set parameters for different build types
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
#set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -ggdb")

# Set default make type
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE "Release" )
endif()

