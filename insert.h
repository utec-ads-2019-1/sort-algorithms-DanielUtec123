#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {
public:
    InsertSort(void *elements, size_t size) : Sort(elements, size) {}

    void execute(void (*compare)(void*, int, int)) {
            for (int i= 1;i<size;i++){
                    int *array = (int*) elements; // Esto no es muy eficiente, deberías tener el cast por fuera (tampoco es crítico)
                    int index= i;
                    int tmp = array[i];
                    for (int j=i-1;j>=0; j-- ){
                            if(array[j]>tmp){
                                    array[index] = array[j];
                                    index--;
                            }
                            if (array[j]<=tmp){
                                    array[j+1] =tmp;
                                    break;
                            }

                    }
            }
    }

    inline string name() { return "InsertSort"; }
};

#endif