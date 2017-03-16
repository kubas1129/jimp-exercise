//
// Created by kubas1129 on 13.03.17.
//

#include "SimpleForwardList.h"


ForwardList *CreateNode(int value)
{
    ForwardList *list = new ForwardList;
    list->value = value;
    list->next = nullptr;
    return list;
}

void DestroyList(ForwardList *list)
{
    if(list != nullptr)
    {
        ForwardList *temp_list = new ForwardList;
        while(list->next != nullptr)
        {
            temp_list = list;
            list = list->next;
            delete temp_list;
        }
        delete temp_list;
        delete list;
    }

}

ForwardList *PushFront(ForwardList *list, int value)
{

    if(list == nullptr)
    {
        return nullptr;
    }
    else
    {
        ForwardList *new_list = CreateNode(value);
        new_list->next = list;

        return new_list;
    }
}

void Append(ForwardList *list, ForwardList *tail)
{
    if(tail != nullptr)
    {
        while(list->next != nullptr)
        {
            list = list->next;
        }

        list->next = tail;
    }
}
