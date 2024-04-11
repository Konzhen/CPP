/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:45:36 by jbutte            #+#    #+#             */
/*   Updated: 2023/08/01 17:15:53 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>

class PhoneBook
{
private:
    Contact contact[8];
    int     index;

public:
    PhoneBook();
    ~PhoneBook();
    
    static void	print_column(std::string arg);
    void                print_contact(int index);
    void                add();
    void                search();
};
