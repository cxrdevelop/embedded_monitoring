#ifndef STATICVECTOR_H
#define STATICVECTOR_H

typedef struct {
    char *buffer;
    int size;
    int capacity;
    int itemSize;
} staticvector_t;

void initVector(staticvector_t *vector, void *buffer, int itemSize, int capacity);
int getVectorSize(staticvector_t *vector);
int getVectorCapacity(staticvector_t *vector);
void* getVectorItem(staticvector_t *vector, int index);
void* addVectorItem(staticvector_t *vector);
void removeVectorItem(staticvector_t *vector, int index);
void clearVector(staticvector_t *vector);

#endif // STATICVECTOR_H
