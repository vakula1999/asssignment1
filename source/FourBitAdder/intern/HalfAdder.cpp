#include "HalfAdder.h"

HalfAdder::HalfAdder() : m_andGate(1), m_orGate(1), m_nandGate(1), m_sum(0), m_carry(0) {}

HalfAdder::~HalfAdder() {}

void HalfAdder::setInputs(const unsigned short int a, const unsigned short int b)
{
    // Sum = A XOR B
    m_nandGate.set_in1(a);
    m_nandGate.set_in2(b);
    unsigned short int nand1 = m_nandGate.out();

    m_nandGate.set_in1(a);
    m_nandGate.set_in2(nand1);
    unsigned short int nand2 = m_nandGate.out();

    m_nandGate.set_in1(nand1);
    m_nandGate.set_in2(b);
    unsigned short int nand3 = m_nandGate.out();

    m_nandGate.set_in1(nand2);
    m_nandGate.set_in2(nand3);
    m_sum = m_nandGate.out();

    // Carry = A AND B
    m_andGate.set_in1(a);
    m_andGate.set_in2(b);
    m_carry = m_andGate.out();
}

unsigned short int HalfAdder::getSum() const
{
    return m_sum;
}

unsigned short int HalfAdder::getCarry() const
{
    return m_carry;
}
