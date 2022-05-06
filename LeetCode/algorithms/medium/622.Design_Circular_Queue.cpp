
  - cpp

class MyCircularQueue {    
public:
    vector<int> queue_;
    int size_;
    int head_;
    int tail_;
    int capa_;
    
    MyCircularQueue(int k) {
       queue_.resize(k);
       size_ = k;
       capa_ = 0;
       head_ = 0;
       tail_ = k-1; 
    }
    
    bool enQueue(int value) {
       if(isFull() == true)
           return false;
        
       tail_ = (tail_ + 1) % size_;
       queue_[tail_] = value;
       capa_++; 
       return true; 
    }
    
    bool deQueue() {
       if(isEmpty() == true)
           return false;
       head_ = (head_ + 1) % size_;
       capa_--;
       return true; 
    }
    
    int Front() {
        if(isEmpty() == true)
            return -1;
        return queue_[head_];
    }
    
    int Rear() {
        if(isEmpty()==true)
            return -1;
        return queue_[tail_]; 
    }
    
    bool isEmpty() {
        return (capa_ == 0);
    }
    
    bool isFull() {
        return (size_ == capa_);
    }
};
