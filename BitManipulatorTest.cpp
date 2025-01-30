#include "BitManipulator.h"
#include <gtest/gtest.h>

/*
 * Tests created by claude.ai
 */

class BitManipulatorTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Basic Bit Operations Tests
TEST_F(BitManipulatorTest, BasicBitOperations) {
    int num = 0;
    
    // setBit tests
    EXPECT_TRUE(BitManipulator::setBit(num, 0));
    EXPECT_EQ(num, 1);
    EXPECT_TRUE(BitManipulator::setBit(num, 3));
    EXPECT_EQ(num, 9);    // Binary: 1001
    EXPECT_FALSE(BitManipulator::setBit(num, -1));
    EXPECT_FALSE(BitManipulator::setBit(num, 32));
    
    // clearBit tests
    num = 15;    // Binary: 1111
    EXPECT_TRUE(BitManipulator::clearBit(num, 1));
    EXPECT_EQ(num, 13);    // Binary: 1101
    EXPECT_FALSE(BitManipulator::clearBit(num, -1));
    EXPECT_FALSE(BitManipulator::clearBit(num, 32));
    
    // toggleBit tests
    num = 10;    // Binary: 1010
    EXPECT_TRUE(BitManipulator::toggleBit(num, 1));
    EXPECT_EQ(num, 8);    // Binary: 1000
    EXPECT_TRUE(BitManipulator::toggleBit(num, 1));
    EXPECT_EQ(num, 10);    // Binary: 1010
    EXPECT_FALSE(BitManipulator::toggleBit(num, -1));
    EXPECT_FALSE(BitManipulator::toggleBit(num, 32));
    
    // checkBit tests
    num = 10;    // Binary: 1010
    EXPECT_TRUE(BitManipulator::checkBit(num, 1));
    EXPECT_FALSE(BitManipulator::checkBit(num, 0));
    EXPECT_FALSE(BitManipulator::checkBit(num, -1));
    EXPECT_FALSE(BitManipulator::checkBit(num, 32));
}

// All Bits Operations Tests
TEST_F(BitManipulatorTest, AllBitsOperations) {
    int num = 0;
    
    // setAllBits tests
    BitManipulator::setAllBits(num);
    EXPECT_EQ(num, -1);    // All bits set to 1
    
    // clearAllBits tests
    num = -1;
    BitManipulator::clearAllBits(num);
    EXPECT_EQ(num, 0);    // All bits cleared
}

// Range Operations Tests
TEST_F(BitManipulatorTest, RangeOperations) {
    int num = 0;
    
    // setBitsInRange tests
    EXPECT_TRUE(BitManipulator::setBitsInRange(num, 2, 4));
    EXPECT_EQ(num, 28);    // Binary: 11100
    EXPECT_FALSE(BitManipulator::setBitsInRange(num, -1, 4));
    EXPECT_FALSE(BitManipulator::setBitsInRange(num, 2, 32));
    EXPECT_FALSE(BitManipulator::setBitsInRange(num, 4, 2));    // Invalid range
    
    // clearBitsInRange tests
    num = -1;    // All bits set
    EXPECT_TRUE(BitManipulator::clearBitsInRange(num, 2, 4));
    EXPECT_EQ(num, -29);    // Binary: ...11100011
    EXPECT_FALSE(BitManipulator::clearBitsInRange(num, -1, 4));
    EXPECT_FALSE(BitManipulator::clearBitsInRange(num, 2, 32));
    EXPECT_FALSE(BitManipulator::clearBitsInRange(num, 4, 2));    // Invalid range
}

// Bit Counting Tests
TEST_F(BitManipulatorTest, BitCounting) {
    // countSetBits tests
    EXPECT_EQ(BitManipulator::countSetBits(0), 0);
    EXPECT_EQ(BitManipulator::countSetBits(7), 3);    // Binary: 111
    EXPECT_EQ(BitManipulator::countSetBits(-1), 32);    // All bits set
    
    // countLeadingZeros tests
    EXPECT_EQ(BitManipulator::countLeadingZeros(0), 32);
    EXPECT_EQ(BitManipulator::countLeadingZeros(1), 31);
    EXPECT_EQ(BitManipulator::countLeadingZeros(0x80000000), 0);
    
    // countTrailingZeros tests
    EXPECT_EQ(BitManipulator::countTrailingZeros(0), 32);
    EXPECT_EQ(BitManipulator::countTrailingZeros(8), 3);
    EXPECT_EQ(BitManipulator::countTrailingZeros(-1), 0);
    
    // countDifferentBits tests
    EXPECT_EQ(BitManipulator::countDifferentBits(0, 0), 0);
    EXPECT_EQ(BitManipulator::countDifferentBits(7, 4), 2);    // 111 vs 100
    EXPECT_EQ(BitManipulator::countDifferentBits(-1, 0), 32);
}

// Bit Position Tests
TEST_F(BitManipulatorTest, BitPosition) {
    // leastSignificantBitPosition tests
    EXPECT_EQ(BitManipulator::leastSignificantBitPosition(0), -1);
    EXPECT_EQ(BitManipulator::leastSignificantBitPosition(12), 2);    // Binary: 1100
    EXPECT_EQ(BitManipulator::leastSignificantBitPosition(-1), 0);
    
    // mostSignificantBitPosition tests
    EXPECT_EQ(BitManipulator::mostSignificantBitPosition(0), -1);
    EXPECT_EQ(BitManipulator::mostSignificantBitPosition(12), 3);    // Binary: 1100
    EXPECT_EQ(BitManipulator::mostSignificantBitPosition(-1), 31);
}

