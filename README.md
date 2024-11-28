# LCEZ Generic Linked List

## Why would I do this project?
- Create a linked list quickly and easily
- Multiple different variable types can be placed in a linked list

## How to use

### demo
```c
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

### all function

- create a head with a head node
```c
DualWay* create_list()
```

- calculate the length of the linked list
```c
int list_length(DualWay* head)
```

- print all data from the linked list
```c
void print_all(DualWay* head)
```

- get the data from the specific index
```c
DualWay* GOTO_Index(DualWay* head,int index)
```

- add node to the linked list
```c
DualWay* add_node(DualWay* current, char side)
```

- delete node from the linkled list
```c
DualWay* delete_node(DualWay* head, DualWay* target)
```

- modify the data in the linked-list
```c
void modify_data(DualWay* node, DataType type)
```

- demo the menu of the linked list function
```c
DualWay* menu(DualWay* head)
```
