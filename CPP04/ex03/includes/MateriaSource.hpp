/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:30:38 by angassin          #+#    #+#             */
/*   Updated: 2024/04/15 12:31:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(MateriaSource const& other);

		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(const std::string& type);

	private:
		AMateria* inventory_[4];
};

#endif
