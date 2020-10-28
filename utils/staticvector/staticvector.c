// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "staticvector.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void initVector(staticvector_t *vector, void *buffer, int itemSize, int capacity) {
    vector->buffer = buffer;
    vector->capacity = capacity;
    vector->itemSize = itemSize;
}

int getVectorSize(staticvector_t *vector) {
    return vector->size;
}

int getVectorCapacity(staticvector_t *vector) {
    return vector->capacity;
}

void* getVectorItem(staticvector_t *vector, int index) {
    if (index >= vector->size) return NULL;
    if (index < 0) return NULL;
    return &vector->buffer[index * vector->itemSize];
}

void* addVectorItem(staticvector_t *vector) {
    if (vector->size == vector->capacity) return NULL;
    memset(&vector->buffer[vector->size * vector->itemSize], 0, vector->itemSize);
    ++vector->size;
    return &vector->buffer[(vector->size-1) * vector->itemSize];
}

void removeVectorItem(staticvector_t *vector, int index) {
    if (index >= vector->size) return;
    if (index < 0) return;
    memcpy(&vector->buffer[index * vector->itemSize], &vector->buffer[(index + 1) * vector->itemSize], vector->itemSize * (vector->size - index));
    --vector->size;
}

void clearVector(staticvector_t *vector) {
    vector->size = 0;
    memset(vector->buffer, 0, vector->itemSize * vector->capacity);
}
