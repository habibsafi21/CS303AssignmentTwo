#include <iostream>

template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

    // Insert at front
    void push_front(const T& item) {
        Node* new_node = new Node{ item, head };
        head = new_node;
        if (!tail) tail = head; // If list was empty
        num_items++;
    }

    // Insert at back
    void push_back(const T& item) {
        Node* new_node = new Node{ item, nullptr };
        if (tail) tail->next = new_node;
        tail = new_node;
        if (!head) head = tail; // If list was empty
        num_items++;
    }

    // Remove from front
    void pop_front() {
        if (head) {
            Node* old_head = head;
            head = head->next;
            delete old_head;
            num_items--;
            if (!head) tail = nullptr; // If list becomes empty
        }
    }

    // Remove from back
    void pop_back() {
        if (head) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            }
            else {
                Node* temp = head;
                while (temp->next != tail) temp = temp->next;
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
            num_items--;
        }
    }

    // Return first element
    T front() const {
        if (head) return head->data;
        throw std::out_of_range("List is empty");
    }

    // Return last element
    T back() const {
        if (tail) return tail->data;
        throw std::out_of_range("List is empty");
    }

    // Check if list is empty
    bool empty() const {
        return head == nullptr;
    }

    // Insert at index
    void insert(size_t index, const T& item) {
        if (index > num_items) return; // Out of bounds
        if (index == 0) {
            push_front(item);
        }
        else if (index == num_items) {
            push_back(item);
        }
        else {
            Node* temp = head;
            for (size_t i = 0; i < index - 1; ++i)
                temp = temp->next;
            temp->next = new Node{ item, temp->next };
            num_items++;
        }
    }

    // Remove at index
    bool remove(size_t index) {
        if (index >= num_items) return false; // Out of bounds
        if (index == 0) {
            pop_front();
        }
        else {
            Node* temp = head;
            for (size_t i = 0; i < index - 1; ++i)
                temp = temp->next;
            Node* to_delete = temp->next;
            temp->next = to_delete->next;
            delete to_delete;
            num_items--;
            if (temp->next == nullptr) tail = temp; // Adjust tail
        }
        return true;
    }

    // Find an element
    size_t find(const T& item) const {
        Node* temp = head;
        size_t index = 0;
        while (temp) {
            if (temp->data == item) return index;
            temp = temp->next;
            index++;
        }
        return num_items; // Return size if not found
    }
};