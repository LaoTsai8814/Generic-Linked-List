# LCEZ Generic Linked List

## Why would I do this project?
- Create a linked list quickly and easily
- Multiple different variable types can be placed in a linked list

## How to use

### demo
```cpp 
#include "Linkinglistc.h"

int main()
{
  DualWay* head = create_list();// <-- Create The Linked List
  head = menu(head);// <-- Test Function   < Create And print the value

  //free the list
  while(head)
  {
    DualWay* temp = head;
    head = hand->next;
    free(temp->value);
    free(temp);
  }
  return 0;
}
```
