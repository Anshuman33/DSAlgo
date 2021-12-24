using namespace std;
#define MAX_SIZE 10
template<typename T>
class Element{
    public:
    int key;
    T value;
    Element(){
        value = 0;
        key = INT16_MIN;
    }
    Element(T val){
        value = val;
        key=INT16_MIN;
    }
};



template<typename T>
class PQueue{
    
    Element<T> * A;
    public:
    int heapSize;
    PQueue(){
        A = new Element<T>[MAX_SIZE];
        heapSize = 0;
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
        Element<T> temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    void maxHeapify(int i){
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l<heapSize && A[l].key>A[i].key)
            largest = l;
        if(r<heapSize && A[r].key>A[largest].key)
            largest = r;
        if(largest!=i){
            exchange(i,largest);
            maxHeapify(largest);
        }
    }

    int heapExtractMax(){
        if(heapSize<1){
            cout<<"\nHeap Underflow";
            return -1;
        }
        else{
            
            exchange(0,heapSize-1);
            int max = A[heapSize-1].value;
            heapSize--;
            maxHeapify(0);
            return max;
        }
    }

    void heapIncreaseKey(int index,int newKey){
        if(newKey<A[index].key){
            cout<<"\nNew Key smaller than original";
        }
        else{
            A[index].key = newKey;
            while(index>0 && A[index].key>A[parent(index)].key){
                exchange(index,parent(index));
                index = parent(index);
            }
        }
    }

    void heapInsert(T value,int key){
        Element<T> * e = new Element<T>(value);
        A[heapSize] = (*e);
        heapSize++;
        heapIncreaseKey(heapSize-1,key);
    }

    void printHeap(){
        for(int i=0;i<heapSize;i++){
            cout<<A[i].value<<" ";
        }
    }
};