#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct Node
{
    Node* next;
};

Node* nLast(Node* head, int n)
{
    Node *q=head, *p=head;
    while(n>0 && p)
    {
        n--;
        p=p->next;
    }
    if(!p) return nullptr;
    p=p->next;
    while(p)
    {
        p=p->next;
        q=q->next;
    }
    return q;
}
int main()
{
    return 0;
    
}
