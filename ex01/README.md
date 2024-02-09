## ex01

step-by-step plan 

### Create the Contact class:

- Define private member variables for the contact fields: first name, last name, nickname, phone number, and darkest secret.
- Create a public constructor that takes these fields as parameters and initializes the member variables.
- Create public getter methods for each field.

 ### Create the PhoneBook class:

- Define a private member variable that is an array of Contact objects. The size of this array should be 8.
- Define a private member variable to keep track of the number of contacts currently in the phonebook.
- Define a private member variable to keep track of the index of the oldest contact in the phonebook.
- Create a public method addContact that takes a Contact object as a parameter. If the phonebook is not full, this method should add the contact to the array and increment the number of contacts. If the phonebook is full, it should replace the oldest contact with the new one and update the index of the oldest contact.
- Create a public method getContact that takes an index as a parameter and returns the corresponding Contact object. This method should handle the case where the index is out of range.

### Create the main program:

- Instantiate a PhoneBook object.
- Enter a loop that prompts the user for a command.
	- If the command is "ADD", prompt the user for the contact fields, create a Contact object, and add it to the phonebook using the addContact method.
	- If the command is "SEARCH", display the list of contacts in the phonebook. Then prompt the user for an index, get the corresponding Contact object using the getContact method, and display its fields.
	- If the command is "EXIT", break the loop.
	- If the command is anything else, ignore it and continue the loop.
- Handle edge cases, such as the phonebook being full or the user entering an out-of-range index. 
- Format the output :
	- Display the saved contacts as a list of 4 columns: index, first name, last
	name and nickname.
	- Each column must be 10 characters wide. A pipe character (’|’) separates
	them. The text must be right-aligned. If the text is longer than the column,
	it must be truncated and the last displayable character must be replaced by a
	dot (’.’).
	- Then, prompt the user again for the index of the entry to display. If the index
	is out of range or wrong, define a relevant behavior. Otherwise, display the
	contact information, one field per line.