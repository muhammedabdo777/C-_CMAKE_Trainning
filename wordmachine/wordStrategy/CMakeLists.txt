
message(STATUS "WordStrategy")


set(TARGET wordmachinestr)

add_executable(${TARGET})

target_include_directories(${TARGET} PRIVATE
						   ${CMAKE_CURRENT_SOURCE_DIR}
						   ${Boost_INCLUDE_DIRS}
)
target_sources(${TARGET}
			   PRIVATE 
			   ${CMAKE_CURRENT_SOURCE_DIR}/wordStrategy.cpp
			   ${CMAKE_CURRENT_SOURCE_DIR}/wordStrategy.cpp
			   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
				)
if(NOT Boost_FOUND)
	message(FETAL_ERROR "boost lib not found")
endif()
target_link_libraries(${TARGET} ${Boost_LIBRARIES})