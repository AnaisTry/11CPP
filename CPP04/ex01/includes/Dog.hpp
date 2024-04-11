/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:46:59 by angassin          #+#    #+#             */
/*   Updated: 2024/04/11 18:05:57 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& other);
		Dog& operator=(Dog const& other);

		void makeSound() const;
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);

	private:
		Brain* brain_;
};

#endif