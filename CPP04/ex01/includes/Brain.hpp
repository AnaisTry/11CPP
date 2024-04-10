/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:56:30 by angassin          #+#    #+#             */
/*   Updated: 2024/04/09 18:08:52 by angassin         ###   ########.fr       */
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
	
	private:
		std::string ideas_[100];

};

#endif