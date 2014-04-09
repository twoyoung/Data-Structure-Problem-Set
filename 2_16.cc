/* 2.16 Pointer la and lb point to the first node of two single linked list respectively. The algorithm below deletes len nodes from the i node
 * beginning at the ith node from list la and inserts them into list lb before the jth node. Is the algorithm correct? If not correct it.
 * Status DeleteAndInsertSub(LinkedList la,LinkedList lb,int i,int j,int len){
 *    if(i < 0 || j < 0 || len < 0) return INFEASIBLE;
 *    p = la; k = 1;
 *    while(k < i) { p = p -> next; k++;}
 *    q = p;
 *    while(k <= len) { q = q -> next; k++;}
 *    s = lb; k = 1;
 *    while(k < j){ s = s -> next; k++;}
 *    s -> next = p; q -> next = s -> next;
 *    return OK;
 * }
 */

#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define OK 0
#define INFEASIBLE -1

typedef int Status;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
} LNode,*LinkedList;

Status InitList_L(LinkedList &L){
    L = NULL;
    return OK;
}

Status InsertList_L(LinkedList &L, ElemType e){
    LinkedList p = (LinkedList)malloc(sizeof(LNode));
    if(!p) exit(OVERFLOW);
    p -> data = e;
    p -> next = L;
    L = p;
    return OK;
}

//The function to delete len nodes from la[i] and insert them before bl[j]:
Status DeleteAndInsertSub(LinkedList la,LinkedList lb,int i,int j,int len){
    if(i < 0 || j < 0 || len < 0) return INFEASIBLE;
    LinkedList p = la; int k = 1;
    while(k < i-1){ p = p -> next; k++;} //After the loop p points to the node la[i-1].
    LinkedList q = p -> next; k = 1;
    while(k < len){ q = q -> next; k++;} // After the loop q points to the node lb[i+len-1] -the last node to delete.
    LinkedList r = q -> next; // r points to the node right after the len nodes.
    LinkedList s = lb; k = 1;
    while(k < j-1){ s = s -> next; k++;} // After the loop s points to the node lb[j-1] -the node after which to insert.
    q -> next = s -> next; s -> next = p -> next; //insert la[i]~la[i+len-1] after lb[j-1]
    p -> next = r; // delete la[i]~la[i+len-1]
    return OK;
}
    
int main(){
    LinkedList la,lb;
    InitList_L(la);
    InitList_L(lb);
    ElemType e;
    printf("Enter elements in la, -1 to end:\n");
    while(true){
 	      scanf("%d",&e);
	      if(e == -1) break;
	      InsertList_L(la,e); //Input elements in la.
    }
    printf("Enter elements in lb, -1 to end:\n");
    while(true){
	      scanf("%d",&e);
	      if(e == -1) break;
	      InsertList_L(lb,e); //Input elements in lb.
    }
    
    /* Code below is just a test. Delete la[5],la[6],la[7] and insert them before lb[2]*/
    printf("Before delete and insert:\n");
    LinkedList p = la;
    LinkedList q = lb;
    while(p){
	      printf("%d ",p -> data);
	      p = p -> next;
    }
    printf("\n");
    while(q){
	      printf("%d ",q -> data);
	      q = q -> next;
    }
    DeleteAndInsertSub(la,lb,5,2,3);
    printf("\nAfter delete and insert:\n");
    p = la; q = lb;
    while(p){
	      printf("%d ",p -> data);
	      p = p -> next;
    }
    printf("\n");
    while(q){
	      printf("%d ",q -> data);
	      q = q -> next;
    }
    printf("\n");
    return OK;
}

/* test outcome:
 * Enter elements in la, -1 to end:
 * 1 2 3 4 5 6 7 8 9 0 -1
 * Enter elements in lb, -1 to end:
 * 0 9 8 7 6 5 4 3 2 1 -1
 * Before delete and insert:
 * 0 9 8 7 6 5 4 3 2 1
 * 1 2 3 4 5 6 7 8 9 0
 * After delete and insert:
 * 0 9 8 7 3 2 1
 * 1 6 5 4 2 3 4 5 6 7 8 9 0
 */
