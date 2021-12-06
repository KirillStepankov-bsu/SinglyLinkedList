#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

template<typename T>
class List {
public:
    List() : size(0), head(nullptr) {};

    ~List();

    void push_back(T data);

    void pop_front();

    void clear();

    void push_front(T data);

    void removeAt(int index);

    void pop_back();

    void insert(const T &value, int index);

    [[nodiscard]] int getSize() const { return size; }

    T &operator[](int index);

private:
    template<typename A>
    class Node {
    public:
        Node *pNext;
        A data;

        Node(A m_data = A(), Node *m_pNext = nullptr) : data(m_data), pNext(m_pNext) {}
    };

    int size;
    Node<T> *head;
};

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    size++;
}

template<typename T>
T &List<T>::operator[](const int index) {
    Node<T> *current = head;
    int counter = 0;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::pop_front() {
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    temp = nullptr;
    size--;
}

template<typename T>
void List<T>::clear() {
    while (size) pop_front();
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    size++;
}

template<typename T>
void List<T>::insert(const T &value, int index) {
    if (index == 0) {
        push_front(value);
        return;
    }

    Node<T> *current = head;
    int counter = 0;
    while (counter != index) {
        current = current->pNext;
        counter++;
    }
    Node<T> *ins = new Node<T>(current->data, current->pNext);
    current->pNext = ins;
    current->data = value;
    size++;
}

template<typename T>
void List<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
        return;
    }

    Node<T> *current = head;
    int counter = 0;
    while (counter != index - 1) {
        current = current->pNext;
        counter++;
    }
    Node<T> *temp = current->pNext;
    current->pNext = temp->pNext;

    delete temp;

    size--;
}

template<typename T>
void List<T>::pop_back() {
    removeAt(size-1);
}


#endif
