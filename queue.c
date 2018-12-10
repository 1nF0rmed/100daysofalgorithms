#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

void shift() {
  int n_of_elements = rear-front-1;
  printf("Shift -> N ele: %d\n", n_of_elements);
  int i, p = front;

  for(i=0;i<n_of_elements;i++, p++) {
    queue[i] = queue[p];
  }
  front = 0, rear = n_of_elements-1;
}

// Normal insert
void insert(int item) {
  if(rear==MAX) {
    printf("Overflow\n");
    return;
  }
  queue[++rear] = item;
  if(front==-1)front++;
}

// Improved version of insert
void imp_insert(int item) {
  if(front==0 && rear==MAX) {
    printf("Overflow");
    return;
  } else if(front!=0 && rear==MAX) {
    shift();
  }

  queue[++rear] = item;
  if(front==-1)front++;
}

int delete() {
  if(front==rear) {
    printf("Underflow\n");
    return -1;
  }
  return queue[front++];
}

void display() {
  int i;
  printf("\nFront index: %d\nRear index: %d\n", front, rear);
  for(i=front;i<=rear;i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}


int main() {
  int a[] = {1, 2, 3, 4, 5};
  int i=0;
  for(i=0;i<5;i++) {
    printf("Inserting: %d\n", a[i]);
    imp_insert(a[i]);
  }
  display();
  printf("Deleting item from queue: %d\n", delete());
  display();
  return 0;
}
