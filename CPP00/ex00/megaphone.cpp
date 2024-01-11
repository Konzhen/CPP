/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:06:34 by jbutte            #+#    #+#             */
/*   Updated: 2023/09/11 00:12:15 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    } 
    for (size_t j = 1; argv[j] != NULL; j++)
        for (size_t i = 0; i < strlen(argv[j]); i++)
            std::cout << (char)toupper(argv[j][i]);
    std::cout << std::endl;
    return (0);
}