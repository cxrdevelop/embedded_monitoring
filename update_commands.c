// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "update_commands.h"
#include "commands/commands.h"
#include "commands/command_parsing.h"

#include <string.h>

// TODO
static command_t* getNextCommand() {
    // implementation required!!!
    return NULL;
}
//

void update_commands() {
    command_t *cmd = getNextCommand();

    while (cmd) {
        int res = parse_command(cmd);
        if (res < 0) {
            // Some error
        }
        cmd = getNextCommand();
    }
}
