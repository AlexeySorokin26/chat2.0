cmake_minimum_required(VERSION 3.1)

project(Chat)

set(CMAKE_CXX_STANDARD 11)
set(USER_SRC User.cpp User.h)
set(MESSAGE_SRC Message.cpp Message.h)
set(SERVER_SRC Server.cpp Server.h)
set(UTILIY_SRC Utility.cpp Utility.h)

#file(GLOB headers *.h)

add_library(UserLib ${USER_SRC})
add_library(MessageLib ${MESSAGE_SRC})
add_library(ServerLib ${SERVER_SRC})
add_library(UtilityLib ${UTILIY_SRC})

add_executable(Chat Chat.cpp)
target_link_libraries(Chat UserLib MessageLib ServerLib UtilityLib)

