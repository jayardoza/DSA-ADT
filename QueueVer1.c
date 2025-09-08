#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int items[MAX];
	int count;
}List;

typedef struct{
	List list;
	int front;
	int rear;
}Queue;

Queue* initialize(){
	Queue * q = malloc(sizeof(Queue));
	
	q->list.count = 0;
	q->front = -1;
	q->rear = -1;
	
	return q;
}

bool isFull(Queue* q){
	bool resp = false;
	if(q->list.count == MAX){
		resp = true;
	}
	return resp;
}

bool isEmpty(Queue* q){
	bool resp = false;
	if(q->list.count == 0){
		resp = true;
	}
	return resp;
}

void enqueue(Queue* q, int value){
	if(!isFull(q)){
		if(isEmpty(q)){
			q->front = 0;
			q->rear = 0;
		}else{
			q->rear = (q->rear+1) % MAX;
		}
		q->list.items[q->rear] = value;
		q->list.count++;
	}
}

int dequeue(Queue* q){
	int value;
	
	if(!isEmpty(q)){
		value = q->list.items[q->front];
		if(q->rear == q->list.count){
			q = initialize();
		}else{
			q->front = (q->front+1)% MAX;
			q->list.count--;
		}
	}
	return value;
}

void display(Queue *q){
	if(!isEmpty(q)){
		int i = q->front;
		
		for(i; i <= q->rear; i = (i+1) % MAX){
			printf("%d\n", q->list.items[i]);
		}
	}
}

int front(Queue *q){
	int value;
	
	if(!isEmpty(q)){
		value = q->list.items[q->front];
	}
	return value;
}
void main() {
    Queue* q;
    
	q = initialize();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    display(q);
    
    dequeue(q);
    display(q);

    printf("Front: %d", front(q));
}
