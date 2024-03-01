/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:12:47 by angassin          #+#    #+#             */
/*   Updated: 2024/03/01 14:21:47 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private :
		Weapon& weapon_;
		std::string name_;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack(const std::string name, const Weapon& weapon) const;
};


#endif