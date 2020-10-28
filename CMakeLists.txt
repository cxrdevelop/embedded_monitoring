cmake_minimum_required(VERSION 3.5)

project(gas_boil_queue LANGUAGES C)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_C_STANDARD 11)

set(SOURCE_EXE
    main.c
    commands/command_parsing.c
    commands/command_parsing.h
    triggers/triggers.h
    triggers/triggers.c
    actions/action.c
    actions/action.h
    encoders/encoders.c
    encoders/encoders.h
    utils/staticvector/staticvector.c
    utils/staticvector/staticvector.h
    commands/commands.h
    update_triggers.c
    update_triggers.h
    tests/tests.c
    tests/tests.h
    housekeeping.c
    housekeeping.h
    update_actions.c
    update_actions.h
    update_commands.c
    update_commands.h)

add_executable(gas_boil_queue ${SOURCE_EXE})	# Создает исполняемый файл с именем main

set_property(TARGET gas_boil_queue PROPERTY C_STANDARD 11)
target_compile_options(gas_boil_queue PRIVATE -Werror -Wall -Wextra)

