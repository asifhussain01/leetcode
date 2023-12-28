class MyCircularDeque {
public:
   int size,front,rear,*arr;
    MyCircularDeque(int k) {
        size=k;
        front=-1;
        rear=-1;
        arr=new int[size];

    }
    
    bool insertFront(int value) {
        //overflow
        if(isFull()){
            return false;
        }
        //singel
       else if(front==-1&&rear==-1){
            front++;
            rear++;
            arr[front]=value;
        }
        //circular nature
        else if(front==0&&rear!=size-1){
            front=size-1;
            arr[front]=value;
        }
        //normal case
        else{
            front--;
            arr[front]=value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        //overflow
        if(isFull()){
            return false;
        }
        //single
       else if(front==-1&&rear==-1){
           front++;
           rear++;
           arr[rear]=value;
       }
       //circular case
       else if(rear==size-1&&front!=0){
           rear=0;
           arr[rear]=value;
       }
       //normal nature
       else{
           rear++;
           arr[rear]=value;
       }
       return true;
    }
    
    bool deleteFront() {
        //underflow
        if(isEmpty()){
            return false;
        }
        //single nature
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        //circular nature
        else if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        //normal nature
        else{
            arr[front]=-1;
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
        //Underflow
        if(isEmpty()){
            return false;
        }
        //single nature
        else if(front==rear){
          arr[rear]=-1;
            rear=-1;
            front=-1;
        }
        //circular nature
        else if(rear==0){
            arr[rear]=-1;
            rear=size-1;
        }
        //normal nature
        else{
            arr[rear]=-1;
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
    
        return arr[front];
        
    }
    
    int getRear() {
        if(isEmpty())return -1;
       
       return arr[rear];
        
    }
    
    bool isEmpty() {
       return (front==-1&&rear==-1);
    }
    
    bool isFull() {
        //overflow
      return (front==0&&rear==size-1)||(rear==front-1);
       
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */