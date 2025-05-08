#include "array.h"
#include <iostream>
#include <cstring>

Array::Array(int size, int step) {
    if (size <= 0) {
        arr = nullptr;
        initialSize = 0;
    } else {
        arr = new int[size];
        initialSize = size;
    }

    this->step = (step > 0) ? step : 5;
    this->currentIndex = 0;
}

Array::~Array() {
    delete[] arr;
}

void Array::showElements() const {
    if (arr == nullptr || currentIndex == 0) {
        std::cout << std::endl;
        return;
    }

    for (int i = 0; i < currentIndex; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size) {
    if (size <= 0) return;

    int newSize = initialSize + size;
    int* newArr = new int[newSize];

    if (arr != nullptr && currentIndex > 0) {
        std::memcpy(newArr, arr, currentIndex * sizeof(int));
    }

    delete[] arr;
    arr = newArr;
    initialSize = newSize;
}

int Array::getSize() const {
    return initialSize;
}

int Array::getElemSize() const {
    return (arr == nullptr) ? 0 : currentIndex;
}

void Array::setValue(int val) {
    if (arr == nullptr || currentIndex >= initialSize) {
        expandArray(step);
    }

    arr[currentIndex++] = val;
}

void Array::setArray(int* pArr, int size) {
    for (int i = 0; i < size; ++i) {
        setValue(pArr[i]);
    }
}
