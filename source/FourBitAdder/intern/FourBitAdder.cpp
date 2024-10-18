/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.
#include "../FourBitAdder.h"
#include <sstream>
#include <algorithm>
#include <iostream>

FourBitAdder::FourBitAdder()
{
    for (int i = 0; i < 4; i++)
    {
        fullAdders[i] = FullAdder();
    }
    connectAdders();
}

void FourBitAdder::connectAdders()
{
    int carryIn = 0;
    for (int i = 0; i < 4; i++)
    {
        fullAdders[i].setInputs(0, 0, carryIn);
        carryIn = fullAdders[i].getCarry();
    }
}

std::string FourBitAdder::add(const std::string& binaryA, const std::string& binaryB, int carry)
{
    std::stringstream result;

    for (int i = binaryA.length() - 1; i >= 0; i--)
    {
        int bitA = binaryA[i] - '0';
        int bitB = binaryB[i] - '0';

        fullAdders[i].setInputs(bitA, bitB, carry);
        int sum = fullAdders[i].getSum();
        carry = fullAdders[i].getCarry();

        result << sum;
    }

    result << carry;

    std::string resultStr = result.str();
    std::reverse(resultStr.begin(), resultStr.end());

    while (resultStr.length() < 5)
    {
        resultStr.insert(resultStr.begin(), '0');
    }

    return resultStr;
}

