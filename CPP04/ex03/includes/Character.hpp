/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:14:48 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 12:18:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		virtual ~Character();
		Character(const Character& other);
		Character& operator=(Character const& other);

		virtual const std::string& getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		std::string name_;
		AMateria* inventory_[4];
};

#endif
