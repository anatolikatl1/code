#include "array.h"

int main() {
    Array arr(2, 2);

    arr.setValue(6);
    arr.setValue(60);
    arr.setValue(40);

    arr.showElements();

    return 0;
}

