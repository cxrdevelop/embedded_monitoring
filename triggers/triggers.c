// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "triggers.h"
#include "../utils/staticvector/staticvector.h"
#include <stddef.h>
#include <string.h>

static trigger_t triggers[TriggerCapacity] = {};
static staticvector_t vector = {};

void initTriggers() {
    initVector(&vector, &triggers, sizeof(trigger_t), TriggerCapacity);
}

int getTriggersSize() {
    return getVectorSize(&vector);
}

int getTriggersCapacity() {
    return getVectorCapacity(&vector);
}

trigger_t* getTrigger(int index) {
    return getVectorItem(&vector, index);
}

trigger_t* addTrigger() {
    return addVectorItem(&vector);
}

void removeTrigger(int index) {
    removeVectorItem(&vector, index);
}

void clearTriggers() {
    clearVector(&vector);
}
