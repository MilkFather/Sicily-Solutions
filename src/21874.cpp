using namespace std;

typedef int Stack_entry;

class Stack {
private:
    struct Node {
        Stack_entry value;
        struct Node *next;
        Node(Stack_entry init): value(init), next(NULL) {};
    };
    struct Node *head;
    
    int s;
    
public:
    Stack() {
        this->head = NULL;
        this->s = 0;
    }
    
    ~Stack() {
        while (!this->empty()) {
            this->pop();
        }
    }
    
    Stack(const Stack &original) {
        this->head = NULL;
        this->s = 0;
        
        if (original.head == NULL)
            return;
        
        // copy the linked list.
        Node *walk = original.head;
        // copy the head
        Node *headNode = new Node(original.head->value);
        this->head = headNode;
        Node *newwalk = this->head;
        
        walk = walk->next;
        //newwalk = newwalk->next;
        
        this->s = 1;
        
        // copy the remaining
        while (walk != NULL) {
            Node *newNode = new Node(walk->value);
            newwalk->next = newNode;
            (this->s)++;
            
            walk = walk->next;
            newwalk = newwalk->next;
        }
    }
    
    void operator= (const Stack &original) {
        // clear this
        while (!this->empty())
            this->pop();
        this->s = 0;
        
        // do the same as the copy constructor
        if (original.head == NULL)
            return;
        
        // copy the linked list.
        Node *walk = original.head;
        // copy the head
        Node *headNode = new Node(original.head->value);
        this->head = headNode;
        Node *newwalk = this->head;
        
        walk = walk->next;
        //newwalk = newwalk->next;
        
        this->s = 1;
        
        // copy the remaining
        while (walk != NULL) {
            Node *newNode = new Node(walk->value);
            newwalk->next = newNode;
            (this->s)++;
            
            walk = walk->next;
            newwalk = newwalk->next;
        }
    }
    
    void push(const Stack_entry &c) {
        struct Node *entry = new struct Node(c);
        entry->next = this->head;
        this->head = entry; // Top is head and thus head is top
        (this->s)++;
    }
    
    void pop() {
        if (head == NULL)
            return;
        struct Node *target = this->head;
        this->head = target->next;
        delete target;
        (this->s)--;
    }
    
    const Stack_entry & top() const {
        return this->head->value;
    }
    
    bool empty() const {
        return this->head == NULL;
    }
    
    int size() const {
        return this->s;
    }
};

typedef Stack MyStack;