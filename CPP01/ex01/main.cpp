/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:41:09 by angassin          #+#    #+#             */
/*   Updated: 2024/02/22 20:35:54 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");

	std::cout << std::endl;
	
	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << std::endl;

	delete [] horde;
	return 0;
}
