#include <iostream>
using namespace std;
bool init(subforwardlist** sfl)
{
    *sfl = nullptr;
    return true;
}


bool push_back(subforwardlist** sfl, int d)
{
    subforwardlist* t = *sfl;
    if (t == nullptr)
    {
        t = new subforwardlist;
        t->data = d;
        t->next = nullptr;
        *sfl = t;
    }

    else
    {
        while (t->next != nullptr)
            t = t->next;
        t->next = new subforwardlist;
        t->next->data = d;
        t->next->next = nullptr;
    }
    return true;

}

int pop_back(subforwardlist** sfl)
{
    int d;
    subforwardlist* t = *sfl;
    if (t == nullptr)
    {
        return 0;
    }
    else if (t->next == nullptr)
    {
        d = t->data;
        delete* sfl;
        *sfl = nullptr;
    }
    else
    {
        while (t->next->next != nullptr)
            t = t->next;
        d = t->next->data;
        delete t->next;
        t->next = nullptr;
    }
    return d;
}

bool push_forward(subforwardlist** sfl, int d)
{
    subforwardlist* t = new subforwardlist;
    t->data = d;
    t->next = *sfl;
    *sfl = t;
    return true;

}

int pop_forward(subforwardlist** sfl)
{
    int d;
    subforwardlist* t = *sfl;
    if (t == nullptr)
    {
        return 0;
    }
    else
    {
        *sfl = t->next;
        d = t->data;
        delete t;
        return d;
    }
}

unsigned int size(subforwardlist* sfl)
{
    subforwardlist* t = sfl;
    if (sfl == nullptr)
        return 0;
    else
    {
        unsigned int sum = 1;
        while (t->next != nullptr)
        {
            t = t->next;
            sum++;
        }
        return sum;
    }

}

bool push_where(subforwardlist** sfl, unsigned int where, int d)
{
    subforwardlist* t = *sfl;
    if (where == 0)
        push_forward(sfl, d);
    else if (where == size(*sfl) - 1)
        push_back(sfl, d);
    else
    {
        for (unsigned int i = 0; i < where - 1; i++)
        {
            t = t->next;
        }
        subforwardlist* b = t->next;
        t->next = new subforwardlist;
        t->next->data = d;
        t->next->next = b;
    }
    return true;
}

int erase_where(subforwardlist** sfl, unsigned int where)
{
    int res;
    subforwardlist* t = *sfl;
    if (where == 0)
        res = pop_forward(sfl);
    else if (where == size(*sfl) - 1)
        res = pop_back(sfl);
    else
    {
        for (unsigned int i = 0; i < where - 1; i++)
        {
            t = t->next;
        }
        subforwardlist* b = t->next;
        t->next = t->next->next;
        res = b->data;
        delete b;
    }
    return res;
}

void clear(subforwardlist** h)
{
    subforwardlist* p, * p1;
    p = *h;

    while (p != NULL)
    {
        p1 = p->next;

        delete p;
        p = p1;
    }
    *h = NULL;

}
