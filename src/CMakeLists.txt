add_executable(${PROJECT_NAME}
    hw.cpp
    logicgame.cpp  
    managergame.cpp  
    parsing.cpp  
    scores.cpp 
)

message("!!!(src) CMAKE_SOURCE_DIR >> " ${CMAKE_SOURCE_DIR})

# add include
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# add lib
target_link_libraries(${PROJECT_NAME}
    wr_file
)