#include "iostream"
#include "LinkedPriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue() {
    head = nullptr;
    size = 0;
}

void PriorityQueue::insert(int element, int i_priority) {
    Node* node = new Node(element, i_priority);
    if (head == nullptr) { // Jeœli lista jest pusta
        head = node;
    }
    else {
        if (i_priority > head->get_priority()) { // Jeœli nowy wêze³ ma wy¿szy priorytet ni¿ g³owa
            node->set_next(head);
            head = node;
        }
        else {
            Node* prev_node = head;
            Node* tmp_node = head->get_next();
            // Znajdowanie poprawnej pozycji do wstawienia nowego wêz³a
            while (prev_node->get_next() != nullptr && i_priority <= tmp_node->get_priority()) {
                tmp_node = tmp_node->get_next();
                prev_node = prev_node->get_next();
            }
            node->set_next(tmp_node);
            prev_node->set_next(node);
        }
    }
    size++;
}

tuple<int, int> PriorityQueue::extract_max() {
    if (head == nullptr) { // Jeœli lista jest pusta
        cout << "Lista jest pusta" << endl;
    }
    if (head->get_next() == nullptr) {
        int value = head->get_value();
        int priority = head->get_priority();
        delete head;
        head = nullptr;
        size--;
        return make_tuple(value, priority);
    }
    Node* current_node = head->get_next();
    int value = head->get_value();
    int priority = head->get_priority();
    delete head;
    head = current_node;
    size--;
    return make_tuple(value, priority);
}

tuple<int, int> PriorityQueue::peek() {
    if (head == nullptr) { // Jeœli lista jest pusta
        cout << "Lista jest pusta" << endl;
        return make_tuple(-1, -1);
    }
    return make_tuple(head->get_value(), head->get_priority());
}

void PriorityQueue::modify_key(int element, int i_priority) {
    if (head == nullptr) { // Jeœli lista jest pusta
        std::cout << "Kolejka jest pusta\n";
        return;
    }

    Node* current_node = head;
    Node* prev_node = nullptr;

    // Znajdowanie wêz³a o podanej wartoœci
    while (current_node != nullptr && current_node->get_value() != element) {
        prev_node = current_node;
        current_node = current_node->get_next();
    }

    if (current_node == nullptr) { // Jeœli wêze³ nie istnieje
        std::cout << "Element " << element << " nie istnieje w kolejce\n";
        return;
    }

    // Decrease key
    if (i_priority < current_node->get_priority()) {
        current_node->set_priority(i_priority);
        if (prev_node != nullptr) {
            // Jeœli priorytet bie¿¹cego wêz³a jest mniejszy ni¿ jego poprzednika
            if (current_node->get_priority() < prev_node->get_priority()) {
                prev_node->set_next(current_node->get_next());
                Node* tmp_node = head;
                Node* prev_temp = nullptr;

                // Znajdowanie w³aœciwej pozycji do wstawienia bie¿¹cego wêz³a
                while (tmp_node != nullptr && tmp_node->get_priority() > i_priority) {
                    prev_temp = tmp_node;
                    tmp_node = tmp_node->get_next();
                }
                prev_temp->set_next(current_node);
                current_node->set_next(tmp_node);
            }
        }
        else {
            // Jeœli bie¿¹cy wêze³ jest g³ow¹
            Node* tmp_node = head->get_next();
            Node* prev_temp = head;

            // Znajdowanie w³aœciwej pozycji do wstawienia bie¿¹cego wêz³a
            while (tmp_node != nullptr && tmp_node->get_priority() > i_priority) {
                prev_temp = tmp_node;
                tmp_node = tmp_node->get_next();
            }

            head = current_node->get_next();
            prev_temp->set_next(current_node);
            current_node->set_next(tmp_node);
        }
    }
    // Increase key
    else if (i_priority > current_node->get_priority()) {
        current_node->set_priority(i_priority);
        if (prev_node != nullptr) {
            // Jeœli priorytet bie¿¹cego wêz³a jest wiêkszy ni¿ jego poprzednika
            if (current_node->get_priority() > prev_node->get_priority()) {
                prev_node->set_next(current_node->get_next());
                Node* tmp_node = head;
                Node* prev_temp = nullptr;

                // Znajdowanie w³aœciwej pozycji do wstawienia bie¿¹cego wêz³a
                while (tmp_node != nullptr && tmp_node->get_priority() > i_priority) {
                    prev_temp = tmp_node;
                    tmp_node = tmp_node->get_next();
                }
                if (prev_temp == nullptr) {
                    head = current_node;
                    current_node->set_next(tmp_node);
                }
                else {
                    prev_temp->set_next(current_node);
                    current_node->set_next(tmp_node);
                }
            }
        }
    }
}

void PriorityQueue::display_queue() {
    Node* tmp = head;
    while (tmp != nullptr) {
        cout << "Wartoœæ: " << tmp->get_value() << " Priorytet: " << tmp->get_priority() << endl;
        tmp = tmp->get_next();
    }
}


int PriorityQueue::return_size() {
    return size;
}

Node* PriorityQueue::get_head() {
    return head;
}
