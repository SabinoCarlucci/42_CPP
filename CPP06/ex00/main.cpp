/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:37:55 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/21 21:07:10 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 2)
    {
        std::cout << "correct usage: " << argv[0] << " <literal>";
        return (1);
    }
    std::string literal = argv[1];
    ScalarConverter::convert(argv[1]);
    return (0);
}