// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "action.h"
#include "../utils/staticvector/staticvector.h"
#include <stddef.h>
#include <string.h>

static action_t actions[ActionCapacity] = {};
static staticvector_t vector = {};

void initActions() {
    initVector(&vector, &actions, sizeof(action_t), ActionCapacity);
}

int getActionssSize() {
    return getVectorSize(&vector);
}

int getActionssCapacity() {
    return getVectorCapacity(&vector);
}

action_t* getAction(int index) {
    return getVectorItem(&vector, index);
}

action_t* addAction() {
    return addVectorItem(&vector);
}

void removeAction(int index) {
    removeVectorItem(&vector, index);
}

void clearActions() {
    clearVector(&vector);
}
