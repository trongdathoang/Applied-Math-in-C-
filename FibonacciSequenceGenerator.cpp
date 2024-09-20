#include "FibonacciSequenceGenerator.h"

#include <string>
#include <cstddef>
#include <cassert>

// Constructor to set up a Fibonacci sequence
FibonacciSequenceGenerator::FibonacciSequenceGenerator(const std::string& aID) noexcept
    : fID(aID), fPrevious(0), fCurrent(1) {}

// Get sequence ID
const std::string& FibonacciSequenceGenerator::id() const noexcept {
    return fID;
}

// Get current Fibonacci number
const long long& FibonacciSequenceGenerator::operator*() const noexcept {
    return fCurrent;
}

// Type conversion to bool
FibonacciSequenceGenerator::operator bool() const noexcept {
    return hasNext();
}

// Reset sequence generator to first Fibonacci number
void FibonacciSequenceGenerator::reset() noexcept {
    fPrevious = 0;
    fCurrent = 1;
}

// Tests if there is a next Fibonacci number.
// Technically, there are infinitely many Fibonacci numbers,
// but the underlying integer data type limits the sequence.
bool FibonacciSequenceGenerator::hasNext() const noexcept {

    return (fCurrent >= 0 && (fPrevious + fCurrent) >= 0);
}

// Advance to next Fibonacci number
// Function performs overflow assertion check.
void FibonacciSequenceGenerator::next() noexcept {

    assert(fCurrent >= 0);
    long long nextFibonacci = fPrevious + fCurrent;

    // Check for overflow condition
    if (nextFibonacci < 0) {
        fCurrent = -1; // Set to a negative value to indicate overflow
    }
    else {
        fPrevious = fCurrent;
        fCurrent = nextFibonacci;
    }
}
