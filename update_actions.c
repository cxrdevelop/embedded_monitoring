// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "update_actions.h"

#include "actions/action.h"
#include "triggers/triggers.h"

#include <stddef.h>

void update_actions() {
    for (int i = 0; i < getActionssSize(); ++i) {

        action_t *action = getAction(i);
        if (action == NULL) continue;

        int triggerIndex = action->triggerIndex;
        if (triggerIndex >= getTriggersSize()) continue;

        trigger_t *trigger = getTrigger(triggerIndex);
        if (trigger == NULL) continue;

        switch (action->actionType) {
        case ActionTriggerType_Off:
        case ActionTriggerType_On:
            // These two are probably useless and should be deleted
            break;

        case ActionTriggerType_Rise:
            // set
            if (trigger->status == TriggerStatus_On && trigger->prevStatus == TriggerStatus_Off) {
                action->status = ActionStatus_Active;
            }
            // reset
            if (trigger->status == TriggerStatus_Off && trigger->prevStatus == TriggerStatus_On) {
                action->status = ActionStatus_Inactive;
            }
            break;

        case ActionTriggerType_Fall:
            // set
            if (trigger->status == TriggerStatus_Off && trigger->prevStatus == TriggerStatus_On) {
                action->status = ActionStatus_Active;
            }
            // reset
            if (trigger->status == TriggerStatus_On && trigger->prevStatus == TriggerStatus_Off) {
                action->status = ActionStatus_Inactive;
            }
            break;
        }

        trigger->prevStatus = trigger->status;
    }
}
