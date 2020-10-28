// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "encoders.h"
#include "../utils/staticvector/staticvector.h"
#include <stddef.h>
#include <string.h>

static encoder_t encoders[EncoderCapacity] = {};
static staticvector_t vector = {};

void initEncoders() {
    initVector(&vector, &encoders, sizeof(encoder_t), EncoderCapacity);
}

int getEncoderssSize() {
    return getVectorSize(&vector);
}

int getEncoderssCapacity() {
    return getVectorCapacity(&vector);
}

encoder_t* getEncoder(int index) {
    return getVectorItem(&vector, index);
}

encoder_t* addEncoder() {
    return addVectorItem(&vector);
}

void removeEncoder(int index) {
    removeVectorItem(&vector, index);
}

void clearEncoders() {
    clearVector(&vector);
}
