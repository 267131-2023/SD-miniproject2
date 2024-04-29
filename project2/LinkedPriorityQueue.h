#include "Node.h"

class PriorityQueue{
private:
    Node* head;
    int size;
public:
    PriorityQueue();
    void insert(Node* element, int i_priority);
    Node* extract_max();
    Node* peek();
    void modify_key(Node* element, int i_priority);
    int return_size();
    void display_queue();
    Node* get_head();
};
