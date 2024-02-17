class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack{

    Node* head;
    Node* mid;
    int size;
    Stack(){
        head = nullptr;
        mid = nullptr;
        size = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        if(size == 0){
            head= temp;
            mid = head;
            size++;
            return;
        }


        head ->next = temp;
        temp->prev = head;

        // update head means here head is top of the stack;
        head = head->next;
        if(size % 2 == 1){
            mid = mid->next;
        }
        size++;

    }
    int pop(){

        int data=-1;
        if (size != 0) {
          Node* toPop = head;
          data = toPop->data;
            if (size == 1) {
                head = nullptr;
                mid = nullptr;
            }
            else {
                head = head->prev;
                head->next = nullptr;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
            }
              delete toPop;
            size--;
        }
      return data;
    }
    int findMid(){
        if(size == 0){
            return -1;
        }
        return mid->data;
    }
    void deleteMid(){
        if (size != 0) {
              Node* toDelete = mid;
            if (size == 1) {
                head = nullptr;
                mid = nullptr;
            }
            else if (size == 2) {
                head = head->prev;
                mid = mid->prev;
                head->next = nullptr;
            }
            else {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
                else {
                    mid = mid->next;
                }
            }
              delete toDelete;
            size--;
        }
    }
};