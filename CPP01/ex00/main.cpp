/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:41:09 by angassin          #+#    #+#             */
/*   Updated: 2024/02/09 22:08:33 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	std::cout << std::endl;

	randomChump("StackZombie");
	std::cout << std::endl;
	
	delete heapZombie;
	return 0;
}