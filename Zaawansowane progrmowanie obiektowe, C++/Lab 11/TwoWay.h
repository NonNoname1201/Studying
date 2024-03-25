//
// Created by User on 12.01.2024.
//

#ifndef LAB_11_TWOWAY_H
#define LAB_11_TWOWAY_H

#include <memory>

template <typename T>
class Node
{
public:
    T data;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;

    Node(T data) : data(data), next(nullptr), prev(std::weak_ptr<Node<T>>()) {}
};

template <typename T>
class TwoWayList
{
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

public:
    TwoWayList() : head(nullptr), tail(nullptr) {}

    void pop_front()
    {
        if (head)
        {
            head = head->next;
            head->prev.reset();
        }
    }

    void pop_back()
    {
        if (tail)
        {
            tail = tail->prev.lock();
            tail->next.reset();
        }
    }

    void push_front(T data)
    {
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(data);
        if (head)
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        else
        {
            head = node;
            tail = node;
        }
    }

    void push_back(T data)
    {
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(data);
        if (tail)
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        else
        {
            head = node;
            tail = node;
        }
    }

    void printList()
    {
        std::shared_ptr<Node<T>> node = head;
        while (node)
        {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    void clear()
    {
        head.reset();
        tail.reset();
    }

    void getSize()
    {
        std::shared_ptr<Node<T>> node = head;
        int size = 0;
        while (node)
        {
            size++;
            node = node->next;
        }
        std::cout << size << std::endl;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    ~TwoWayList() {}
};

#endif // LAB_11_TWOWAY_H
