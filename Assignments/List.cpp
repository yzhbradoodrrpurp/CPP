//
// Created by 易治行 on 2025/5/7.
//

#include <iostream>

using namespace std;

template <class T>

class List {

private:
    T value;
    List* previous;
    List* next;

public:
    List(): value(0), previous(nullptr), next(nullptr) {}
    List(T value): value(value), previous(nullptr), next(nullptr) {}

    ~List(){}

    void append(T value) {

        List* p = this;

        while (p->next != nullptr)
            p = p->next;

        p->next = new List(value);
        p->next->previous = this;
    }

    int length() {
        int len = 1;
        List* p = this;

        while (p->next != nullptr) {
            p = p->next;
            len += 1;
        }

        return len;
    }

    void remove(int idx) {
        int len = length();

        if (idx >= len) {
            cout << "The index is out of range." << endl;
            return;
        }

        int current_idx = 0;
        List* p = this;

        while (current_idx < idx) {
            p = p->next;
            current_idx += 1;
        }

        p->previous->next = p->next;
        p->next->previous = p->previous;
    }

    List* search(T value) {
        List* p = this;

        while (p != nullptr) {
            if (p->value == value)
                return p;

            p = p->next;
        }

        return nullptr;
    }

    void insert(T value, int idx) {
        int len = length();

        if (idx >= len) {
            cout << "The index is out of range." << endl;
            return;
        }

        int current_idx = 0;
        List*p = this;

        while (current_idx < idx) {
            current_idx += 1;
            p = p->next;
        }

        auto new_node = new List(value);

        p->previous->next = new_node;
        new_node->previous = p->previous;
        p->previous = new_node;
        new_node->next = p;
    }

    friend ostream& operator<<(ostream&, const List<int>*);

};

ostream& operator<<(ostream& out, const List<int>* l) {
    auto p = l;

    while (p != nullptr) {
        out << p->value << "\t";
        p = p->next;
    }

    return out;
}


int main() {

    auto p = new List<int>(10);

    p->append(15);
    p->append(30);
    p->append(50);
    cout << p << endl;

    auto x = p->search(30);
    cout << x << endl;

    p->remove(1);
    cout << p << endl;

    p->insert(60, 1);
    cout << p << endl;

    return 0;
}