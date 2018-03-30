#include <iostream>
#include <cassert>
#include <List.h>
#include <LinkedList.h>
#include <DeLinkedList.h>
#include <Common.hpp>

void unittest_list(const char *listName, List<int> *list, size_t MAXN = stdcs::MAXN)
{ 
    bool flag = true;
    int arr[stdcs::MAXN];
    for (size_t i = 0; i < MAXN; ++i) arr[i] = rand();
    for (size_t i = 0; i < MAXN && flag; ++i)
    {
        if(!list->add(arr[i]) || list->size() != i + 1)
        {
            std::cout << "Add Element Error!" << std::endl;
            flag = false;
            break;
        }
    }
    assert(list->size() == MAXN);

    // list->show();
    list->reverse();
    // list->show();
    for (size_t i = 0; i < MAXN && flag; ++i)
    {
        if (!list->find(arr[i]))
        {
            std::cout << "Cannot Found Element Error!" << std::endl;
            flag = false;
            break;
        }
    }

    // for (size_t i = 0; i < MAXN && flag; ++i)
    // {
    //     assert(list->front() == arr[i]);
    // }

    for (size_t i = 0; i < MAXN && flag; ++i)
    {
        if (!list->remove(arr[i]) || list->size() + 1 + i != MAXN)
        {
            std::cout << "Remove Element Error!" << std::endl;
            flag = false;
            break;
        }
    }
    assert(list->size() == 0);

    std::string str(listName);
    std::cout << str << ":  ";
    if(flag)
    {
        std::cout << "Test Succeed!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed!" << std::endl;
    }
}

int main()
{

    DeLinkedList<int> dll;
    LinkedList<int> ll;
    DeLinkedList<int> *pdll = &dll;
    List<int> *list = dynamic_cast<List<int> *>(pdll);
    if (list != NULL)
        std::cout << "Dynamic Cast Succeed!" << std::endl;
    else
        std::cout << "Dynamic Cast Failed!" << std::endl;
    unittest_list("DeLinkedList", &dll, 1000);
    unittest_list("LinkedList", &ll, 1000);
    return 0;
}
