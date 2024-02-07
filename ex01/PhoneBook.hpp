/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:25 by angassin          #+#    #+#             */
/*   Updated: 2024/02/07 16:16:28 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
class PhoneBook 
{
	private:
	
		Contact contacts_[8];
		int contactsNumber_;
		int oldestContactIndex_;

	public:
	
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);ß
		Contact getContact(int index) const;
};

#endif