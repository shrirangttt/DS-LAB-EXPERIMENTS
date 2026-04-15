#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n ) {
	NODE first = NULL, temp, last = NULL;
	int x;
	
	if(n <= 0) return NULL;

	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		temp = createNodeInCLL(x);
	
		if (first == NULL) {
            first = last = temp;
            last->next = first;
        } else {
            last->next = temp;
            last = temp;
            last->next = first;
        }
    }
    return first;




}

// Traverse CLL
void traverseListInCLL(NODE first) {
	NODE temp = first;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");





}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE first,int pos,int x) {

NODE temp=createNodeInCLL(x);
NODE p=first;
int count=1;
if(pos==1)
{
if(first==NULL)
{
temp->next=temp;
return temp;
}
while(p->next!=first)
p=p->next;
temp->next=first;
p->next=temp;
first=temp;
return first;
}
p=first;
for(int i=1;i<pos-1;i++)
{
p=p->next;
count++;
if(p->next==first)
{
printf("Position not found\n");
return first;
}
}
temp->next=p->next;
p->next=temp;
return first;


	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(NODE first,int pos) {
NODE temp=first,prev;
int count=1;

if(pos<1)
{
printf("Position not found\n");
return first;
}

if(pos==1)
{
NODE last=first;

if(first->next==first)
{
printf("Deleted element: %d\n",first->data);
free(first);
return NULL;
}
while(last->next!=first)
last=last->next;
printf("Deleted element: %d\n",first->data);
last->next=first->next;
first=first->next;
free(temp);
return first;
}
prev=NULL;
temp=first;
for(int i=1;i<pos;i++)
{
prev=temp;
temp=temp->next;
if(temp==first)
{
printf("Position not found\n");
return first;
}
}
prev->next=temp->next;
printf("Deleted element: %d\n",temp->data);
free(temp);
return first;

	
	
}

// Reverse CLL
NODE reverseCLL(NODE first) {
	
if (first == NULL || first->next == first)
        return first;

    NODE prev = NULL, curr = first, next;
    NODE last = first;

    // find last node
    while (last->next != first)
        last = last->next;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != first);

    first->next = prev;
    first = prev;

    return first;



}

// Concatenate two CLLs
NODE concatCLL(NODE first, NODE second) {

 if (first == NULL) return second;
    if (second == NULL) return first;

    NODE last1 = first;
    while (last1->next != first)
        last1 = last1->next;

    NODE last2 = second;
    while (last2->next != second)
        last2 = last2->next;

    last1->next = second;
    last2->next = first;

    return first;



}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
