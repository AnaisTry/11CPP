
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

