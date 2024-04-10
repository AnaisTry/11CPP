
# Theory

## Namespace

Small bags of related variables

https://www.ibm.com/docs/en/i/7.5?topic=expressions-scope-resolution-operator-c-only

## Stdio

https://www.geeksforgeeks.org/cin-in-c/
https://www.geeksforgeeks.org/manipulators-in-c-with-examples/


## Reference

When an object is passed by reference, the function receives a reference to the original object, not a copy of it.
It's then possible to use the address-of operator (&) to get the address of the original object and assign this address to a pointer.


## Classes

declaration : .h or .hpp
definition : .cpp

destructors and constructors don't have return types

class instance : type <name> ex : ```Sample instance;```

member attributes 
member functions
	- definition type <function>

## Operator overload

```
 std::ostream &operator<<( std::ostream &o, <ClassName> const &other);
```

## Method

 = virtual member function

## Shallow and deep copy

https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
https://www.linkedin.com/pulse/understanding-deep-copy-shallow-c-object-oriented-yamil-garcia-qaoze

In shallow copy, an object is created by simply copying the data of all variables of the original object. This works well if none of the variables of the object are defined in the heap section of memory.
If some variables are dynamically allocated memory from heap section, then the copied object variable will also reference the same memory location.
This will create ambiguity and run-time errors, dangling pointer. Since both objects will reference to the same memory location, then change made by one will reflect those change in another object as well.
Since we wanted to create a replica of the object, this purpose will not be filled by Shallow copy. 



## Best practices for organizing and structuring classes in C++:

1. Encapsulation: Keep data members private, and provide public getter and setter methods if necessary. This hides the internal representation of the class and makes it easier to change the implementation without affecting other parts of the code.

2. Single Responsibility Principle: Each class should have a single responsibility or a single reason to change. This makes the class easier to understand, test, and maintain.

3. Consistent Ordering: It's common to declare public members before private ones, as the public interface is typically of more interest to users of the class.

4. Initialization: Initialize all member variables. This can be done in the constructor or at the point of declaration.

5. Use of Constructors and Destructors: Constructors should establish all class invariants and destructors should clean up any resources the class has acquired.

6. Avoid Public Data Members: Except in rare cases, data members should be private. This encapsulates and protects them from being modified directly.

7. Use const Correctly: If a member function doesn't modify the state of the object, declare it as const.

8. Use of Header Files: Class declarations should be in header files (.h or .hpp), and definitions should be in source files (.cpp).

9. Use of Include Guards: To prevent header files from being included multiple times.


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

