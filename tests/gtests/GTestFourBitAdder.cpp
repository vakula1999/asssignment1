#include <gtest/gtest.h>
#include "../../source/FourBitAdder/FourBitAdder.h"
#include <iostream>
#include <string>
#include <bitset>

TEST(FourBitAdderTest, testFourBitAdder)
{
    FourBitAdder fourBitAdder;

    std::cout << "Four Bit Adder Truth Table:" << std::endl;
    std::cout << "+---------+---------+---------+---------+---------+" << std::endl;
    std::cout << "|   binA  |   binB  |   Sum   |  Carry  |  Expected |" << std::endl;
    std::cout << "+---------+---------+---------+---------+---------+" << std::endl;

    std::string inputBinA[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                               "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
                              };
    std::string inputBinB[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                               "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
                              };

    for (const auto& binaryA : inputBinA)
    {
        for (const auto& binaryB : inputBinB)
        {
            std::string sum = fourBitAdder.add(binaryA, binaryB, 0);
            int carryOut = sum[0] - '0';
            sum = sum.substr(1);

            int intA = std::bitset<4>(binaryA).to_ulong();
            int intB = std::bitset<4>(binaryB).to_ulong();
            int intSum = std::bitset<4>(sum).to_ulong();
            int expectedSum = (intA + intB) & 0xF; // Keep only 4 bits

            std::cout << "|   " << binaryA << "   |   " << binaryB << "   |  " << sum << "  |    " << carryOut
                      << "    |   " << intA << " + " << intB << "   |" << std::endl;
            ASSERT_EQ(expectedSum, intSum);

            int expectedCarry = (intA + intB) >> 4;
            ASSERT_EQ(expectedCarry, carryOut);
        }
    }

    std::cout << "+---------+---------+---------+---------+---------+" << std::endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
