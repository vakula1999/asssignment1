#ifndef FULLADDER_H
#define FULLADDER_H

#include "HalfAdder.h"

class FullAdder
{
public:
    FullAdder();
    void setInputs(unsigned short in1, unsigned short in2, unsigned short carryIn);
    unsigned short getSum() const;
    unsigned short getCarry() const;

private:
    HalfAdder halfAdder1;
    HalfAdder halfAdder2;
    unsigned short carryIn_;
};

#endif // FULLADDER_H
