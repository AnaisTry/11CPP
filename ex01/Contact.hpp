/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:09 by angassin          #+#    #+#             */
/*   Updated: 2024/02/07 15:55:23 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string firstName_;
		std::string lastName_;
		std::string nickname_;
		std::string phoneNumber_;
		std::string darkestSecret_;

		

	public:
		// constructors and destructor

		// default constructor automatically initalized to empty strings 
		//(non-class types need to be explicitly initiallized)
		Contact();

		// parameterized constructor
		Contact(std::string firstName, std::string lastName, std::string nickname,
		 		std::string phoneNumber, std::string darkestSecret);

		// factory method
		// static Contact createContact(){
		// 	return Contact();
		// };

		~Contact();
		
		// getters
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif 
