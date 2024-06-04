/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:07:28 by angassin          #+#    #+#             */
/*   Updated: 2024/06/04 15:26:52 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array() : _array(NULL), _size(0)
		{
			std::cout << "Created empty array" << std::endl;
		};

		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			std::cout << "Created array of size " << n << std::endl;
		};

		Array(const Array &src) : _array(new T[src._size]), _size(src._size)
		{
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = src._array[i];
			std::cout << "Created array by copy" << std::endl;
		};

		virtual ~Array()
		{
			delete[] _array;
			std::cout << "Deleted array" << std::endl;
		};

		Array &operator=(const Array& copy)
		{
			if (this != &copy)
			{
				delete[] _array;
				_size = copy._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_array[i] = copy._array[i];
			}
			std::cout << "Assigned array" << std::endl;
			return *this;
		};

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _array[index];	
		};

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of bounds";
				};
		};

		unsigned int size() const
		{
			return _size;
		};
	
	private:
		T* _array;
		unsigned int _size;
};

#endif
