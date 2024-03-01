/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:42:39 by angassin          #+#    #+#             */
/*   Updated: 2024/02/22 19:52:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string name_;

	public:
		Zombie(); //default constructor
		Zombie(std::string name);
		~Zombie();

		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
