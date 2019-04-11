#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {
public:
    SelectSort(void *elements, size_t size) : Sort(elements, size) {}

    void execute(void (*compare)(void*, int, int)) {


            for (int i= 0;i<size-1;i++){
                    int *array = (int*) elements;
                    int min = array[i];
                    int index= i;
                    for (int j=i+1;j<=size-1;j++ ){

                            if (array[j] < min) {
                                    min = array[j];
                                    index = j;
                            }
                    }
                    swap(array[i], array[index]);
            }
    }

    inline string name() { return "SelectSort"; }
};

#endif