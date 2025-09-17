/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:20:17 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 11:34:00 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include <iostream>

void wrongTest()
{
	std::cout << "----- WRONG ANIMAL TEST -----" << std::endl;
	
	const WrongAnimal* meta = new WrongAnimal();
	const WrongCat* j = new WrongCat();
	const WrongAnimal* i = new WrongCat();
	std::cout << std::endl;
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	
	i->makeSound(); //mi aspetto il suono del gatto, ma non lo fa perche' punta alla classe base
	j->makeSound(); //mi aspetto il suono del gatto(mucca)
	meta->makeSound(); //mi aspetto il suono dell'animale generico
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
}

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << std::endl;

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << std::endl;

i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
std::cout << std::endl;

delete meta;
delete j;
delete i;

std::cout << std::endl;
std::cout << std::endl;

wrongTest();

return 0;
}