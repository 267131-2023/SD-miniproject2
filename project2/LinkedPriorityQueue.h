#include "Node.h"

using namespace std;

class PriorityQueue{
private:
    Node* head;
    int size;
public:
    PriorityQueue();
    void insert(int element, int i_priority);
    tuple<int, int> extract_max();
    tuple<int, int> peek();
    void modify_key(int element, int i_priority);
    int return_size();
    void display_queue();
    Node* get_head();

};
