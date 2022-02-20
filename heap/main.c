#include "definition.c"

int main(){
    int arr[] = {20,40,60,10,90,100,50,80};
    
    struct heap* h;
    init(&h);
    for(int i = 0; i < 8; i++){
       insert(h,arr[i]);
    }
    
    int p = 0;
    findMax(h,&p);
    printf("%d\n",p);
    
    extractMax(h,&p);
    printf("%d\n",p);
    
    findMax(h,&p);
    printf("%d\n",p);
    
    int* ptr = heapSort(h);
    
    for(int i = 1; i <= h->heapSize; i++){
       printf("%d ",ptr[i]);
    }
    printf("\n");
    return 0;
}
