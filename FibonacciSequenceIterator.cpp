#include "FibonacciSequenceIterator.h"


FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequenceGenerator& aSequenceObject, long long aStart) noexcept : fSequenceObject(aSequenceObject), fIndex(aStart) {}

const long long& FibonacciSequenceIterator::operator*() const noexcept {
	return *fSequenceObject;
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept {
	fIndex++;
	fSequenceObject.next();
	return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept {
	FibonacciSequenceIterator fCurrentIterator = *this;
	++(*this);
	return fCurrentIterator;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept {
	return fIndex == aOther.fIndex && fSequenceObject.id() == aOther.fSequenceObject.id();
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const noexcept {
	return !(*this == aOther);
}
FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept {

    FibonacciSequenceIterator copy = *this;
    copy.fIndex = 0;
    copy.fSequenceObject.reset();
    return copy;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept {

	FibonacciSequenceIterator endIterator = *this;
	while (endIterator.fSequenceObject.hasNext()) {
		++endIterator.fIndex;
		endIterator.fSequenceObject.next();
	}
	return endIterator;
}





