#include <stdio.h>
#include <stdlib.h>
#include "Linkinglistc.h"
#include <string.h>
#include <stdbool.h>
//#include"ReadInput.h"


// 創建一個新的鏈表頭節點
DualWay* create_list() {
    DualWay* head = (DualWay*)malloc(sizeof(DualWay));
    if (!head) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    head->pre = NULL;
    head->value = NULL;
    printf("Linked list created successfully!\n");
    return head;
}
// 計算鏈表長度
int list_length(DualWay* head) {
    int length = 0;
    DualWay* ptr = head;
    while (ptr) {
        length++;
        ptr = ptr->next;
    }
    return length-1;
}

// 打印所有節點的值
void print_all(DualWay* head) {
    DualWay* ptr = head->next;
    if (!ptr) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List Contents:\n");
    while (ptr) {
        switch (ptr->datatype) {
            case INT:
                printf("[INT: %d] ", *(int*)ptr->value);
                break;
            case FLOAT:
                printf("[FLOAT: %.2f] ", *(float*)ptr->value);
                break;
            case DOUBLE:
                printf("[DOUBLE: %.2lf] ", *(double*)ptr->value);
                break;
            case CHAR:
                printf("[CHAR: %s] ", (char*)ptr->value);
                break;
            default:
                printf("[UNKNOWN TYPE] ");
                break;
        }
        ptr = ptr->next;
    }
    printf("\n");
}
DualWay* GOTO_Index(DualWay* head,int index){
    DualWay* ptr = head;
    if(list_length(head)<=index||0>=index){
        printf("NULL");
        return NULL;
    }
        
    for(int i=0;i<index;i++)
        ptr = ptr->next;
    
    return ptr;
} 
// 新增節點到指定方向（前或後）
DualWay* add_node(DualWay* current, char side) {
    DualWay* new_node = (DualWay*)malloc(sizeof(DualWay));
    if (!new_node) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->value = NULL;
    new_node->datatype = UNKNOWN; // 默認類型
    new_node->next = NULL;
    new_node->pre = NULL;

    if (side == 'f' || side == 'F') { // 添加到當前節點之後
        new_node->next = current->next;
        new_node->pre = current;
        if (current->next) {
            current->next->pre = new_node;
        }
        current->next = new_node;
    } else if (side == 'b' || side == 'B') { // 添加到當前節點之前
        if(current->next==NULL&&current->pre==NULL){
            printf("It on the head elements, unable to going back side.\n");
            free(new_node);
            return current;
        }
        new_node->pre = current->pre;
        new_node->next = current;
        if (current->pre) {
            current->pre->next = new_node;
        }
        current->pre = new_node;
    } else {
        printf("Invalid side. Use 'f' for front or 'b' for back.\n");
        free(new_node);
        return current;
    }
    return new_node;
}

// 刪除指定節點
DualWay* delete_node(DualWay* head, DualWay* target) {
    if (!target) {
        printf("Error: Target node is NULL.\n");
        return head;
    }

    if (target->pre) {
        target->pre->next = target->next;
    } else { // 刪除頭節點
        head = target->next;
    }

    if (target->next) {
        target->next->pre = target->pre;
    }

    free(target->value);
    free(target);
    printf("Node deleted successfully.\n");
    return head;
}

// 修改節點數據
void modify_data(DualWay* node, DataType type) {
    if (!node) {
        printf("Error: Node is NULL.\n");
        return;
    }
    node->datatype = type;
    switch (type) {
        case INT: {
            int* value = (int*)malloc(sizeof(int));
            printf("Enter INT value: ");
            scanf("%d", value);
            node->value = value;
            break;
        }
        case FLOAT: {
            float* value = (float*)malloc(sizeof(float));
            printf("Enter FLOAT value: ");
            scanf("%f", value);
            node->value = value;
            break;
        }
        case DOUBLE: {
            double* value = (double*)malloc(sizeof(double));
            printf("Enter DOUBLE value: ");
            scanf("%lf", value);
            node->value = value;
            break;
        }
        case CHAR: {
            char* value = (char*)malloc(100 * sizeof(char));
            printf("Enter STRING value: ");
            scanf("%s", value);
            node->value = value;
            break;
        }
        default:
            printf("Unknown data type.\n");
            break;
    }
    printf("Node data modified successfully.\n");
}

// 主菜單函數
DualWay* menu(DualWay* head) {
    int choice;
    DualWay* current = head;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("Current List Length Is %d\n",list_length(head));
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Modify Node Data\n");
        printf("4. Print All Nodes\n");
        printf("5. Goto Index\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char side;
                printf("Enter side (f for front, b for back): ");
                scanf(" %c", &side);
                current = add_node(current, side);
                break;
            }
            case 2: {
                head = delete_node(head, current);
                current = head; // 更新當前指針
                break;
            }
            case 3: {
                int type=0;
                printf("Enter data type (1-INT, 2-FLOAT, 3-DOUBLE, 4-CHAR): ");
                fflush(stdin);
                scanf("%d", &type);
                printf("%d",type);
                modify_data(current, (DataType)(type - 1));
                break;
            }
            case 4:
                print_all(head);
                break;
            case 5:{
                int index=0;
                printf("Enter The Index You Want To GOTO");
                fflush(stdin);
                scanf("%d",&index);
                printf("%d",index);
                DualWay *Index_ptr=GOTO_Index(head,index);
                if(Index_ptr!=NULL){
                    current = Index_ptr;
                }
                break;
            }
            case 6:
                printf("Exiting program.\n");
                return head;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// 主函數
int main() {
    DualWay* head = create_list();
    head = menu(head);

    // 釋放內存
    while (head) {
        DualWay* temp = head;
        head = head->next;
        free(temp->value);
        free(temp);
    }
    printf("Memory cleaned up. Program terminated.\n");
    return 0;
}
