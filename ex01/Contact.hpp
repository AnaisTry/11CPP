#ifndef Contact_hpp
# define Contact_hpp

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
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
		~Contact();
};

#endif
