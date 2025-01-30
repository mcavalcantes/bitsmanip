#include "BitManipulator.h"

/* 
 * I chose to implement each method as independent of each
 * others, even though I could reuse previously defined
 * methods to avoid rewriting some stuff. Consequently,
 * this code can be severely optimized if one wants to do so.
 */

/*
 * After finishing this, I learned that I should reuse methods
 * EVERY TIME possible, even if I'm doing something for educational
 * purposes. I did reuse only one function (`addNumbers`), because I'm definitely
 * not implementing `subtractNumbers` from scratch. `addNumbers` already took
 * me an hour to figure out a algorithm to it, and I'm definitely not willing to
 * see how much time it takes me to implement the subtraction.
 */

bool BitManipulator::setBit(int& number, int position) {
    if (position < INITIAL_POSITION || position > LAST_POSITION)
        return false;
    
    number |= (1 << position);
    return true;
}

bool BitManipulator::clearBit(int& number, int position) {
    if (position < INITIAL_POSITION || position > LAST_POSITION)
        return false;
    
    number &= ~(1 << position);
    return true;
}

bool BitManipulator::toggleBit(int& number, int position) {
    if (position < INITIAL_POSITION || position > LAST_POSITION)
        return false;
    
    number ^= (1 << position);
    return true;
}

bool BitManipulator::checkBit(int number, int position) {
    if (position < INITIAL_POSITION || position > LAST_POSITION)
        return false;
    
    return static_cast<bool>(number & (1 << position));
}

void BitManipulator::setAllBits(int& number) {
    int pos { INITIAL_POSITION };

    while (pos <= LAST_POSITION) {
        number |= (1 << pos);
        ++pos;
    }
}

void BitManipulator::clearAllBits(int& number) {
    int pos { INITIAL_POSITION };

    while (pos <= LAST_POSITION) {
        number &= ~(1 << pos);
        ++pos;
    }
}

bool BitManipulator::setBitsInRange(int& number, int start, int end) {
    if (start > end || start < INITIAL_POSITION || end > LAST_POSITION)
        return false;

    int pos { start };
    
    while (pos <= end) {
        number |= (1 << pos);
        ++pos;
    }

    return true;
}

bool BitManipulator::clearBitsInRange(int& number, int start, int end) {
    if (start > end || start < INITIAL_POSITION || end > LAST_POSITION)
        return false;

    int pos { start };
    
    while (pos <= end) {
        number &= ~(1 << pos);
        ++pos;
    }

    return true;
}

int BitManipulator::countSetBits(int number) {
    int count { 0 };
    int pos { INITIAL_POSITION };

    while (pos <= LAST_POSITION) {
        bool isSet = static_cast<bool>(number & (1 << pos));
        count += static_cast<int>(isSet);
        ++pos;
    }

    return count;
}

int BitManipulator::countLeadingZeros(int number) {
    int count { 0 };
    int pos { LAST_POSITION };

    while (pos >= INITIAL_POSITION) {
        if (number & (1 << pos))
            break;
        ++count;
        --pos;
    }

    return count;
}

int BitManipulator::countTrailingZeros(int number) {
    int count { 0 };
    int pos { INITIAL_POSITION };

    while (pos <= LAST_POSITION) {
        if (number & (1 << pos))
            break;
        ++count;
        ++pos;
    }

    return count;
}

int BitManipulator::countDifferentBits(int n1, int n2) {
    int count { 0 };
    int pos { INITIAL_POSITION };

    while (pos <= LAST_POSITION) {
        bool b1 = static_cast<bool>(n1 & (1 << pos));
        bool b2 = static_cast<bool>(n2 & (1 << pos));

        count += (b1 != b2);
        ++pos;
    }

    return count;
}

int BitManipulator::leastSignificantBitPosition(int number) {
    int pos { INITIAL_POSITION };

    while (pos <= LAST_POSITION) {
        if (number & (1 << pos))
            return pos;
        ++pos;
    }

    return -1;
}

int BitManipulator::mostSignificantBitPosition(int number) {
    int pos { LAST_POSITION };

    while (pos >= INITIAL_POSITION) {
        if (number & (1 << pos))
            return pos;
        --pos;
    }

    return -1;
}

bool BitManipulator::isPowerOfTwo(int number) {
    int count { 0 };
    int pos { INITIAL_POSITION };

    while (pos <= LAST_POSITION) {
        bool isSet = static_cast<bool>(number & (1 << pos));
        count += static_cast<int>(isSet);
        ++pos;
    }

    return count == 1;
}

bool BitManipulator::areBitsAlternating(int number) {
    bool prevBit { static_cast<bool>(number & 1) };
    
    for (int pos { INITIAL_POSITION + 1 }; pos <= LAST_POSITION; ++pos) {
        bool currBit { static_cast<bool>(number & (1 << pos)) };

        if (currBit == prevBit)
            return false;
        
        prevBit = currBit;
    }

    return true;
}

