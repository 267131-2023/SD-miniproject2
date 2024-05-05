#ifndef PRIORITYQUEUE_NODE_H
#define PRIORITYQUEUE_NODE_H

class Node{
private:
    int value;
    int priority;
    Node* next;

public:
    Node(int i_value, int i_priority);
    int get_value();
    int get_priority();
    Node* get_next();
    void set_value(int i_new_value);
    void set_priority(int i_new_priority);
    void set_next(Node* next_node);
};

#endif //PRIORITYQUEUE_NODE_H
