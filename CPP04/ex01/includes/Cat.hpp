/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:38:20 by angassin          #+#    #+#             */
/*   Updated: 2024/04/11 18:05:42 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& other);
		Cat& operator=(Cat const& other);

		void makeSound() const;
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);

	private:
		Brain* brain_;
};

#endif