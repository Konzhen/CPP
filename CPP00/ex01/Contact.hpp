/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:41:13 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/11 03:28:59 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    Contact(std::string _firstName, std::string _lastName, std::string _nickName, std::string _phoneNumber, std::string _darkestSecret);
    ~Contact();
    std::string getFirstName();
    void setFirstName(std::string firstName);
    void addFirstName();
    std::string getLastName();
    void setLastName(std::string lastName);
    void addLastName();
    std::string getNickName();
    void setNickName(std::string nickName);
    void addNickName();
    std::string getPhoneNumber();
    void setPhoneNumber(std::string phoneNumber);
    void addPhoneNumber();
    std::string getDarkestSecret();
    void setDarkestSecret(std::string darkestSecret);
    void addDarkestSecret();
};