/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:49:01 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/11 02:09:24 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>

int main()
{
    PhoneBook   phoneBook;
    std::string input;

    while (input != "EXIT" && std::cin)
    {
        std::cout << "Type a command, which are ADD, SEARCH or EXIT" << std::endl;
        std::cout << "-> ";
        getline(std::cin, input);
        if (input == "ADD")
            phoneBook.add();
        else if (input == "SEARCH")
            phoneBook.search();
    }
}