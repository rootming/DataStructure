PROJECT (calc[CXX])

SET(SRC_LIST main.cpp stack.h expr.cpp expr.h)
SET(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall")
#SET(CMAKE_CXX_FLAGS -g)
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV(CXXFLAGS) -Wall -g -ggdb -std=c++11")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV(CXXFLAGS) -Wall -std=c++11")

ADD_EXECUTABLE(calc ${SRC_LIST})


