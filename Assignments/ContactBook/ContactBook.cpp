//
// Created by 易治行 on 2025/5/21.
//

#include "ContactBook.h"
#include "Contact.h"
#include <fstream>
#include <iostream>


ContactBook::ContactBook() {}
ContactBook::~ContactBook(){}


void ContactBook::add(Contact* contact) {
    contacts.push_back(contact);
}

Contact* ContactBook::search(std::string name) {
    for (auto contact: contacts) {
        if (contact->name == name)
            return contact;
    }

    return nullptr;
}

void ContactBook::remove(std::string name) {
    int idx = 0;

    for (auto contact: contacts) {
        if (contact->name == name)
            break;
        idx++;
    }

    if ((idx == 0 and contacts[0]->name == name) or idx != 0)
        contacts.erase(contacts.begin() + idx);
    else
        std::cout << name << " is not in the contact book." << std::endl;
}

void ContactBook::save() {
    std::ofstream file("contacts.csv");

    if (file.is_open()) {
        for (auto contact: contacts)
            file << contact->name << ", " << contact->address << ", " << contact->phone << std::endl;
        file.close();

        std::cout << "Successfully saved." << std::endl;
    }
    else
        std::cout << "error opening file" << std::endl;
}

void ContactBook::show() {
    for (auto contact: contacts)
        std::cout << contact->name << ", " << contact->address << ", " << contact->phone << std::endl;
}


