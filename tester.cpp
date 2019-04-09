#include "tester.h"

void integersBubble(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}


void integersSelect(void *elements, int first, int second) {

}

void integerInsert(void *elements, int first, int second) {

}
void integerShell(void *elements, int first, int second) {

}

void merge_sort(int*,int*,int,int);
void integerMerge(void *elements, int low, int high) {
    int *array = (int *) elements;
    int *tmp  = new int[high+1];

    merge_sort(array,tmp,0,high);

}


void merge(int*,int*,int,int, int);
void merge_sort(int *A,int *tmp,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = low + (high-low)/2; //This avoids overflow when low, high are too large
        merge_sort(A,tmp,low,mid);
        merge_sort(A,tmp,mid+1,high);
        merge(A,tmp,low,mid,high);
    }
}

void merge(int *A,int *tmp,int low,int mid,int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high))
    {
        if(A[h]<=A[j])
        {
            tmp[i]=A[h];
            h++;
        }
        else
        {
            tmp[i]=A[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            tmp[i]=A[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            tmp[i]=A[k];
            i++;
        }
    }
    for(k=low;k<=high;k++) A[k]=tmp[k];
}




Sort* Tester::getSort(Algorithm sort, void *array, size_t size) {
    switch (sort) {
        case bubblesort: return new BubbleSort(array, size);
        case selectsort: return new SelectSort(array, size);
        case insertsort: return new InsertSort(array, size);
        case shellsort: return new ShellSort(array, size);
        case quicksort: return new QuickSort(array, size);
        case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid sort");
    }
}

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integersBubble;
        case selectsort: return &integersSelect;
        case insertsort: return &integerInsert;
        case shellsort: return &integerShell;
        case mergesort: return &integerMerge;
        default: throw invalid_argument("Not a valid comparer");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    int temp[size];

    Algorithm algorithm[] = { bubblesort, selectsort , insertsort, shellsort/*, quicksort*/, mergesort };
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}