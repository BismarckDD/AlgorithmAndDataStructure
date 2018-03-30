#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <Algorithm.h>

const int MAXN = 100000;
int arr[15] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};

int main()
{
    std::cout << "Hello World" << std::endl;

    std::cout << std::lower_bound(arr, arr + 15, 2) << " " << stdcs::lower_bound(arr, arr + 15, 2) << std::endl;
    std::cout << std::upper_bound(arr, arr + 15, 2) << " " << stdcs::upper_bound(arr, arr + 15, 2) << std::endl;

    std::cout << std::lower_bound(arr, arr + 15, -1) << " " << stdcs::lower_bound(arr, arr + 15, -1) << std::endl;
    std::cout << std::upper_bound(arr, arr + 15, -1) << " " << stdcs::upper_bound(arr, arr + 15, -1) << std::endl;

    std::cout << std::lower_bound(arr, arr + 15, 5) << " " << stdcs::lower_bound(arr, arr + 15, 5) << std::endl;
    std::cout << std::upper_bound(arr, arr + 15, 5) << " " << stdcs::upper_bound(arr, arr + 15, 5) << std::endl;

    std::vector<int> vec;
    for (int i = 1; i <= MAXN; ++i) 
        vec.push_back(rand() % 10000);

    std::sort(vec.begin(), vec.end());

    for (int i = 0; i <= 32767; ++i)
    {
        if (std::lower_bound(vec.begin(), vec.end(), i) != stdcs::lower_bound(vec.begin(), vec.end(), i) ||
            std::upper_bound(vec.begin(), vec.end(), i) != stdcs::upper_bound(vec.begin(), vec.end(), i))
            std::cout << "Error! : " << i << std::endl;
    }

    std::vector<int> vec1(vec);
    std::vector<int> vec2(vec);
    
    // std::cout << vec1.size() << std::endl;
    // std::cout << vec2.size() << std::endl;

    int diff1 = stdcs::unique(vec1.begin(), vec1.end()) - vec1.begin();
    int diff2 = std::unique(vec2.begin(), vec2.end()) - vec2.begin();
    
    if (diff1 == diff2)
        std::cout << "Correct!" << std::endl;
    else
        std::cout << "Error! " << diff1 << " " << diff2 << std::endl;
    
    for (int i = 0; i < vec1.size(); ++i)
        if (vec1[i] != vec2[i])
        {
            std::cout << "Error! " << i << " " << vec1[i] << " " << vec2[i] << std::endl;
            break;
        }
        // else
           // std::cout << vec1[i] << std::endl;
    return 0;
}