// Pattern Tests
TEST_F(BitManipulatorTest, PatternChecking) {
    // isPowerOfTwo tests
    EXPECT_TRUE(BitManipulator::isPowerOfTwo(1));
    EXPECT_TRUE(BitManipulator::isPowerOfTwo(4));
    EXPECT_FALSE(BitManipulator::isPowerOfTwo(0));
    EXPECT_FALSE(BitManipulator::isPowerOfTwo(6));
    EXPECT_FALSE(BitManipulator::isPowerOfTwo(-4));
    
    // areBitsAlternating tests
    EXPECT_TRUE(BitManipulator::areBitsAlternating(0xAAAAAAAA));    // 10101010...
    EXPECT_TRUE(BitManipulator::areBitsAlternating(0x55555555));    // 01010101...
    EXPECT_FALSE(BitManipulator::areBitsAlternating(0));
    EXPECT_FALSE(BitManipulator::areBitsAlternating(7));    // 111
    
    // areBitsPalindrome tests
    EXPECT_TRUE(BitManipulator::areBitsPalindrome(0));
    EXPECT_TRUE(BitManipulator::areBitsPalindrome(1342177290));    // 01010...01010
    EXPECT_FALSE(BitManipulator::areBitsPalindrome(0x55555555));    // All alternating 1s
    EXPECT_FALSE(BitManipulator::areBitsPalindrome(2));
}

// Bit Rotation Tests
TEST_F(BitManipulatorTest, BitRotation) {
    // rotateBitsLeft tests
    int num = 0x80000001;    // Binary: 1000...0001
    BitManipulator::rotateBitsLeft(num);
    EXPECT_EQ(num, 3);    // Binary: 11
    
    // rotateBitsRight tests
    num = 3;    // Binary: 11
    BitManipulator::rotateBitsRight(num);
    EXPECT_EQ(num, 0x80000001);    // Binary: 1000...0001
    
    // reverseBits tests
    num = 0x80000001;    // Binary: 1000...0001
    BitManipulator::reverseBits(num);
    EXPECT_EQ(num, 0x80000001);    // Should be the same
    
    num = 0x80000000;    // Binary: 1000...0000
    BitManipulator::reverseBits(num);
    EXPECT_EQ(num, 1);    // Binary: 1
}

// Bit Swapping Tests
TEST_F(BitManipulatorTest, BitSwapping) {
    int num = 10;    // Binary: 1010
    
    EXPECT_TRUE(BitManipulator::swapBits(num, 1, 3));
    EXPECT_EQ(num, 10);    // Should remain the same as bits are same
    
    EXPECT_TRUE(BitManipulator::swapBits(num, 0, 1));
    EXPECT_EQ(num, 9);    // Binary: 1001
    
    EXPECT_FALSE(BitManipulator::swapBits(num, -1, 1));
    EXPECT_FALSE(BitManipulator::swapBits(num, 1, 32));
    EXPECT_TRUE(BitManipulator::swapBits(num, 31, 1)); // ORder does not matter when swapping
}

// Arithmetic Operations Tests
TEST_F(BitManipulatorTest, ArithmeticOperations) {
    // addNumbers tests
    EXPECT_EQ(BitManipulator::addNumbers(5, 3), 8);
    EXPECT_EQ(BitManipulator::addNumbers(-5, 3), -2);
    EXPECT_EQ(BitManipulator::addNumbers(0, 0), 0);
    
    // subtractNumbers tests
    EXPECT_EQ(BitManipulator::subtractNumbers(5, 3), 2);
    EXPECT_EQ(BitManipulator::subtractNumbers(3, 5), -2);
    EXPECT_EQ(BitManipulator::subtractNumbers(0, 0), 0);
    
    // multiplyByTwoNTimes tests
    EXPECT_EQ(BitManipulator::multiplyByTwoNTimes(5, 2), 20);
    EXPECT_EQ(BitManipulator::multiplyByTwoNTimes(0, 5), 0);
    EXPECT_EQ(BitManipulator::multiplyByTwoNTimes(-5, 2), -20);
    
    // divideByTwoNTimes tests
    EXPECT_EQ(BitManipulator::divideByTwoNTimes(20, 2), 5);
    EXPECT_EQ(BitManipulator::divideByTwoNTimes(0, 5), 0);
    EXPECT_EQ(BitManipulator::divideByTwoNTimes(-20, 2), -5);
}

// Sign Operations Tests
TEST_F(BitManipulatorTest, SignOperations) {
    // absoluteValue tests
    EXPECT_EQ(BitManipulator::absoluteValue(5), 5);
    EXPECT_EQ(BitManipulator::absoluteValue(-5), 5);
    EXPECT_EQ(BitManipulator::absoluteValue(0), 0);
    EXPECT_EQ(BitManipulator::absoluteValue(INT_MIN + 1), INT_MAX);
    
    // getSignBit tests
    EXPECT_EQ(BitManipulator::getSignBit(5), 0);
    EXPECT_EQ(BitManipulator::getSignBit(-5), 1);
    EXPECT_EQ(BitManipulator::getSignBit(0), 0);
}
