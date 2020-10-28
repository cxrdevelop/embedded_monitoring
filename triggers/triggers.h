#ifndef TRIGGERS_H
#define TRIGGERS_H

enum TriggerType {
    TriggerTypeInput,
    TriggerTypeTemperature,
    TriggerTypeSystem
};

enum SystemMessagesType {
    SystemMessageStartUp,
    SystemMessagePowerOff,
    SystemMessagePowerOn,
    SystemMessageIncomingCall
};

enum TriggerStatus {
    TriggerStatus_Off,
    TriggerStatus_On
};

typedef struct {
    enum TriggerType type;
    union {
        int inputReverse;
        int temperature;
        enum SystemMessagesType systemType;
    } settings;
    union {
        int encoderIndex;
        int inputIndex;
    } source;

    int status; // 0 - Off, 1 - On
    int prevStatus;
} trigger_t;

#define TriggerCapacity 256

void initTriggers();
int getTriggersSize();
int getTriggersCapacity();
trigger_t* getTrigger(int index);
trigger_t* addTrigger();
void removeTrigger(int index);
void clearTriggers();

#endif // TRIGGERS_H
