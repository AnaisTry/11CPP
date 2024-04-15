/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:40:29 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 11:03:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria 
{
	public:
		AMateria();
		AMateria(const std::string& type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(AMateria const& other);

		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	
	protected:
		std::string type_;
};

#endif