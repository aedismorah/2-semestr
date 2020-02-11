#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    queue q;
    for (int i = 0; i < 10; ++i) 
    {
        queue tmp;
        q.enqueue(i);
    }
    while(!q.empty)
    {
        int el = q.dequeue();
        cout << el << endl;
    }

}
