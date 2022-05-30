cmake_minimum_required(VERSION 3.22)

project(WORDMACHINE
        DESCRIPTION "c++ REMEMBER TASK"
        )
		
message(STATUS "3AL ALLAH ELTASAHEL")

set(CMAKE_CXX_STANDARD "14")
set(CXXFLAGS="$CFLAGS -Wall --format=binary -ggdb")

set(TARGET wordmachine)
find_package(Boost)

add_executable(${TARGET})

target_include_directories(${TARGET} PRIVATE
						   ${CMAKE_CURRENT_SOURCE_DIR}/inc/
						   ${Boost_INCLUDE_DIRS}
)
target_sources(${TARGET}
			   PRIVATE 
			   ${CMAKE_CURRENT_SOURCE_DIR}/src/operations.cpp
			   ${CMAKE_CURRENT_SOURCE_DIR}/src/wordmachine.cpp
			   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
				)
if(NOT Boost_FOUND)
	message(FETAL_ERROR "boost lib not found")
endif()
target_link_libraries(${TARGET} ${Boost_LIBRARIES})
				
add_subdirectory(wordStrategy)