bool BitManipulator::areBitsPalindrome(int number) {
    for (int pos { INITIAL_POSITION }; pos < (LAST_POSITION + 1) / 2; ++pos) {
        bool b1 = static_cast<bool>(number & (1 << pos));
        bool b2 = static_cast<bool>(number & (1 << (LAST_POSITION - pos)));

        if (b1 != b2)
            return false;
    }

    return true;
}

void BitManipulator::rotateBitsLeft(int& number) {
    int pos { INITIAL_POSITION };

    bool b { };
    bool nextB { static_cast<bool>(number & 1) }; // Gets the first bit
    
    /* Saves the last bit */
    bool lastB { static_cast<bool>(number & (1 << LAST_POSITION)) };

    while (pos < LAST_POSITION) {
        b = nextB;
        nextB = static_cast<bool>(number & (1 << (pos + 1)));

        if (b) {
            /* If the current bit is 1, sets the next bit to 1 */
            number |= (1 << (pos + 1));
        } else {
            /* If the current bit is 0, sets the next bit to 0 */
            number &= ~(1 << (pos + 1));
        }

        ++pos;
    }

    /* Sets the first bit according to the last bit (saved earlier) */
    if (lastB) {
        // If the last bit was 1, sets the first bit to 1, due to rotation
        number |= 1;
    } else {
        // If the last bit was 0, sets the first bit to 0, due to rotation
        number &= ~1;
    }
}

void BitManipulator::rotateBitsRight(int& number) {
    int pos { LAST_POSITION };

    bool b { };
    bool nextB { static_cast<bool>(number & (1 << LAST_POSITION)) }; // Gets the last bit
    
    /* Saves the first bit */
    bool firstB { static_cast<bool>(number & 1) };

    while (pos > INITIAL_POSITION) {
        b = nextB;
        nextB = static_cast<bool>(number & (1 << (pos - 1)));

        if (b) {
            /* If the current bit is 1, sets the next bit to 1 */
            number |= (1 << (pos - 1));
        } else {
            /* If the current bit is 0, sets the next bit to 0 */
            number &= ~(1 << (pos - 1));
        }

        --pos;
    }

    /* Sets the last bit according to the first bit (saved earlier) */
    if (firstB) {
        // If the first bit was 1, sets the last bit to 1, due to rotation
        number |= (1 << LAST_POSITION);
    } else {
        // If the first bit was 0, sets the last bit to 0, due to rotation
        number &= ~(1 << LAST_POSITION);
    }
}

void BitManipulator::reverseBits(int& number) {
    for (int pos { INITIAL_POSITION }; pos < (LAST_POSITION + 1) / 2; ++pos) {
        bool b1 { static_cast<bool>(number & (1 << pos)) };
        bool b2 { static_cast<bool>(number & (1 << (LAST_POSITION - pos))) };

        if (b1 != b2) {
            if (b1) {
                number &= ~(1 << pos);
                number |= (1 << (LAST_POSITION - pos));
            } else {
                number |= (1 << pos);
                number &= ~(1 << (LAST_POSITION - pos));
            }
        }
    }
}

bool BitManipulator::swapBits(int& number, int pos1, int pos2) {
    if (
        pos1 < INITIAL_POSITION ||
        pos2 < INITIAL_POSITION ||
        pos1 > LAST_POSITION ||
        pos2 > LAST_POSITION
    ) {
        return false;
    }

    bool b1 = static_cast<bool>(number & (1 << pos1));
    bool b2 = static_cast<bool>(number & (1 << pos2));

    /* Swaps only if the bits are different, obviously. */
    if (b1 != b2) {
        if (b1) {
            number &= ~(1 << pos1);
            number |= (1 << pos2);
        } else {
            number |= (1 << pos1);
            number &= ~(1 << pos2);
        }
    }

    return true;
}

int BitManipulator::addNumbers(int n1, int n2) {
    int result { 0 };

    int pos { INITIAL_POSITION };
    bool carry { false };

    while (pos <= LAST_POSITION) {
        bool b1 { static_cast<bool>(n1 & (1 << pos)) };
        bool b2 { static_cast<bool>(n2 & (1 << pos)) };

        bool b { b1 != b2 };

        result |= (static_cast<int>(b != carry) << pos);

        if ((b1 && b2) || (b1 && carry) || (b2 && carry)) {
            carry = 1;
        } else {
            carry = 0;
        }

        ++pos;
    }

    return result;
}

/* I'm definitely not implementing this one LOL */
int BitManipulator::subtractNumbers(int n1, int n2) {
    return BitManipulator::addNumbers(n1, -n2);
}

/*
 * This method has a overflow risk.
 */
int BitManipulator::multiplyByTwoNTimes(int number, int n) {
    return (number << n);
}

/*
 * This method has risk of losing information.
 */
int BitManipulator::divideByTwoNTimes(int number, int n) {
    return (number >> n);
}

int BitManipulator::absoluteValue(int number) {
    bool signB { static_cast<bool>(number & (1 << LAST_POSITION)) };

    if (!signB)
        return number;

    return ~(number - 1);
}

int BitManipulator::getSignBit(int number) {
    bool b { static_cast<bool>(number & (1 << LAST_POSITION)) };
    return static_cast<int>(b);
}
