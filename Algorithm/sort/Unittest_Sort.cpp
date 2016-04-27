#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
#include"QuickSort.h"
#include"MergeSort.h"
#include"HeapSort.h"
#include"SelectionSort.h"
#include"InsertionSort.h"
#include"ShellSort.h"
#include"BubbleSort.h"


//template<typename TYPE>
void unittest_sort(const char *test_name, void (*sort)(int *arr, size_t n))
{
    
    const size_t MAXN = 1000000;
    int *arr = new int[MAXN]; 
	for(int i = 0; i < MAXN; ++i) 
        arr[i] = rand();
	
    sort(arr, MAXN);
	
    int temp = 0;
    printf("%s: ",test_name);
    for(int i = 0; i < MAXN; ++i) 
    {
        if(temp > arr[i])
        {
            cout << "Test Failed!" << endl;
            return ;
        }
        else
        {
            temp = arr[i];
        }
    }
    cout << "Test Successfully!" << endl;
    delete arr;
}


int main()
{

    const size_t MAXN = 1000000;
    unittest_sort("MergeSort", MergeSort);
	unittest_sort("HeapSort", HeapSort);
    unittest_sort("QuickSort", QuickSort);
    //int arr[MAXN];
    //for (size_t i=0;i<MAXN;++i) arr[i] = rand();
    //QuickSort(arr,MAXN);
    //unittest_sort
    return 0;

}
