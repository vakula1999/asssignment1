#ifndef HALFADDER_H
#define HALFADDER_H

#include "LogicGates.h"

class HalfAdder
{
public:
    HalfAdder();
    ~HalfAdder();

    void setInputs(const unsigned short int a, const unsigned short int b);
    unsigned short int getSum() const;
    unsigned short int getCarry() const;

private:
    AND m_andGate;
    OR m_orGate;
    NAND m_nandGate;
    unsigned short int m_sum;
    unsigned short int m_carry;
};

#endif // HALFADDER_H
