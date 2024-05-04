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
    }
    else{

        if(element->get_priority() > head->get_priority()){
            element->set_next(head);
            head = element;
        }

        else{
            Node* prev_node = head;
            Node* tmp_node = head->get_next();
            while(prev_node->get_next() != nullptr && i_priority <= tmp_node->get_priority()){
                tmp_node = tmp_node->get_next();
                prev_node = prev_node->get_next();
            }
            element->set_next(tmp_node);
            prev_node->set_next(element);
            }
        }
    size++;
}


tuple<int, int> PriorityQueue::extract_max() {
    if (head == nullptr) { // lista jest pusta
        cout << "Lista jest pusta" << endl;
    }
    if (head->get_next() == nullptr) {// lista zawiera tylko jeden element
        int value = head -> get_value();
        int priority = head -> get_priority();
        delete head;
        head = nullptr;
        size--;
        return make_tuple(value, priority);
    }
    Node* current_node = head->get_next();
    int value = head ->get_value();
    int priority = head -> get_priority();
    delete head;
    head = current_node;
    size--;
    return make_tuple(value, priority);
}

tuple<int, int> PriorityQueue::peek() {
    if (head == nullptr) { // lista jest pusta
        cout << "Lista jest pusta" << endl;
    } else{
        return make_tuple(head->get_value(), head->get_priority());
    }
}

void PriorityQueue::modify_key(Node* element, int i_priority) {
    if (element == nullptr) {
        std::cout << "Podany węzeł nie istnieje\n";
        return;
    }
    int initial_priority = element->get_priority();
    if (i_priority < initial_priority) {
        if (element == head) {
            extract_max();
            insert(element->get_value(), i_priority);

        }
    }
}

void PriorityQueue::display_queue() {
    Node* tmp = head;

    while(tmp != nullptr){
        cout << "Value: " << tmp->get_value() << " Priority: " << tmp->get_priority() << endl;
        tmp = tmp->get_next();
    }
}

void modify_key(Node* element, int i_priority){
    
}

int PriorityQueue::return_size() {
    return size;
}

Node *PriorityQueue::get_head() {
    return head;
}
