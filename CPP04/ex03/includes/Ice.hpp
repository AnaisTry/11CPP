/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:26:21 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 11:49:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		Ice(const Ice& other);
		Ice& operator=(Ice const& other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

};

#endif