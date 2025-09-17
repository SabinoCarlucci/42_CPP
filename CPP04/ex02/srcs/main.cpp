/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:20:17 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 22:20:11 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include <iostream>

int main()
{
	//decomment to get error
	//const Animal* unicorn = new Animal();

	
	int n = 4;

	Animal* animals[n];
	std::cout << "----- ANIMAL SPAWNING -----" << std::endl;
	
	animals[0] = new Dog();
	const Dog *doggo = static_cast<const Dog *>(animals[0]);
	std::cout << std::endl;
	
	animals[1] = new Cat();
	const Cat *feline = static_cast<const Cat *>(animals[1]);
	std::cout << std::endl;

	doggo->getBrain()->setIdea(0, "me wanna play");
	feline->getBrain()->setIdea(0, "purrrrr");

	animals[2] = new Dog(*doggo);
	const Dog *doggy = static_cast<const Dog *>(animals[2]);
	std::cout << std::endl;
	
	animals[3] = new Cat(*feline);
	const Cat *kitty = static_cast<const Cat *>(animals[3]);
	std::cout << std::endl;


	doggy->getBrain()->setIdea(0, "me hate cats");
	kitty->getBrain()->setIdea(0, "the world is mine");

	std::cout << "----- ANIMAL THOUGHTS-----" << std::endl;
	std::cout << doggo->getBrain()->getIdea(0) << std::endl;
	std::cout << feline->getBrain()->getIdea(0) << std::endl;
	std::cout << doggy->getBrain()->getIdea(0) << std::endl;
	std::cout << kitty->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "----- ANIMAL NOISES-----" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << "animal #" << i << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	
	std::cout << "----- ANIMAL KILLING SPREE -----" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << "deleting animal #" << i << std::endl;
		delete animals[i];
		std::cout << std::endl;
	}
	
	return 0;
}