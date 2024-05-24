/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:17:04 by angassin          #+#    #+#             */
/*   Updated: 2024/05/24 14:41:12 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <cstdint>

class Serializer
{
	public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);


	private:
		Serializer();
		virtual ~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(Serializer const& other);
};

#endif