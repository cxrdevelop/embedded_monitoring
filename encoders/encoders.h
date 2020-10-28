#ifndef ENCODERS_H
#define ENCODERS_H

typedef struct {
    int type;
    int address;
} encoder_t;

#define EncoderCapacity 256

void initEncoders();
int getEncoderssSize();
int getEncoderssCapacity();
encoder_t* getEncoder(int index);
encoder_t* addEncoder();
void removeEncoder(int index);
void clearEncoders();

#endif // ENCODERS_H
