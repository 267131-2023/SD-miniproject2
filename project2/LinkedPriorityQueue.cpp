#include "iostream"
#include "PriorityQueue.h"

using namespace std;

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
            Node* prev_node = head;
            tmp_node = head->get_next();
            while(tmp_node->get_next() != nullptr && element->get_priority() <= tmp_node->get_priority()){
                tmp_node = tmp_node->get_next();
                prev_node = prev_node->get_next();
            }

            if(tmp_node->get_next() == nullptr){
                tmp_node->set_next(element);
                element->set_next(nullptr);
            }

            else{
                element->set_next(prev_node->get_next());
                prev_node->set_next(element);
            }
        }
        size++;
    }
}

void PriorityQueue::display_queue() {
    Node* tmp = head;

    while(tmp != nullptr){
        cout << "Value: " << tmp->get_value() << " Priority: " << tmp->get_priority() << endl;
        tmp = tmp->get_next();
    }
}

int PriorityQueue::return_size() {
    return size;
}

Node *PriorityQueue::get_head() {
    return head;
}
