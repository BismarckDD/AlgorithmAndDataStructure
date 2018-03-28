#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//#include"LinkedList.h"
#include"DeLinkedList.h"
#include"LinkedList.h"

void unittest_list(const char *listName, List<int> *list)
{ 
    bool flag = true;
    const int MAXN = 10000;
    int arr[MAXN];
    for(size_t i = 0; i < MAXN; ++i) arr[i] = rand();
    for(size_t i = 0; i < MAXN && flag; ++i)
    {
        if(!list->add(arr[i]) || list->size() != i+1)
        {
            cout << "Add Error!" << endl;
            flag = false;
            break;
        }
    }
     //list->show();
    list->reverse();
    //list->show();
    for(size_t i = 0; i < MAXN && flag; ++i) 
    {
        if(!list->find(arr[i]))
        {
            cout << "Cannot Found in find()!" << endl;
            flag = false;
            break;
        }
    }
    for(size_t i = 0; i < MAXN && flag; ++i) 
    {
        if(!list->remove(arr[i]) || list->size()+1+i != MAXN)
        {
            cout << "Remove Error!" << endl;
            flag = false;
            break;
        }
    }

    string str(listName);
    cout << str << ": ";
    if(flag)
    {
        cout << "Test Succeed!" << endl;
    }
    else
    {
        cout << "Test Failed!" << endl;
    }
}

int main()
{
    
    DeLinkedList<int> dll;
    LinkedList<int> ll;
    DeLinkedList<int> *pdll = &dll;
    List<int> *list = dynamic_cast<List<int> *>(pdll);
    if(list != NULL)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    unittest_list("DeLinkedList", &dll);
    unittest_list("LinkedList", &ll);
    return 0;
}
