#ifndef ACTION_H
#define ACTION_H

typedef enum {
    ActionType_None,
    ActionType_SMS
} ActionType;

typedef enum {
    ActionTriggerType_On,
    ActionTriggerType_Off,
    ActionTriggerType_Rise,
    ActionTriggerType_Fall
} ActionTriggerType;

typedef enum {
    ActionStatus_Inactive,
    ActionStatus_Active
} ActionStatus;

typedef struct {
    ActionType type;
    ActionTriggerType actionType;
    int triggerIndex;
    char message[255];

    int status;
} action_t;

#define ActionCapacity 32

void initActions();
int getActionssSize();
int getActionssCapacity();
action_t* getAction(int index);
action_t* addAction();
void removeAction(int index);
void clearActions();

#endif // ACTION_H
