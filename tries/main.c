#include "definition.c"

int main(){
    struct trieNode* root;
    init(&root);
    insert(root,"bet");
    printf("%d\n",search(root,"be"));

    insert(root,"apple");
    insert(root,"be");
    insert(root,"best");
    insert(root,"beed");
    insert(root,"app");

    printf("%d\n",search(root,"bet"));
    printf("%d\n",search(root,"be"));
    printf("%d\n",search(root, "app"));
    printf("%d\n",search(root,"bee"));
    return 0;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
    
int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i,j;
    i = low-1; j = low;
    while(j < high){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    int temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;
    return i+1;
}