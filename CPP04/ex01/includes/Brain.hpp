/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:56:30 by angassin          #+#    #+#             */
/*   Updated: 2024/04/11 14:09:00 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		virtual ~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);

		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
	
	private:
		std::string ideas_[100];

};

#endif