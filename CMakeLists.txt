cmake_minimum_required(VERSION 3.9)
project(ImageLib VERSION 2.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_GENERATOR_PLATFORM x64)
#默认vscode生成Release,Debug需手动更改下面字段为Debug
set(CMAKE_BUILD_TYPE "Release")
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /we4013 /we4431 /we4133 /we4716 /we6244 /we6246 /we4457 /we4456 /we4172 /we4700 /we4477 /we4018 /we4047")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /we4013 /we4431 /we4133 /we4716 /we6244 /we6246 /we4457 /we4456 /we4172 /we4700 /we4477 /we4018 /we4047")
endif()


include_directories(${CMAKE_SOURCE_DIR}/include/)

if(AUTO_EXPOSURE)
#全局添加宏
add_definitions(-D_AUTO_EXPOSURE)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/color_correction/ AUTO_EXPOSURE_SRC)
endif()

set(SRC_FILES ${AUTO_EXPOSURE_SRC})
#SHARED/STATIC
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})
#单独添加宏
# target_compile_definitions(${PROJECT_NAME} PRIVATE DBUILDING_DLL)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/)

if(AUTO_EXPOSURE)
aux_source_directory(${CMAKE_SOURCE_DIR}/Demo/ DEMO_SRC)
add_executable(Demo ${DEMO_SRC} )
target_link_libraries(Demo ImageLib)
endif()
