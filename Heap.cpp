class Heap{
    int * A;
    int heapSize ;
    Heap(int * arr,int len){
        A = arr;
        heapSize = len;
        buildMaxHeap();
    }
 
    int left(int i){
        return 2*(i)+1;
    }

    int right(int i){
        return 2*(i+1);
    }

    int parent(int i){
        if(i%2==0){
            return i/2-1;
        }
        else{
            return i/2;
        }
    }

    int exchange(int i,int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    void maxHeapify(int i){
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l<heapSize && A[l]>A[i])
            largest = l;
        if(r<heapSize && A[r]>A[largest])
            largest = r;
        if(largest!=i){
            exchange(i,largest);
            maxHeapify(largest);
        }
    }

    void buildMaxHeap(){
        for(int i=heapSize/2-1;i>=0;i--){
            maxHeapify(i);
        }
    } 
};

