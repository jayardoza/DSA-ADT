#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *Eptr;

void initialize(Eptr L);
void insertPos(Eptr L, int data, int position);
void display(Eptr L);

int main() {
    Etype L;
    int pos;
    
    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 2, 2);
    insertPos(&L, 5, 3);

    printf("Before Insertion:\n");
    display(&L);

    insertPos(&L, 7, 2);

    printf("After Insertion:\n");
    display(&L);
    
    printf("\nBefore Deletion:\n");
    display(&L);

    deletePos(&L, 2);

    printf("After Deletion:\n");
    display(&L);
    
	pos = printf("\nPos of Data = %d\n", locate(L, 3));
	
	pos = printf("\nData of Pos = %d\n", retrieve(L, 1));
	
	 printf("\nBefore Insert Sorted:\n");
    display(&L);

    insertSorted(&L, 0);

    printf("After InsertSorted:\n");
    display(&L); 
    
    return 0;
}

//Functions
void initialize(Eptr L) {
    L->count = 0;
}

void insertPos(Eptr L, int data, int position){
    int i;
    if(L->count != MAX && position <= L->count){
    	for(i = L->count; i >= position; i--){
    	L->elem[i] = L->elem[i-1];
		}
	L->elem[position] = data;
	L->count++;
	}
}

void deletePos(Eptr L, int position){
	int i;
	if(position <= L->count){
		for(i = position; i < L->count-1; i++){
    	L->elem[i] = L->elem[i+1];
		}
	L->count--;
	}
}

int locate(Eptr L, int data){
	int i;
	int pos = -1;
	
	for(i = 0; i < L->count; i++){
		if(L->elem[i] == data){
			pos = i;
	    }
    }
		return pos;
}

int retrieve(Eptr L, int position) {
    int value = -1;  

    if (position >= 0 && position < L->count) {
        value = L->elem[position];
    }

    return value;
}

void insertSorted(Eptr L, int data) {
    int i;
	int pos = 0;

    if (L->count >= MAX) {
        printf("Full List!\n");
        return L;
    }

    while (pos < L->count && L->elem[pos] < data) {
        pos++;
    }

    for (i = L->count - 1; i >= pos; i--) {
        L->elem[i + 1] = L->elem[i];
    }

    L->elem[pos] = data;
    L->count++;
}

void display(Eptr L) {
	int i;
	
    printf("List: ");
    for (i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(Eptr L) {
    if (L != NULL) {
        free(L);
    }
}


