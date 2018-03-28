#ifndef _radix_sort_h_
#define _radix_sort_h_

size_t pow(size_t x, size_t y)
{
    size_t result = 1;
    for(size_t i = 1; i <= y; ++i)
        result *= x;
    return result;
}

void RadixSort(int *arr, size_t len, size_t radix = 16, size_t digit = 8)
{
    //cout << hex << RAND_MAX << endl;
    int *res = new int[len];
    int *c = new int[radix];
    int temp;
    size_t p, radix1 = radix-1;
    for (size_t i = 0; i < digit; ++i)
    {
        p  = pow(radix, i);
        for(int j = 0; j < radix; ++j) c[j] = 0;
        for(int j = 0; j < len; ++j) ++c[(arr[j]/p)&radix1];
        for(int j = 1; j < radix; ++j) c[j] += c[j-1];
        for(int j = len-1; j >= 0; --j) 
        {
            temp = (arr[j]/p)&radix1;
            res[c[temp]-1] = arr[j];
            --c[temp];
        }
        for(int j = 0; j < len; ++j) arr[j] = res[j];
    }
    delete[] res;
    res = NULL;
    delete[] c;
    c = NULL;
}

void RadixSort(int *arr, size_t len)
{
    RadixSort(arr, len, 32, 7);
}

#endif
