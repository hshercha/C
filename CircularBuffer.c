//
//  CircularBuffer.c
//  Circular Buffer Example
//  Use array and pointers to create a circular buffer.
//
//  Created by Himal Sherchan on 5/2/16.
//  Copyright (c) 2016 Himal Sherchan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Intializes the buffer with the given size
 */
void initialize(size_t size);

/*
 * Reads the byte from the last pointer.
 */
uint8_t readByte();

/*
 * Writes the byte starting from the last pointer.
 */
void writeByte(uint8_t byte);

uint8_t maxSize;

uint8_t *origBufferAddress;
uint8_t *readPtr;
uint8_t *writePtr;


int main(int argc, const char * argv[]) {
    initialize(4);
    return 0;
}

void initialize(size_t size)
{
    uint8_t buffer[size];
    
    memset(buffer, 0, sizeof(buffer));
    maxSize = 0;
    
    //Initializes all the pointers as well.
    origBufferAddress = &buffer[0];
    writePtr = &buffer[0];
    readPtr = &buffer[0];
    return;
}

uint8_t readByte()
{
    //Once the readPtr reads the last value in the buffer,
    //reset it to the first value of the buffer.
    //Checking the difference of the addresses ensures
    //no data is being read past the max size.
    if (readPtr - origBufferAddress == maxSize)
    {
        readPtr = origBufferAddress;
    }
    
    uint8_t retVal = *readPtr;
    
    //Increment the readPtr after value is retrieved
    readPtr = readPtr + 1;
    
    return retVal;
}

void writeByte(uint8_t byte)
{
    //Once the writePtr writes the last value in the buffer,
    //reset it to the first value of the buffer.
    //Checking the difference of the addresses ensures
    //no data is being written past the max size.
    if (writePtr - origBufferAddress == maxSize)
    {
        writePtr = origBufferAddress;
    }
    *writePtr = byte;
    
    //Increment the writePtr after the value is written.
    writePtr = writePtr + 1;
}
