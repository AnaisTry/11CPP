/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:25 by angassin          #+#    #+#             */
/*   Updated: 2024/02/09 09:09:12 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
class PhoneBook 
{
	public:
	
		PhoneBook();
		~PhoneBook();
		//class-wide constant (only one copy indifferent of the number of objects created)
		static const int MAX_CONTACTS = 8;
		void addContactPrompt();
		void searchContactPrompt() const;

	private:
	
		Contact contacts_[MAX_CONTACTS];
		int contactsNumber_;
		int oldestContactIndex_;
		void addContact_(const Contact &contact);
		Contact getContact_(int index) const;
		bool getInput_(std::string &input, const std::string &prompt) const;
		void printSearchTable_() const;
};

#endif