using namespace std;

template <typename T>
class Queue {
    T data[100];
    int head, tail;
    int count;
    
public:
    Queue() {
        this->head = this->tail = this->count = 0; // Tail always points the next one after the last one.
    }
    
    ~Queue() {
        
    }
    
    Queue(const Queue &rhs) {
        for (int i = 0; i < 100; i++)
            this->data[i] = rhs.data[i];
        this->head = rhs.head;
        this->tail = rhs.tail;
        this->count = rhs.count;
    }
    
    const Queue & operator = (const Queue &rhs) {
        for (int i = 0; i < 100; i++)
            this->data[i] = rhs.data[i];
        this->head = rhs.head;
        this->tail = rhs.tail;
        this->count = rhs.count;
        
        return *this;
    }
    
    bool empty() const {
        return this->count == 0;
    }
    
    bool full() const {
        return this->count == 100;
    }
    
    int size() const {
        return this->count;
    }
    
    bool push(const T &c) {
        if (this->full()) {
            return false;
        } else {
            this->data[this->tail] = c;
            this->tail = (this->tail + 1) % 100;
            this->count++;
            return true;
        }
    }
    
    bool pop() {
        if (this->empty()) {
            return false;
        } else {
            this->head = (this->head + 1) % 100;
            this->count--;
            return true;
        }
    }
    
    const T & front() const {
        return this->data[this->head];
    }
};