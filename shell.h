#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            int *array= (int*)elements;
            for (int gap = size/2; gap >0 ; gap/=2) {

                for(int k =0;k<gap;k++){
                    for (int i= k;i<size;i+=gap){
                        int index= i;
                        int tmp = array[i];
                        for (int j=i-gap;j>=0; j-=gap ){
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
            }

        }

        inline string name() { return "ShellSort"; }
};

#endif