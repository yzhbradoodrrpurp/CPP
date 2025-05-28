//
// Created by 易治行 on 2025/5/21.
//

#include "Contact.h"
#include "ContactBook.h"
#include <string>

Contact::Contact(std::string name, std::string address, std::string phone): name(name), address(address), phone(phone) {}

Contact::~Contact() {}

std::string Contact::get_address() {
    return address;
}

std::string Contact::get_phone() {
    return phone;
}