#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/HalfAdder.h"
#include <iostream>

TEST(HalfAdderTest, testHalfAdderSum)
{
    HalfAdder halfAdder;

    std::cout << "Half Adder Sum Truth Table:" << std::endl;
    std::cout << "+-------+-------+-------+---------+" << std::endl;
    std::cout << "|   A   |   B   | Carry |  Sum    |" << std::endl;
    std::cout << "+-------+-------+-------+---------+" << std::endl;

    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            halfAdder.setInputs(a, b);

            int sum = halfAdder.getSum();
            int carryOut = halfAdder.getCarry();

            std::cout << "|   " << a << "   |   " << b << "   |   " << carryOut << "   |    " << sum << "    |" << std::endl;
            ASSERT_EQ(a ^ b, sum); // Sum = A XOR B
            ASSERT_EQ(a & b, carryOut); // Carry = A AND B
        }
    }
    std::cout << "+-------+-------+-------+---------+" << std::endl;
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
