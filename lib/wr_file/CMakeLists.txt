# Собираем статическую библиотеку
add_library(wr_file 
    STATIC
    src/wr_file.cpp
)

# Подключаем заголовочные файлы
target_include_directories(wr_file
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)