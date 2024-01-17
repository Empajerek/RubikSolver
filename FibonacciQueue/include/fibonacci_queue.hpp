#ifndef FIBONACCI_QUEUE_H
#define FIBONACCI_QUEUE_H

#include <memory>
#include <vector>

template <typename T>
struct Node {
    std::shared_ptr<Node<T>> left, right, parent, child;
    int degree;
    T value;
    Node() {};
};

template <typename T>
class Fibonacci_queue {
    private:

        std::shared_ptr<Node<T>> head;

    public:

        /**
         * @brief Construct a new Fibonacci_queue object
         */
        Fibonacci_queue();

        /**
         * @brief Put a value into the queue.
         * 
         * @param  T inserted value.
         */
        void Insert(T);

        /**
         * @brief Show current minimal value in the queue.
         * 
         * @return T - Minimal value.
         */
        T Show_min();

        /**
         * @brief Return current minimal value, and delete it.
         * 
         * @return T - Minimal value
         */
        T Extract_min();

        /**
         * @brief Prints current queue in tree form.
         * 
         */
        void PrintQueue();

    private:

        /**
         * @brief Turn two root nodes into one by appending bigger to list of
         * smaller children.
         */
        void UniteTwoRoots(std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>);

        /**
         * @brief Take union of two nodes by linking them.
         */
        void Union(std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>);

        /**
         * @brief Helper function for putting nodes into vector by their degrees.
         */
        void Put_into_vector(std::vector<std::shared_ptr<Node<T>>> &, std::shared_ptr<Node<T>>);
};

#endif // !FIBONACCI_QUEUE_H