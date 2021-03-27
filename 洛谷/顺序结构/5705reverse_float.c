//
// Created by 木子又欠 on 2020/7/9.
//
#include <ctype.h>
#include <stdlib.h>

struct node{
    char element;
    struct node* nextNode;
};

int main(){
    struct node* first,*temp;
    first =  NULL;
    char c;
    while (scanf("%c",&c) && (isprint(c))){
//    while (c=getchar()){
//        if (!isprint(c)){ break; }
        temp = first;
        first =(struct node*) malloc(sizeof(struct node));
        first->element=c;
        first->nextNode = temp;
    }
    while (first != NULL) {
        printf("%c", first->element);
        first = first->nextNode;
    }
}
