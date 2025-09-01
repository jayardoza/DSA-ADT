#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
void display(List L);


int main() {
    List L;
	int pos;
	
    L = initialize(L);
    printf("After Initialize: Count = %d\n", L.count);

   
    L = insertPos(L, 1, 0);   
    L = insertPos(L, 3, 1);   
    L = insertPos(L, 2, 2);   
    L = insertPos(L, 5, 3);  
    display(L);

    L = insertPos(L, 4, 1);   
    display(L);
	
	deletePos(L, 2);   
    display(L);
    
    pos = printf("Pos = %d", locate(L, 3));

    
    return 0;
}


//Functions
List initialize(List L){
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
    int i;
    if(L.count != MAX && position <= L.count){
    	for(i = L.count; i >= position; i--){
    	L.elem[i] = L.elem[i-1];
		}
	L.elem[position] = data;
	L.count++;
	}
	return L;
}

List deletePos(List L, int position){
	int i;
	if(position <= L.count){
		for(i = position; i < L.count-1; i++){
    	L.elem[i] = L.elem[i+1];
		}
	L.count--;
	}
	return L;
}

int locate(List L, int data){
	int i;
	int pos = -1;
	
	for(i = 0; i < L.count; i++){
		if(L.elem[i] == data){
			pos = i;
	    }
    }
		return pos;
}


void display(List L) {
    int i;
    
    for (i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    
    printf("\n Count = %d", L.count);
 
    printf("\n");
}



