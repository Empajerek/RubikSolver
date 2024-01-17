#include "../include/fibonacci_queue.hpp"

template <typename T>
Fibonacci_queue<T>::Fibonacci_queue(){
    head = nullptr;
}

template<typename T>
void Fibonacci_queue<T>::PrintQueue(){
    // TO DO
}

template <typename T>
void Fibonacci_queue<T>::Insert(T value){
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>();
    new_node->left = new_node;
    new_node->right = new_node;
    new_node->parent = nullptr;
    new_node->child = nullptr;
    new_node->value = value;
    new_node->degree = 0;
    if(head == nullptr){
        head = new_node;
        return;
    }
    Union(head, new_node);
    if(new_node->value < head->value)
        head = new_node;
}

template <typename T>
T Fibonacci_queue<T>::Show_min(){
    return head->value;
}

template <typename T>
void Fibonacci_queue<T>::UniteTwoRoots(std::shared_ptr<Node<T>> a, 
                                       std::shared_ptr<Node<T>> b){
    if(a->value > b->value){
        Node<T> temp = a;
        a = b;
        b = temp;
    }
    a->degree++;
    b->parent = a;
    b->left->right = b->right;
    b->right->left = b->left;
    Union(a->child, b);
}

template <typename T>
void Fibonacci_queue<T>::Union(std::shared_ptr<Node<T>> a, 
                               std::shared_ptr<Node<T>> b){
    b->left->right = a->right;
    a->right->left = b->left;
    a->right = b;
    b->left = a;
}

template <typename T>
void Fibonacci_queue<T>::Put_into_vector(
    std::vector<std::shared_ptr<Node<T>>> &degrees, 
    std::shared_ptr<Node<T>> node){
    if(degrees[node->degree] == nullptr){
        degrees[node->degree] = &node;
        return;
    }
    Unite(node, degrees[node->degree]);
    if((long long)node->degree > degrees.size())
        degrees.resize(node->degree + 1, nullptr);
    Put_into_vector(degrees, node);
}

template <typename T>
T Fibonacci_queue<T>::Extract_min(){
    if(head == nullptr)
        return NULL;
    T min = head->value;
    if(head->left == head){
        head = nullptr;
        return min;
    }
    // Remove head
    Union(head->child, head);
    // add its nodes
    head->left->right = head->right;
    head->right->left = head->left;
    // Move head
    head = head->left;
    std::shared_ptr<Node<T>> minNode = head, temp = head;
    int n = 0;
    std::vector<Node<T>*> roots;
    do{
        if(temp->value < min->value)
            minNode = temp->value;
        if(n < temp->degree)
            n = temp->degree;
        temp = temp->right;
        roots.push_back(temp);
    }while(temp != head);
    std::vector<Node<T>*> degrees(n+1, nullptr);
    for(auto node : roots)
        Put_into_vector(degrees, node);
    head = minNode;
    return min;
}