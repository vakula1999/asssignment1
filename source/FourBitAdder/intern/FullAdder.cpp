#include "FullAdder.h"

FullAdder::FullAdder() : carryIn_(0) {}

void FullAdder::setInputs(unsigned short in1, unsigned short in2, unsigned short carryIn)
{
    carryIn_ = carryIn;
    halfAdder1.setInputs(in1, in2);
    halfAdder2.setInputs(halfAdder1.getSum(), carryIn_);
}

unsigned short FullAdder::getSum() const
{
    return halfAdder2.getSum();
}

unsigned short FullAdder::getCarry() const
{
    return halfAdder1.getCarry() | halfAdder2.getCarry();
}
