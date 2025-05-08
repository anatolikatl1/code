#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int initialSize;
    int step;
    int* arr;
    int currentIndex;

public:
    Array(int size = 10, int step = 5);
    ~Array();

    void showElements() const;
    void expandArray(int size);
    int getSize() const;
    int getElemSize() const;
    void setValue(int val);
    void setArray(int* pArr, int size);
};

#endif
