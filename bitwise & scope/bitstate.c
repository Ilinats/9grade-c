#include "bitstate.h"

static unsigned int bitstate = 4;

void setbit (int position) {

    if(position < 32 && position >= 0)
    {
        unsigned int temp = 0;
        temp = 1 << position;
        bitstate = bitstate | temp;
    }
}

void unsetbit (int position) {

    if(position < 32 && position >= 0)
    {
        unsigned int temp = 0;
        temp = 1 << position;
        bitstate = bitstate ^ temp;
    }
}

void togglebit (int position) {
    
    if(position < 32 && position >= 0)
    {
        unsigned int temp = 0;
        temp = 1 << position;
        bitstate = bitstate ^ temp;
    }
}

int isbitset (int position) {

    if(position < 32 && position >= 0)
    {
        unsigned int temp = 0;
        temp = 1 << position;
        return ((temp & bitstate) == temp);
    } else
        return -1;
}

unsigned int getbitstate (void) {
    return bitstate;
}