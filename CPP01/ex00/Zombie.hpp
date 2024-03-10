/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:42:39 by angassin          #+#    #+#             */
/*   Updated: 2024/03/10 19:52:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:

		Zombie(std::string name);
		~Zombie();

		void announce(void);
		
	private:

		std::string name_;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif