//
// Created by 易治行 on 2025/5/7.
//

#include <iostream>
#include <string>

using namespace std;

template <class T>

class Library {

private:
    T value;
    Library* previous;
    Library* next;

public:
    Library(T value): value(value), previous(nullptr), next(nullptr) {}

    ~Library() {
        Library* last = this;

        while (last != nullptr)
            last = last->next;

        while (last != nullptr) {
            Library* next_last = last->previous;
            delete last;
            last = next_last;
        }
    }

    void append(T value) {

        Library* p = this;

        while (p->next != nullptr)
            p = p->next;

        p->next = new Library(value);
        p->next->previous = this;
    }

    int length() {
        int len = 1;
        Library* p = this;

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
        Library* p = this;

        while (current_idx < idx) {
            p = p->next;
            current_idx += 1;
        }

        p->previous->next = p->next;
        p->next->previous = p->previous;
    }

    Library* search(T value) {
        Library* p = this;

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

        if (idx == 0) {
            cout << "`idx` == 0 is not allowed." << endl;
            return;
        }

        int current_idx = 0;
        Library*p = this;

        while (current_idx < idx) {
            current_idx += 1;
            p = p->next;
        }

        auto new_node = new Library(value);

        p->previous->next = new_node;
        new_node->previous = p->previous;
        p->previous = new_node;
        new_node->next = p;
    }

    friend ostream& operator<<(ostream&, const Library<int>*);
    friend ostream& operator<<(ostream& , const Library<string>*);
};

ostream& operator<<(ostream& out, const Library<int>* l) {
    auto p = l;

    while (p != nullptr) {
        out << p->value << "\t";
        p = p->next;
    }

    return out;
}

ostream& operator<<(ostream& out, const Library<string>* l) {
    auto p = l;

    while (p != nullptr) {
        out << p->value << "\t";
        p = p->next;
    }

    return out;
}


int main() {
    Library<string>* lib = new Library<string>("憨豆先生");

    lib->append("斗罗大陆");
    lib->append("红楼梦");
    lib->append("斗破苍穹");
    lib->append("淘气包马小跳");
    lib->append("暴走漫画");

    cout << lib << endl;

    lib->insert("校花的贴身保镖", 2);

    cout << lib << endl;

    delete lib;

    return 0;
}
