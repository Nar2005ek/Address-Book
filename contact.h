#ifndef CONTACT
#define CONTACT
#include <iostream>
#include <vector>

class Contact {
public:
    Contact() = default;
    Contact(const Contact& other);
    ~Contact() = default;
    Contact& operator=(const Contact&);
    std::string fullName() const;
    std::string phoneNumber() const;
    std::string mail() const;
    void setFullName();
    void setPhoneNumber();
    void setMail();
    bool isValidPhoneNumber(std::string) const;
    bool isValidMail(std::string) const;
private:
    std::string m_fullName = "";
    std::string m_phoneNumber = "";
    std::string m_mail = "";
};
#include "contact.hpp"

#endif //CONTACT