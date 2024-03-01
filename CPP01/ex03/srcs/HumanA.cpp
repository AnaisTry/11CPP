/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:25:43 by angassin          #+#    #+#             */
/*   Updated: 2024/02/22 22:51:45 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon ): name_(name), weapon_(weapon)
{
	std::cout << "HumanA constructed " << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" <<std::endl;
}