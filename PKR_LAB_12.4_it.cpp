#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <windows.h>


class Node {
public:
    int value;
    Node* next;
};

void addNode(Node** head_ref, int new_value) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->value = new_value;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    while (last->next != *head_ref)
        last = last->next;

    last->next = new_node;
    new_node->next = *head_ref;
}

void printList(Node* head) {
    if (head != NULL) {
        Node* temp = head;
        do {
            std::cout << temp->value << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
}

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    Node* current = head;
    if (head != NULL) {
        do {
            if (current->value >= 0)
                addNode(head1_ref, current->value);
            else
                addNode(head2_ref, current->value);

            current = current->next;
        } while (current != head);
    }
}

void generateList(Node** head_ref, int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        int random_value = rand() % 100 - 50;
        addNode(head_ref, random_value);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;

    generateList(&head, 10);

    std::cout << "Вихідний список: ";
    printList(head);

    splitList(head, &head1, &head2);

    std::cout << "Список з додатними числами: ";
    printList(head1);

    std::cout << "Список з від'ємними числами: ";
    printList(head2);

    return 0;
}
