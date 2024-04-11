/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:45:40 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/11 02:18:58 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():index(1)
{

}

PhoneBook::~PhoneBook()
{
    
}

void	PhoneBook::print_column(std::string arg)
{
	std::string	tmp;
	
    std::cout << std::setw(10);
	if (arg.length() > 9)
        std::cout << arg.substr(0, 9) + '.' ;        
    else
        std::cout << arg;
}

void PhoneBook::print_contact(int index)
{
    std::cout << this->contact[index].getFirstName() << std::endl;
    std::cout << this->contact[index].getLastName() << std::endl;
    std::cout << this->contact[index].getNickName() << std::endl;
    std::cout << this->contact[index].getPhoneNumber() << std::endl;
    std::cout << this->contact[index].getDarkestSecret() << std::endl;
}

void PhoneBook::add()
{
    if (this->index == 9)
        this->index = 1;
    this->contact[this->index - 1].addFirstName();
    this->contact[this->index - 1].addLastName();
    this->contact[this->index - 1].addNickName();
    this->contact[this->index - 1].addPhoneNumber();
    this->contact[this->index - 1].addDarkestSecret();
    this->index++;
}

void PhoneBook::search()
{
    std::string  n;
    
    if (this->contact[0].getFirstName().empty())
    {
        std::cout << "No contact yet in PhoneBook, please add at least one contact by printing \"ADD\" in the console" << std::endl;
        return ;
    }
    for (int i = 0; i < 8; i++)
    {
        if (this->contact[i].getFirstName().empty())
            break ;
        std::cout << std::setw(10);
        std::cout << i + 1 << " | ";
        print_column(this->contact[i].getFirstName());
        std::cout << " | ";
        print_column(this->contact[i].getLastName());
        std::cout << " | ";
        print_column(this->contact[i].getNickName());
        std::cout << std::endl;   
    }

    std::cout << "Choose a contact to display by printing its index" << std::endl;
    std::cout << "-> ";
    getline(std::cin, n);
    while (((std::atoi(n.c_str()) > 8 || std::atoi(n.c_str()) < 1) || this->contact[std::atoi(n.c_str()) - 1].getFirstName().empty()) && std::cin)
    {    
        std::cout << "Wrong index as parameter" << std::endl;
        std::cout << "-> ";
        getline(std::cin, n);
    }
    if (std::cin)
        PhoneBook::print_contact(std::atoi(n.c_str()) - 1);
}
