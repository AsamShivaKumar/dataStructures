#include "definition.c"

struct nodeQ{
       struct node* ele;
       struct nodeQ* next;
};

struct queue{
    struct nodeQ* front;
    struct nodeQ* rear;
};

int initQ(struct queue**);
int isEmpty(struct queue*);
int enqueue(struct queue*, struct node*);
int dequeue(struct queue*, struct node**);
int destroyQ(struct queue**);

int bft(struct node*);

int main(){

    struct node* root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    int arr[] = {20,10,50,9,18,40,60,8,12};
    for(int i = 0; i < 9; i++){
        insertNode(&root,arr[i]);
    }
    bft(root);
    return 0; 
}

int bft(struct node* root){
    struct queue* q;
    initQ(&q);
    enqueue(q,root);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    while(!isEmpty(q)){
         dequeue(q,&temp);
         printf("%d, ", temp->data);
         if(temp->left) enqueue(q,temp->left);
         if(temp->right) enqueue(q, temp->right);
    }
    destroyQ(&q);
    free(temp);
    printf("\n");
    return 1;
}


int initQ(struct queue** q){
    *q = (struct queue*)malloc(sizeof(struct queue));
    if(!(*q)) return 0;
    (*q)->front = NULL;
    (*q)->rear = NULL;
    return 1;
}

int isEmpty(struct queue* q){
    return q->front == NULL;
}

int enqueue(struct queue* q, struct node* ele){
    struct nodeQ* newNode = (struct nodeQ*)malloc(sizeof(struct nodeQ));
    if(!newNode) return 0;
    newNode->ele = ele;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }else if(q->front == q->rear){
        q->front->next = newNode;
        q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return 1;
}

int dequeue(struct queue* q, struct node** ptr){
    if(isEmpty(q)) return 0;
    *ptr = q->front->ele;
    q->front = q->front->next;
    if(!q->front){
        q->rear = NULL; 
    }
    return 1;
}

int destroyQ(struct queue** q){
    if(isEmpty(*q)) return 1;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    while(!isEmpty(*q)){
        dequeue(*q, &temp);
    }
    free(temp);
    *q = NULL;
    return 1;
}