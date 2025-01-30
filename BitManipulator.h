#pragma once

/* 32 bits */

#define INITIAL_POSITION 0
#define LAST_POSITION 31

class BitManipulator {
public:
    static bool setBit(int& number, int position);
    static bool clearBit(int& number, int position);
    static bool toggleBit(int& number, int position);
    static bool checkBit(int number, int position);

    static void setAllBits(int& number);
    static void clearAllBits(int& number);
    
    static bool setBitsInRange(int& number, int start, int end);
    static bool clearBitsInRange(int& number, int start, int end);

    static int countSetBits(int number);
    static int countLeadingZeros(int number);
    static int countTrailingZeros(int number);
    static int countDifferentBits(int n1, int n2);

    static int leastSignificantBitPosition(int number);
    static int mostSignificantBitPosition(int number);

    static bool isPowerOfTwo(int number);
    static bool areBitsAlternating(int number);
    static bool areBitsPalindrome(int number);

    static void rotateBitsLeft(int& number);
    static void rotateBitsRight(int& number);
    static void reverseBits(int& number);

    static bool swapBits(int& number, int pos1, int pos2);

    static int addNumbers(int n1, int n2);
    static int subtractNumbers(int n1, int n2);
    static int multiplyByTwoNTimes(int number, int n);
    static int divideByTwoNTimes(int number, int n);

    static int absoluteValue(int number);
    static int getSignBit(int number);
};
