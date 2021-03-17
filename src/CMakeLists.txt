cmake_minimum_required(VERSION 3.12)

project(Chat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

set(USER_SRC User.cpp User.h)
set(MESSAGE_SRC Message.cpp Message.h)
set(SERVER_SRC Server.cpp Server.h)
set(UTILIY_SRC Utility.cpp Utility.h)

#file(GLOB headers *.h)

find_package(Boost REQUIRED COMPONENTS filesystem iostreams system regex chrono timer program_options unit_test_framework)

add_library(UserLib ${USER_SRC})
add_library(MessageLib ${MESSAGE_SRC})
add_library(ServerLib ${SERVER_SRC})
add_library(UtilityLib ${UTILIY_SRC})

if(Boost_FOUND)
	message(STATUS "found boost")	
	include_directories(${Boost_INCLUDE_DIRS})
	add_executable(Chat Chat.cpp)
	target_link_libraries(Chat UserLib MessageLib ServerLib UtilityLib ${Boost_LIBRARIES})
endif()

