// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "command_parsing.h"
#include "../triggers/triggers.h"
#include "../actions/action.h"
#include "../encoders/encoders.h"
#include <stddef.h>
#include <string.h>

static void sendAnswer(CommandType type, int ack, int dataSize, char *data) {
    command_t ans;
    ans.type = type;
    ans.ack = ack;
    ans.dataSize = dataSize;
    if (dataSize == 0 || data == NULL) return;
    memcpy(&ans.data, data, dataSize);
    // put in the out queue
}

// TODO
static int save() {
    return 1;
}

static int reset() {
    return 1;
}

static int factory() {
    return 1;
}
//

int parse_command(command_t *cmd) {
    switch (cmd->type) {

    // System
    case CommandType_GetVersion: {
        int version = 1;
        sendAnswer(cmd->type, 1, sizeof(int), (char*)&version);
        break;
    }

    case CommandType_Reset: {
        int res = reset();
        sendAnswer(cmd->type, res, 0, NULL);
        break;
    }

    case CommandType_Save: {
        int res = save();
        sendAnswer(cmd->type, res, 0, NULL);
        break;
    }

    case CommandType_Factory: {
        int res = factory();
        sendAnswer(cmd->type, res, 0, NULL);
        break;
    }

    // Triggers
    case CommandType_Trigger_GetSize: {
        int size = getTriggersSize();
        sendAnswer(cmd->type, 1, sizeof(int), (char*)&size);
        break;
    }

    case CommandType_Trigger_GetCapacity: {
        int size = getTriggersCapacity();
        sendAnswer(cmd->type, 1, sizeof(int), (char*)&size);
        break;
    }

    case CommandType_Trigger_Add: {
        // Adds trigger and initializes it
        trigger_t *trigger = addTrigger();
        if (cmd->dataSize != sizeof (trigger_t)) {
            sendAnswer(cmd->type, 0, 0, NULL); // error
        }
        memcpy(trigger, cmd->data, sizeof (trigger_t));        // init new trigger
        int index = getTriggersSize() - 1;
        sendAnswer(cmd->type, 1, sizeof (int), (char*)&index); // send back index
        break;
    }

    case CommandType_Trigger_Remove: {
        if (cmd->dataSize != sizeof (int)) {
            sendAnswer(cmd->type, 0, 0, NULL); // error
        }
        int index = 0;
        memcpy(&index, cmd->data, sizeof (int));
        removeTrigger(index);
        sendAnswer(cmd->type, 1, 0, NULL); // ack
        break;
    }

    case CommandType_Trigger_ClearAll: {
        clearTriggers();
        sendAnswer(cmd->type, 1, 0, NULL); // ack
        break;
    }

    case CommandType_Trigger_Get: {
        int index = 0;
        memcpy(&index, cmd->data, sizeof (int));
        trigger_t *trigger = getTrigger(index);
        if (trigger == NULL) {
            sendAnswer(cmd->type, 0, 0, NULL); // error
        }
        sendAnswer(cmd->type, 1, sizeof (trigger_t), (char*)trigger); // send it back
        break;
    }

    case CommandType_Trigger_Set: {
        int index = 0;
        memcpy(&index, cmd->data, sizeof (int));
        trigger_t *trigger = getTrigger(index);
        if (trigger == NULL) {
            sendAnswer(cmd->type, 0, 0, NULL);  // error
            break;
        }
        if (cmd->dataSize != sizeof (trigger_t)) {
            sendAnswer(cmd->type, 0, 0, NULL);  // error
            break;
        }
        memcpy(trigger, cmd->data, sizeof (trigger_t));
        sendAnswer(cmd->type, 1, 0, NULL);      // ack
        break;
    }

    default:
        return -1;
    }

    return 0;
}
