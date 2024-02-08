
# Theory

## Input validation

Input validation is crucial for ensuring that your program behaves correctly and securely. Here are some common techniques for input validation in C++:

1. Check the state of the stream: After each input operation, check whether the operation succeeded by testing the stream in a boolean context or by calling the fail method. If the operation failed, handle the error appropriately.

2. Use the correct data type: If you're expecting a number, don't read it into a string and then convert it to a number. Instead, read it directly into a numeric variable. This will automatically validate that the input is a number.

3. Check the range of numeric values: If you're expecting a number within a certain range, check that the input value is within that range.

4. Use regular expressions: If you're expecting a string that matches a certain pattern, you can use a regular expression to validate the input.

5. Sanitize the input: If the input will be used in a context where certain characters are special (such as in a SQL query), make sure to sanitize the input to prevent injection attacks.

6. Use a validation loop: If the input is invalid, don't just fail silently. Instead, use a loop to keep asking for input until valid input is provided.

7. Provide clear error messages: If the input is invalid, provide a clear and helpful error message to the user.

8. Handle EOF correctly: If the user signals EOF (by pressing Ctrl+D or Ctrl+Z), handle it appropriately. Don't treat EOF as an error, but as a signal that the user wants to stop providing input

## Input error handling 

1. Check the state of the stream after each input operation: After reading from a stream, you should always check whether the operation succeeded. You can do this by testing the stream in a boolean context (e.g., if (!std::cin)) or by calling the fail method (e.g., if (std::cin.fail())).

2. Clear the error state of the stream before trying to read from it again: If an input operation fails, the stream enters a fail state and all subsequent input operations will fail until the error state is cleared. You can clear the error state by calling the clear method (e.g., `std::cin.clear()`).

3. Ignore unwanted characters in the stream: If an input operation fails because the next character in the stream is not what was expected, that character remains in the stream and will cause the next input operation to fail as well. You can remove unwanted characters from the stream by calling the ignore method (e.g., `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')`).

4. Handle EOF correctly: Pressing Ctrl+D (or Ctrl+Z on Windows) sends an EOF signal to the terminal, which can cause `std::getline` and other input functions to stop reading input. You should check for EOF by testing the eof method (e.g., `if (std::cin.eof())`) and handle it appropriately.

5. Use exceptions for error handling: By default, C++ streams don't throw exceptions when an error occurs. However, you can enable exceptions by calling the exceptions method (e.g., `std::cin.exceptions(std::istream::failbit | std::istream::badbit)`). This will cause the stream to throw an exception of type `std::ios_base::failure` when an error occurs, which you can catch and handle in a try-catch block.

6. Provide feedback to the user: If an input operation fails, it's a good idea to let the user know what went wrong. You can do this by printing an error message to the standard error stream (`std::cerr`).

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
- Format the output as specified in the instructions.