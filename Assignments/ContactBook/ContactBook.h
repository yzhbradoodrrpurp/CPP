//
// Created by 易治行 on 2025/5/21.
//

#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <vector>

class Contact;

class ContactBook {

private:
    std::vector<Contact*> contacts;

public:
    ContactBook();
    ~ContactBook();

    void add(Contact*);

    Contact* search(std::string);

    void remove(std::string);

    void save();

    void show();
};

#endif //CONTACTBOOK_H
