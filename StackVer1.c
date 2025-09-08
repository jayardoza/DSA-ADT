#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int items [MAX];
	int top;
}Stack;

Stack* initialize(){
	Stack * s = malloc(sizeof(Stack));
	
	s->top = -1;
	
	return s;
}

bool isFull(Stack* s){
	bool resp = false;

	if(s->top == (MAX-1)){
		resp = true;
	}
	
	return resp;
}

bool isEmpty(Stack* s){
	bool resp = false;

	if(s->top == -1){
		resp = true;
	}
	
	return resp;
}

void push(Stack* s, int value){
	if(!isFull(s)){
		s->top++;
		s->items[s->top] = value;
	}else{
		printf("Error");
	}
}

int pop(Stack* s){
	int value;
	
	if(!isEmpty(s)){
		value = s->items[s->top];
		s->top--;
	}
	
	return value;
}


int peek(Stack* s){
	int value;
	
	if(s->top == -1){
		value = s->items[s->top];
	}
	
	return value;
}

void display(Stack* s){
	
	if(!isEmpty(s)){
		int i = s->top;
		
		for(i; i >= 0; i--){
			printf("\n%d\n", s->items[i]);
		}
		
}
}


void main(){
    Stack *s;
    s = initialize();
    
   // printf("%d", s->top);
    
	push(s, 1);
	push(s, 2);
	push(s, 3);

    display(s);
    
    pop(s);
    display(s);
}





