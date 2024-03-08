// Sarah Miller
// Assignment 2

#include <iostream>

template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data; // stores data for this node
        Node* next; // a pointer to the next node in the linked list. it points to another node struct.
        Node(const Item_Type& data_item, Node* next_ptr = nullptr) // constructor of the node. it has two parameters and a pointer.
            : data(data_item), next(next_ptr) {} // this is the initializier list of the constructor. 
    };

    Node* head; // pointer to the first node of the linked list
    Node* tail; // pointer to the last node (tail) of the linked list.
    size_t num_items; // a variable that stores the # of nodes in the linked list. It keeps track of the current size of the list.

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {} // constructor of the single_linked_list class. initializes head pointer, tail pointer, and num_items variable. Sets 'head' and 'tail' to nullpointer.

    ~Single_Linked_List() { // Deconstructor of the single_linked_list class. It cleans up memory in the nodes in the linked list. It does by calling the pop_front function until the list is empty, empty_() returns true.
        while (!empty()) {
            pop_front();
        }
    }

    void push_front(const Item_Type& item) { //  defines the push_front function of the Single_linked_list class.
        Node* new_node = new Node(item, head); // this line creates a new node object with item as its data and head as its next pointer. 
        head = new_node; // updates the head pointer of the list to the newly created node.
        if (num_items == 0) { // checks the list if it is empty before adding the new node.
            tail = new_node; //  If it was, it sets the tail pointer of the list to point to the new node, since in a list with only one node, the head and tail are the same.
        }
        ++num_items; // increments the num_items to reflect addition of the new nnode.
    }

    void push_back(const Item_Type& item) { // defines the push_back function for a single linked list. Takes item-type as its argument. 
        Node* new_node = new Node(item); // object using new keyward. initializes the new node with the provided item. 
        if (empty()) { // checks if the list is empty. Sets head pinter of the list to point to the new node making the new node the head of the list.
            head = new_node; 
        } else {
            tail->next = new_node; 
        }
        tail = new_node; // updates the tail pointer
        ++num_items; // increments to reflect the new node.
    }

    void pop_front() { // defines the pop front function. Which does not take any arguments becase it is a void function.
        if (empty()) { // line checks if the list is empyty. the func returns w/o performing any further actions as there is no node in the list.
            return;
        }
        Node* temp = head; // creates a temp pointer to temp and assigns its value to head pointer. 
        head = head->next; // updates the head pointer to the next node in the list.
        delete temp; // this line deallocates the memory occupied by the node that was originally the head of the list, thus removing it from the list.
        --num_items; // decrements the counter of the list to reflect the removal of the node.
        if (num_items == 0) { // checks if the list is empty.
            tail = nullptr; // no nodes left.
        }
    }

    void pop_back() { // function with no arguments bc it is a void func
        if (empty()) { // line checks if the list is empty.
            return; 
        }
        if (num_items == 1) { // checks if there is an item in the list
            delete tail; // if there is an item, this line deletes the memory where the node was that was last of the list.
            head = tail = nullptr; // sets both head and tail pointers to nullptr. suggesting that the list is empty.
            --num_items; // decrements to show the removal of the node.
            return;
        }
        Node* current = head; // this line initializes a ptr current to the head of the list.
        while (current->next != tail) { // a loop that iterates throught the list until current points to the node before tail.
            current = current->next; // 
        }
        delete tail;
        tail = current;
        tail->next = nullptr; // sets the next pointer of the new tail node, suggesting the end of a list.
        --num_items; // decrements to show the removal of the tail node.
    }

    Item_Type front() const { // returns item_type as object. Is declared as const which means that it does not change the list.
        if (empty()) { // echicks if the list is empty using the empty func. 
            throw std::logic_error("List is empty"); // if the list is empty it throws a logic error message saying the list is empty.
        }
        return head->data; // if the list is not empty, this line returns the data member of the head node, which is the first node in the list.
    }

    Item_Type back() const { // declares the back function which returns item_type object. the function is marked as const, indicating that it does not change the list.
        if (empty()) { // line checks if the list is empty using the empty func. 
            throw std::logic_error("List is empty"); // if it is empty we tell the user that the "list is empty"
        }
        return tail->data; // if the list is not empty, this line returns the tail node, which is the last node on the list.
    }

    bool empty() const { // line declares the empty function which returns a bool. const means the list doesn't change.
        return num_items == 0; // line returns true if the number of items in the list is equal to 0. If not then it returns false.
    }

    void insert(size_t index, const Item_Type& item) { // declares insert function that takes an index and an object item_type as agruments.
        if (index > num_items) { // checks if the specific index is greater than the # of items in the list.
            index = num_items; // if it is, than we set the specific index equal to the num_items. inserting the new node at the end of the list.
        }
        if (index == 0) { // checks if index is equal to 0. 
            push_front(item); // inserts the new node at the beginning of the list.
        } else if (index == num_items) { // checks if the index is = to the # of items in a list. if it is:
            push_back(item); // we call back the push_back() to insert the new node at the end of the list.
        } else {
            Node* current = head; // initializes a pointer to current, to the head of the list.
            for (size_t i = 0; i < index - 1; ++i) { // iterates through the loop, moving current to the node just before the index
                current = current->next; 
            }
            Node* new_node = new Node(item, current->next); // creates a node object "new_node" with item and its next ptr to the node that current is pointing to.
            current->next = new_node; // updates the ptr of current to new node, inserting the new node into the list.
            ++num_items;
        }
    }

    bool remove(size_t index) { // declares the remove() that takes index as an argument and returns a bool, suggesting the removal was successful.
        if (index >= num_items) { 
            return false;
        }
        if (index == 0) { // line checks if index is 0. if it is it calls the popfront () to remove the first node in the list.
            pop_front();
        } else { // if the index is not 0, the following code is executed.
            Node* current = head; // initilizes curretn to head.
            for (size_t i = 0; i < index - 1; ++i) { // iteraties through the list using a loop, moving current to the node just before the index node.
                current = current->next; 
            }
            Node* temp = current->next; // temp ptr and is assigned to the nxt ptr of current, which points to the node to be removed.
            current->next = temp->next;
            delete temp;
            --num_items;
        }
        return true;
    }

    size_t find(const Item_Type& item) { // decalres the find () which takes an item_type object as an argument and returns num_items
        size_t index = 0; // initializes size_t index to 0. this will be used to store the index
        Node* current = head; // initializes a ptr current to the head of the list
        while (current != nullptr) { // iterates throught the list until current reaches the end of the list
            if (current->data == item) { // inside the loop, it checks if the data of the current node is = to the specific item. if they are equal it reutrns the index.
                return index;
            }
            current = current->next;
            ++index;
        }
        return num_items;
    }
};
 
int main() {
    Single_Linked_List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.insert(1, 10);

    std::cout << "List: ";
    for (size_t i = 0; i < list.find(10); ++i) {
        std::cout << list.front() << " ";
        list.pop_front();
    }
    std::cout << list.front() << std::endl;

    return 0;
}
