#include "Node.h"

Node::Node(int i_value, int i_priority) {
    value = i_value;
    priority = i_priority;
    next = nullptr;
}

int Node::get_value() {
    return value;
}

int Node::get_priority() {
    return priority;
}

Node *Node::get_next() {
    return next;
}

void Node::set_priority(int i_new_priority) {
    priority = i_new_priority;
}

void Node::set_next(Node *next_node) {
    next = next_node;
}

void Node::set_value(int i_new_value) {
    value = i_new_value;
}


