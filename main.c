// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "actions/action.h"
#include "commands/command_parsing.h"
#include "update_triggers.h"
#include "update_actions.h"
#include "update_commands.h"
#include "housekeeping.h"

#define TESTS

#ifdef TESTS
#include "tests/tests.h"
#endif

void main_task() {

    update_triggers();  // smth is done - hardware interop needed
    update_actions();   // todo
    housekeeping();     // todo

    // Разгребаем очередь входных команд из последовательного порта
    // возможно лучше пусть обработаем все настройки, а потом их поломаем
    // хотя по факту разницы не будет
    update_commands();
    // update_gsm();
}

int main()
{
#ifdef TESTS
    run_tests();
#else
    main_task();
#endif
    return 0;
}
