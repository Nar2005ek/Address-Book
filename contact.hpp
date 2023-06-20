#include <iostream>
#include <fstream>
#include "contact.h"

std::string Contact::fullName() const {
    return m_fullName;
}

std::string Contact::phoneNumber() const {
    return m_phoneNumber;
}

std::string Contact::mail() const {
    return m_mail;
}

void Contact::setFullName() {
    do {
        std::cout << "Please Enter Full Name" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, m_fullName);
    } while(m_fullName.size() == 0);
}

void Contact::setPhoneNumber() {
    do {
        std::cout << "Please Enter Phone Number" << std::endl;
        // std::cin >> m_phoneNumber;
        std::getline(std::cin, m_phoneNumber);
    } while (!isValidPhoneNumber(m_phoneNumber));
}

void Contact::setMail() {
    do {
        std::cout << "Please Enter Mail" << std::endl;
        // std::cin >> m_mail;
        std::getline(std::cin, m_mail);
    } while (!isValidMail(m_mail));
}

bool Contact::isValidPhoneNumber(std::string phoneNumber) const {
    if(phoneNumber.size() != 9 || phoneNumber[0] != '0') {
        return false;
    }
    return true;
}

bool Contact::isValidMail(std::string mail) const {
    if(mail.size() <= 10) {
        return false;
    }
    std::string tmp = mail.substr(mail.size() - 10);
    if (tmp == "@gmail.com" || tmp == "@email.com") {
        return true;
    }
    return false;
}

Contact::Contact(const Contact& other) {
    m_fullName = other.m_fullName;
    m_phoneNumber = other.m_phoneNumber;
    m_mail = other.m_mail;
}

Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        m_fullName = other.m_fullName;
        m_phoneNumber = other.m_phoneNumber;
        m_mail = other.m_mail;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << '\t' << "Full Name: " << contact.fullName() << std::endl;
    os << '\t' << "Phone Number: " << contact.phoneNumber() << std::endl;
    os << '\t' << "Mail: " << contact.mail() << std::endl;
    return os;
}
