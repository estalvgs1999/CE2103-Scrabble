#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"
using namespace std;

class List {
private:
    Node *head;

public:

    List() {
        head = nullptr;
    }

    void addHead(string data) {
        Node *newHead = new Node(data);
        newHead->setNextNode(head);
        head = newHead;
    }

    void deleteNode(string data) {
        Node* node = head;
        if(!searchNode(data)) return;
        if(node->getData() == data){
            head = node->getNextNode();
            delete(node);
        }else{
            while(node->getNextNode()->getData() != data)
                node = node->getNextNode();
            Node *nodeToDelete = node->getNextNode();
            node->setNextNode(nodeToDelete->getNextNode());
            delete(nodeToDelete);
        }
    }

    Node *searchNode(string data) {
        for(Node *node = head; node; node = node->getNextNode()) {
            if (node->getData().compare(data) == 0) return node;
        }return nullptr;
    }

    void printList() {
        cout << "List ([Data | Memory Address]): ";
        for(Node *node = head; node != nullptr; node = node->getNextNode())
            cout<<node->getData()<<endl;
        cout << "NULL" << endl;
    }
};

#endif LINKEDLIST_HPP
