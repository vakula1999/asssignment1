cmake_minimum_required (VERSION 2.6)

#https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
#https://github.com/google/googletest/blob/master/googletest/docs/primer.md

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(INC_LOGIC 
../../source/FourBitAdder/intern/AbstractGate.h
../../source/FourBitAdder/intern/LogicGates.h
../../source/FourBitAdder/intern/HalfAdder.h
../../source/FourBitAdder/intern/FullAdder.h
../../source/FourBitAdder/FourBitAdder.h
)

set(SRC_LOGIC 
./GTestLogicGates.cpp
../../source/FourBitAdder/intern/AbstractGate.cpp
../../source/FourBitAdder/intern/LogicGates.cpp
)

add_executable(LogicGatesGTests_gtests ${SRC_LOGIC} ${INC_LOGIC})
target_link_libraries(LogicGatesGTests_gtests proj1_FourBitAdder ${GTEST_LIBRARIES} pthread)

# add cmake script for other unittests
# HalfAdder test files
set(SRC_HALFADDER 
    ./GTestHalfAdder.cpp
    ../../source/FourBitAdder/intern/AbstractGate.cpp
    ../../source/FourBitAdder/intern/LogicGates.cpp
    ../../source/FourBitAdder/intern/HalfAdder.cpp
)

add_executable(HalfAdderGTests_gtests ${SRC_HALFADDER} ${INC_LOGIC})
target_link_libraries(HalfAdderGTests_gtests ${GTEST_LIBRARIES} pthread)

# FullAdder test files
set(SRC_FULLADDER 
    ./GTestFullAdder.cpp
    ../../source/FourBitAdder/intern/AbstractGate.cpp
    ../../source/FourBitAdder/intern/LogicGates.cpp
    ../../source/FourBitAdder/intern/HalfAdder.cpp
    ../../source/FourBitAdder/intern/FullAdder.cpp
)

add_executable(FullAdderGTests_gtests ${SRC_FULLADDER} ${INC_LOGIC})
target_link_libraries(FullAdderGTests_gtests ${GTEST_LIBRARIES} pthread)

# FourBitAdder test files
set(SRC_FOURBITADDER 
    ./GTestFourBitAdder.cpp
    ../../source/FourBitAdder/intern/AbstractGate.cpp
    ../../source/FourBitAdder/intern/LogicGates.cpp
    ../../source/FourBitAdder/intern/HalfAdder.cpp
    ../../source/FourBitAdder/intern/FullAdder.cpp
    ../../source/FourBitAdder/intern/FourBitAdder.cpp
)

add_executable(FourBitAdderGTests_gtests ${SRC_FOURBITADDER} ${INC_LOGIC})
target_link_libraries(FourBitAdderGTests_gtests ${GTEST_LIBRARIES} pthread)