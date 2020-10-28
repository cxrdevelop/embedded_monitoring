// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "tests.h"
#include "../utils/staticvector/staticvector.h"
#include "../actions/action.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>

void test_settings() {
    action_t settings[256];
    staticvector_t settingsVector;
    initVector(&settingsVector, &settings, sizeof (action_t), 256);

    // Run some tests
    assert(getVectorItem(&settingsVector, 0) == NULL);
    assert(getVectorItem(&settingsVector, -1) == NULL);
    assert(getVectorSize(&settingsVector) == 0);

    removeVectorItem(&settingsVector,0);
    assert(getVectorSize(&settingsVector) == 0);

    removeVectorItem(&settingsVector,1);
    assert(getVectorSize(&settingsVector) == 0);

    assert(addVectorItem(&settingsVector) != NULL);
    assert(getVectorSize(&settingsVector) == 1);

    assert(addVectorItem(&settingsVector) != NULL);
    assert(getVectorSize(&settingsVector) == 2);

    clearVector(&settingsVector);
    assert(getVectorSize(&settingsVector) == 0);

    for (int i = 0; i < getVectorCapacity(&settingsVector); ++i) {
        action_t *s = addVectorItem(&settingsVector);
        s->type = i;
    }

    assert(getVectorSize(&settingsVector) == getVectorCapacity(&settingsVector));
    assert(addVectorItem(&settingsVector) == NULL);

    removeVectorItem(&settingsVector,0);
    assert(addVectorItem(&settingsVector) != NULL);
    assert(addVectorItem(&settingsVector) == NULL);

    // check remove
    clearVector(&settingsVector);
    // fill 0,1,2,3,...,255
    for (int i = 0; i < getVectorCapacity(&settingsVector); ++i) {
        action_t *s = addVectorItem(&settingsVector);
        s->type = i;
    }
    // remove every even
    for (int i = 0; i < getVectorCapacity(&settingsVector)/2; ++i) {
        removeVectorItem(&settingsVector,i);
    }

    // check the sequence
    // it should be 1,3,5,...,127
    assert(getVectorSize(&settingsVector) == getVectorCapacity(&settingsVector)/2);
    for (int i = 0; i < getVectorCapacity(&settingsVector)/2; ++i) {
        int type = ((action_t*)getVectorItem(&settingsVector,i))->type;
        assert(type == i*2 + 1);
    }
    clearVector(&settingsVector);
}

void run_tests() {
    test_settings();
}
