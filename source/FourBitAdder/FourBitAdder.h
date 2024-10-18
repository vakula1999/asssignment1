#ifndef FOURBITADDER_H
#define FOURBITADDER_H

#include "intern/FullAdder.h"
#include <string>
#include <vector>

class FourBitAdder
{
public:
    FourBitAdder();
    std::string add(const std::string& binaryA, const std::string& binaryB, int carry);

private:
    void connectAdders();
    FullAdder fullAdders[4];
};

#endif // FOURBITADDER_H
