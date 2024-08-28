#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void append(struct ListNode **head, int new_val) {
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = new_val;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct ListNode *p = *head;
    p->next = new_node;
    return;
}

void display(struct ListNode *l){
    struct ListNode *p = l;
    // p = p->next;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* l = NULL;

    int carry = 0;
    int sum = 0;
    while(p != NULL && q != NULL){
        sum = p->val + q->val + carry;
        if(sum > 9){
            append(&l, sum % 10);
            carry = sum / 10;
        }
        else
            append(&l, sum);
        p = p->next;
        q = q->next;
    }
    while(p != NULL){
        sum = p->val + carry;
        if(sum > 9){
            append(&l, sum % 10);
            carry = sum / 10;
        }
        else
            append(&l, sum);
        p = p->next;
    }
    while(q != NULL){
        sum = q->val + carry;
        if(sum > 9){
            append(&l, sum % 10);
            carry = sum / 10;
        }
        else
            append(&l, sum);
        q = q->next;
    }
    if(carry > 0){
        append(&l, carry);
    }
    return l;
}

int main(){
    struct ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;
    append(&l1, 2);
    append(&l1, 4);
    append(&l1, 3);
    // printf("%d\n", l1->next->val);
    printf("test1\n");
    display(l1);

    append(&l2, 5);
    append(&l2, 6);
    append(&l2, 4);
    printf("test0\n");
    display(l2);

    l3 = addTwoNumbers(l1, l2);
    display(l3);

    return 0;
}