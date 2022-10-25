#include<iostream>
#include<limits.h>
using namespace std;
struct queue {
  int front;
  int rear;
  int *array;
  int capacity;
  int size;
};

struct queue * createQueue(int capacity) {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    if(!q)
    return NULL;
    q -> front = q -> rear = -1;
    q -> array = (int*)malloc(sizeof(int) * capacity);
    if(!q -> array)
    return NULL;
    q -> capacity = capacity;
    q -> size = 0;
    return q;
}

int queueSize(struct queue *q) {
    return q -> size;
}

int isFull(struct queue *q) {
    return q -> size == q -> capacity;
}

int isEmpty(struct queue *q) {
    return q -> size ==0;
}

int front(struct queue *q) {
    return q -> array[q -> front];
}

int rear(struct queue *q) {
    return q -> array[q -> rear];
}

int resize(struct queue *q) {
    int size = q -> capacity;
    q -> capacity = q -> capacity*2;
    q -> array = (int *)realloc(size(int)*q -> capacity);
    
}
int enqueue(struct queue* q, int data) {
    if(isFull(q)) {
        resize(q);
    }
    
    q -> rear = (q -> rear+1)% q -> capacity;
    
    q -> array[q -> rear] = data;
    if(q -> front ==-1)
    q -> front = q -> rear;
    q -> size = q -> size+1;
}

int dequeue(struct queue *q) {
    int temp;
    if(isEmpty(q)) {
        cout<<"Queue is EMPTY\n";
        return 0;
    }
    
    temp = q -> array[q -> front];
    if(q -> front == q -> rear) {
        q -> front = q -> rear = -1;
        q -> size = 0;
    }
    else {
        q -> front = (q -> front+1)%(q -> capacity);
        q -> size -=1;
    }
    return temp;
}

int printQueue(struct queue *q) {
    for(int i=0; i < q -> size; i++) {
        cout<<q -> array[i]<<" ";
    } 
    cout<<"\n";
}

void deleteQueue(struct queue *q) {
    if(q)
        if(q -> array)
        free(q -> array);
    free(q);
}
int main() {
    int capacity;
    cout<<"Enter the capacity of a queue : ";
    cin>>capacity;
    struct queue *q = createQueue(capacity);
    
    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 7);
    enqueue(q, 10);

    cout<<"The size of queue : "<<queueSize(q)<<endl;
    
    cout<<"The front Element of a queue : "<<front(q)<<endl;
    cout<<"The rear element of a queue : "<<rear(q)<<endl;
    
    cout<<dequeue(q)<<" is deleted from queue \n";
    cout<<dequeue(q)<<" is deleted from queue \n";
    cout<<dequeue(q)<<" is deleted from queue \n";
    cout<<dequeue(q)<<" is deleted from queue \n";
    cout<<dequeue(q)<<" is deleted from queue \n";
    cout<<dequeue(q)<<" is deleted from queue \n";
    
    enqueue(q, 5);
    enqueue(q, 100);
    
    cout<<"The size of queue : "<<queueSize(q)<<endl;
    
    cout<<"The front Element of a queue : "<<front(q)<<endl;
    cout<<"The rear element of a queue : "<<rear(q)<<endl;
    
    deleteQueue(q);
}
