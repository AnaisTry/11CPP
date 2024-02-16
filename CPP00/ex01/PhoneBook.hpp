/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:25 by angassin          #+#    #+#             */
/*   Updated: 2024/02/16 12:59:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
class PhoneBook 
{
	private:
	
		//class-wide constant (only one copy indifferent of the number of objects created)
		static const int MAX_CONTACTS = 8;
		Contact contacts_[MAX_CONTACTS];
		int contactsNumber_;
		int oldestContactIndex_;
		
		void addContact_(const Contact &contact);
		Contact getContact_(int index) const;
		void printSearchTable_() const;

	public:
	
		PhoneBook();
		~PhoneBook();
		bool getInput(std::string &input, const std::string &prompt) const;
		void addContactPrompt();
		void searchContactPrompt() const;
};

#endif
