//
// Created by 易治行 on 2025/5/21.
//

#include "ContactBook.h"
#include "Contact.h"
#include <iostream>


int main(void) {
    ContactBook book = ContactBook();

    auto hang = new Contact("Zhihang Yi", "Chongqing, China", "14321849586");
    auto bella = new Contact("Bella", "Chongqing, China", "1863241879");
    auto ian = new Contact("Ian", "Chengdu, China", "13206118193");
    auto wayne = new Contact("Wayne", "Chengdu, China", "17765432918");
    auto jack = new Contact("Jack", "Zurich, Switzerland", "15643218765");

    book.add(hang);
    book.add(bella);
    book.add(ian);
    book.add(wayne);
    book.add(jack);

    auto one = book.search("Bella");
    std::cout << "address: " << one->get_address() << std::endl;;
    std::cout << "phone: " << one->get_phone() << std::endl;

    book.remove("Wayne");
    book.show();

    book.save();

    delete hang;
    delete bella;
    delete ian;
    delete wayne;
    delete jack;

    return 0;
}