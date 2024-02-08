/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:25 by angassin          #+#    #+#             */
/*   Updated: 2024/02/08 07:54:37 by angassin         ###   ########.fr       */
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
		void addContact(const Contact &contact);
		Contact getContact(int index) const;

	private:
	
		Contact contacts_[MAX_CONTACTS];
		int contactsNumber_;
		int oldestContactIndex_;
};

#endif