/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:57:50 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 11:57:56 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();
		Cure(const Cure& other);
		Cure& operator=(Cure const& other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

};

#endif
