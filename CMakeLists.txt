cmake_minimum_required(VERSION 3.11 )
project(MultithreadingCVFramework)

# 检测政策更新
if(POLICY CMP0146)
    cmake_policy(SET CMP0146 OLD)
endif()

find_package(OpenCV REQUIRED)
set(set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_FLAGS "-std=c++11"))

include_directories(
        ./
        Framework/
        TestClass/
        ${OpenCV_INCLUDE_DIRS}
)

add_executable(
        ${PROJECT_NAME}
        main.cpp
        Framework/MulThrCV.cpp
        TestClass/TestClass.cpp
        Framework/Framework.h
)

target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}  ${OpenCV_LIBS})