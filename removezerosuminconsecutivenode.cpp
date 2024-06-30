// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h> 
typedef struct node{
    int val;
    struct node *next;
}node;
node* getNode(int val){
    node *temp = (node*)malloc(sizeof(int));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
node* insert(node *head, int val){
    node *temp = getNode(val);
    temp->next = head;
    head = temp;
    return head;
}

void display( node *head){
    node *p = head;
    while (p != NULL){
        printf("%d->", p->val);
        p = p->next;
    }
    printf("\n");
}
node* removezerosum(node *head){
    std::map<int, node*> prefixSumMap;
    node *start = NULL;
    int sum = 0;
    while (head != NULL){
        sum += head->val;
        if (prefixSumMap.find(sum) != prefixSumMap.end()){
            start = prefixSumMap[sum];
            node *q = start;
            while (q != head){
                q = q->next;
            }
            start->next = q->next;
        }
        else{
          prefixSumMap.insert({sum, head});
        }
        head = head->next;
    }
    return start;
}
int main() {
    // Write C++ code here
    node *head = NULL;
    head = insert(head, -1);
    head = insert(head,1);
    head = insert(head, 3);
    head = insert(head, -3);
    head = insert(head, 2);
    display(head);
    node *start = removezerosum(head);
    display(start);

    return 0;
}
