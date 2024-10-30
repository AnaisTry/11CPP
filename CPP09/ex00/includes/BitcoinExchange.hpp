#ifndef CLASS_NAME_HPP
# define CLASS_NAME_HPP

#include <iostream>

class class_name
{
	public:
		class_name();
		virtual ~class_name();
		class_name(const class_name& other);
		class_name& operator=(const class_name& other);

	 protected:
		// Protected members

	 private:
		// Private members
};

#endif