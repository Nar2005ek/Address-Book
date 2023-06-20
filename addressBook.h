#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
#include <vector>
#include "contact.h"

class AddressBook {
public:
    void remove();
    void push();
    void seeAllContacts() const;
    void file() const;
    void commands();
private:
    std::vector<Contact> m_book;
};
#include "addressBook.hpp"

#endif // ADDRESSBOOK_H
