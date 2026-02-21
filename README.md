# otus_basic_hm_third
Выполняем домашнее задание 3.

иерархия папок проекта

```
Variant 1

CMakeLists.txt
src/
    CMakelists.txt
    user_game.cpp
    hw.cpp  //main
include/
    user_game.h
lib/
    wr_file/
        CMakeLists.txt
        include/
            wr_file.h
        src/
            wr_file.cpp

----------------------
Variant 2

CMakeLists.txt
src/
    CMakelists.txt

    logicgame.cpp  
    managergame.cpp  
    parsing.cpp  
    scores.cpp

    hw.cpp  //main

include/
    logicgame.hpp  
    managergame.hpp  
    parsing.hpp  
    scores.hp

lib/
    wr_file/
        CMakeLists.txt
        include/
            wr_file.h
        src/
            wr_file.cpp
```
    

Работа над ошибками
1. Обратите внимание на класс User_game. У него много ортогональных зон ответственности: логика игры, парсинг строк, рекорды... Логику парсинга и хранения таблицы лидеров стоило выделить в отдельный класс.

2. Желательно добавить валидацию ошибок ввода. Сейчас ввод буквы вместо числа приведет к бесконечному циклу.

3. Похоже, что наличие числа в имени пользователя (`JohnODoe`) приведет к проблемам в set_high_scores_container.

Version 2
---------------
1. Новая логика проекта
Класс:
-  LogicGame логика (хранения имени рекорда и механика игры)             - completed
-  Parsing парсинг строк                                                 - completed
-  Scores таблица результатов (работа с файлом и массив рекордов)        - completed
-  ManagerGame - объединения всех классов общая работа...                - completed

2. Выполнить проверку на число при вводе.                                - completed
   
3. Добавить проверки, если следующее в строке идёт число, то это строчка.- completed

#. Фильтр на топ игроков и результатов;                                  - completed
---------------
К чему ещё не приступал:
2. Перезаписывать результат, если он лучше предыдущего, если его нет, то просто запись. - TODO