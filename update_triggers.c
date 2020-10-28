// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "update_triggers.h"
#include "triggers/triggers.h"

#include <stddef.h>

// TODO!!!
static int getTemperature(int index) {
    (void) index;
    return 0;
}

static int getInput(int index) {
    (void) index;
    return 0;
}

static int isExtPowerOn() {
    return 0;
}
//

static void parseTemperatureTrigger(trigger_t *trigger) {
    int encoderIndex = trigger->source.encoderIndex;
    int temperature = getTemperature(encoderIndex);

    if (temperature > trigger->settings.temperature) {
        trigger->status = TriggerStatus_On;
    } else {
        trigger->status = TriggerStatus_Off;
    }
}

static void parseInputTrigger(trigger_t *trigger) {
    int inputIndex = trigger->source.inputIndex;
    int input = getInput(inputIndex);
    if (input) {
        trigger->status = trigger->settings.inputReverse ? TriggerStatus_Off : TriggerStatus_On;
    } else {
        trigger->status = trigger->settings.inputReverse ? TriggerStatus_On : TriggerStatus_Off;
    }
}

static void parseSystemTrigger(trigger_t *trigger) {
    switch (trigger->settings.systemType) {
    case SystemMessageStartUp:
        trigger->status = TriggerStatus_On;
        break;

    case SystemMessagePowerOff:
        trigger->status = isExtPowerOn() ? TriggerStatus_Off : TriggerStatus_On;
        break;

    case SystemMessagePowerOn:
        trigger->status = isExtPowerOn() ? TriggerStatus_On : TriggerStatus_Off;
        break;

    case SystemMessageIncomingCall:
        break;

    default:
        break;
    }
}

void update_triggers() {
    for (int i = 0; i < getTriggersSize(); ++i) {
        trigger_t *trigger = getTrigger(i);
        if(trigger == NULL) continue;

        switch (trigger->type) {
        case TriggerTypeInput:
            parseInputTrigger(trigger);
            break;

        case TriggerTypeTemperature:
            parseTemperatureTrigger(trigger);
            break;

        case TriggerTypeSystem:
            parseSystemTrigger(trigger);
            break;

        default:
            break;
        }
    }
}
