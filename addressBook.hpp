#include <iostream>
#include <fstream>
#include "addressBook.h"

void AddressBook::seeAllContacts() const {
    for(int i = 0; i < m_book.size(); ++i) {
        std::cout << "Contact" << i + 1 << " {" << std::endl;
        std::cout <<  m_book[i] << '}' << std::endl;
    }
}

void AddressBook::remove() {
    std::string str;
    do {
        std::cout << "Please Enter Phone Number" << std::endl;
        std::cin >> str;
    } while(str.size() != 9 || str[0] != '0');
    for (int i = 0; i < m_book.size(); ++i) {
        if (m_book[i].phoneNumber() == str) {
            m_book.erase(i + m_book.begin());
            std::cout << "Element Removed Successfully" << std::endl;
            file();
            return;
        }
    }
    std::cout << "No Such Element" << std::endl;
}

void AddressBook::push() {
    Contact ct;
    ct.setFullName();
    ct.setMail();
    ct.setPhoneNumber();
    m_book.push_back(ct);
    file();
}

void AddressBook::file() const {
    std::remove("address_book.txt");
    std::ofstream out("address_book.txt");
    if(out.is_open()) {
        for(int i = 0; i < m_book.size(); ++i) {
            out << m_book[i];
        }
        out.close();
    }
}

void AddressBook::commands() {
    std::string command;
    do {
        std::cout << "Coose The Option" << std::endl;
        std::cout << "   addElement" << std::endl <<  "   removeElement" << std::endl << "   seeAllContacts" << std::endl << "   exit" << std::endl;
        std::cin >> command;
        if(command == "addElement") {
            // std::cout << "aaa" << std::endl;
            push();
        }
        if(command == "removeElement") {
            remove();
        }
        if(command == "seeAllContacts") {
            seeAllContacts();
        }
    } while(command != "exit");
}