//
// Created by 易治行 on 2025/5/21.
//

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class ContactBook;

class Contact {
private:
    std::string name;
    std::string address;
    std::string phone;

public:
    Contact(std::string name, std::string address, std::string phone);
    ~Contact();

    std::string get_address();

    std::string get_phone();

    friend class ContactBook;
};

#endif //CONTACT_H
