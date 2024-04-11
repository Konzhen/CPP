/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:50:38 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/11 03:28:55 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

    Contact::Contact()
    {
        
    }

    Contact::Contact(std::string _firstName, std::string _lastName, std::string _nickName, std::string _phoneNumber, std::string _darkestSecret)
    {
        setFirstName(_firstName);
        setLastName(_lastName);
        setNickName(_nickName);
        setPhoneNumber(_phoneNumber);
        setDarkestSecret(_darkestSecret);
    }

    Contact::~Contact()
    {

    }

    std::string Contact::getFirstName()
    {
        return this->_firstName;
    }

    void Contact::setFirstName(std::string firstName)
    {
        this->_firstName = firstName;
    }

    void Contact::addFirstName()
    {
        std::string firstName;

        std::cout << "Firstname :" << std::endl;
        std::cout << "-> ";
        getline(std::cin, firstName);
        if ((firstName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos || firstName.empty()) && std::cin)
        {
            std::cout << "Wrong Firstname as parameter." << std::endl;
            addFirstName();
        }
        else
            Contact::setFirstName(firstName);
    }

    std::string Contact::getLastName()
    {
        return this->_lastName;
    }

    void Contact::setLastName(std::string lastName)
    {
        this->_lastName = lastName; 
    }

    void Contact::addLastName()
    {
        std::string lastName;

        std::cout << "Lastname :" << std::endl;
        std::cout << "-> ";
        getline(std::cin, lastName);
        if ((lastName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos || lastName.empty()) && std::cin)
        {
            std::cout << "Wrong Lastname as parameter." << std::endl;
            addLastName();
        }
        else
            Contact::setLastName(lastName);
    }

    std::string Contact::getNickName()
    {
        return this->_nickName;
    }

    void Contact::setNickName(std::string nickName)
    {
        this->_nickName = nickName; 
    }

    void Contact::addNickName()
    {
        std::string nickName;

        std::cout << "Nickname :" << std::endl;
        std::cout << "-> ";
        getline(std::cin, nickName);
        if ((nickName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos || nickName.empty()) && std::cin)
        {
            std::cout << "Wrong Nickname as parameter." << std::endl;
            addNickName();
        }
        else
            Contact::setNickName(nickName);
    }

    std::string Contact::getPhoneNumber()
    {
        return this->_phoneNumber;
    }

    void Contact::setPhoneNumber(std::string phoneNumber)
    {
        this->_phoneNumber = phoneNumber; 
    }

    void Contact::addPhoneNumber()
    {
        std::string phoneNumber;

        std::cout << "PhoneNumber :" << std::endl;
        std::cout << "-> ";
        getline(std::cin, phoneNumber);
        if ((phoneNumber.find_first_not_of("0123456789") != std::string::npos || phoneNumber.empty() || phoneNumber.length() != 10) && std::cin)
        {
            std::cout << "Wrong PhoneNumber as parameter." << std::endl;
            addPhoneNumber();
        }
        else
            Contact::setPhoneNumber(phoneNumber);
    }

    std::string Contact::getDarkestSecret()
    {
        return this->_darkestSecret;
    }

    void Contact::setDarkestSecret(std::string darkestSecret)
    {
        this->_darkestSecret = darkestSecret; 
    }

    void Contact::addDarkestSecret()
    {
        std::string darkestSecret;

        std::cout << "Darkest Secret :" << std::endl;
        std::cout << "-> ";
        getline(std::cin, darkestSecret);
        if (darkestSecret.empty() && std::cin)
        {
            std::cout << "Wrong DarkestSecret as parameter." << std::endl;
            addDarkestSecret();
        }
        else
            Contact::setDarkestSecret(darkestSecret);
    }
