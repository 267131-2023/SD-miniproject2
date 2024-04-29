#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    head = nullptr;
    size = 0;
}

void PriorityQueue::insert(Node *element, int i_priority) {
    if(head == nullptr){
        head = element;
        head->set_priority(i_priority);
        head->set_next(nullptr);
        size++;
    }

    else{
        Node* tmp_node = head;

        if(element->get_priority() > tmp_node->get_priority()){
            head = element;
            element->set_next(tmp_node);
        }

        else{
            while(tmp_node->get_next() != nullptr && element->get_priority() <= tmp_node->get_priority()){
                tmp_node = tmp_node->get_next();
            }

            element->set_next(tmp_node->get_next());
            tmp_node->set_next(element);
            size++;
        }
    }
}

int PriorityQueue::return_size() {
    return size;
}

Node *PriorityQueue::get_head() {
    return head;
}
