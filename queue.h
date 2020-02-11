#include <iostream>
using namespace std;

class queue{
public:
    queue()                //init(?)
    {
    cout <<__PRETTY_FUNCTION__ << endl;
    head.next = nullptr;
    }

    void enqueue(int elem)    //push(?)
    {
    cout <<__PRETTY_FUNCTION__ << elem << endl;
    link *l = new link();
    l->val = elem;
    l->next = nullptr;
    link *h = &head;
    while (  h->next != nullptr) 
    {
        h = h->next;         //тут происходит шаг по элементам
    }
    h->next = l;  //тут кладется залупа в пупу
    }

    int dequeue()          //pop(?)
    {
        if(head.next != nullptr)
        {    
            int ret = head.next -> val;  //неясно
            link *old = head.next;
            head.next = head.next -> next;
            delete old;
            return ret;
        }
        return 0;
    }

    bool empty()
    {
        cout <<__PRETTY_FUNCTION__ << endl;
        return head.next == nullptr;
    }

    ~queue()
    {
        while(!empty())
        {
            dequeue();
        }
        cout <<__PRETTY_FUNCTION__ << endl;
    }

private:
    struct link
    {
        int val;
        struct link *next;
    }head;
    
    
    
    
};
