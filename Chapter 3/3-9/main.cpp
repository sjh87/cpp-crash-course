#include <cstdlib>
#include <cstdio>

struct Node {
    Node* next{};
    Node* previous{};

    void insertAfter(Node* newElement) {
        Node* next = this->next;
        this->next = newElement;
        newElement->next = next;
        newElement->previous = this;
        if (next) next->previous = newElement;
    }

    void insertBefore(Node* newElement) {
        Node* previous = this->previous;
        this->previous = newElement;
        newElement->next = this;
        newElement->previous = previous;
        if (previous) previous->next = newElement;
    }

    char prefix[3];
    short operatingNumber;
};

int main(void) {
    Node head{nullptr, nullptr, "PT", 123};
    Node second{nullptr, nullptr, "TP", 234};
    Node third{nullptr, nullptr, "PP", 345};
    Node tail{nullptr, nullptr, "TT", 456};

    Node extra{nullptr, nullptr, "SS", 69};

    head.insertAfter(&second); // make
    second.insertAfter(&third); // a nice little
    third.insertAfter(&tail); // doubly-linked list

    third.insertBefore(&extra); // insert a node and hopefully not mess it up

    Node* current = &head;

    while (current) { // forwards traversal
        printf("Storm Trooper %s-%d, reporting for doo-doo\n", current->prefix, current->operatingNumber);
        current = current->next;
    }

    current = &tail;

    while (current) { // backwards traversal
        printf("Storm Trooper %s-%d, reporting for doo-doo\n", current->prefix, current->operatingNumber);
        current = current->previous;
    }

    return EXIT_SUCCESS;
}
