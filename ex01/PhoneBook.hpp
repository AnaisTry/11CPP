/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:53:25 by angassin          #+#    #+#             */
/*   Updated: 2024/02/06 20:30:16 by angassin         ###   ########.fr       */
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
		int oldestContact_;

	public:
	
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);
		Contact getContact(int index) const;
};

#endif