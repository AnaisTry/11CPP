1. The program accepts three parameters: a filename, and two strings, s1 and s2.

2. The std::ifstream class from the <fstream> library is used to open the file with the given filename. If the file cannot be opened, an error message is displayed and the program exits.

3. The std::ofstream class is used to create a new file with the name <filename>.replace. If the file cannot be created, an error message is displayed and the program exits.

4. The contents of the original file are read line by line using std::getline. For each line, a loop is used to find each occurrence of s1. When an occurrence of s1 is found, it is replaced with s2. This is done by creating a new string where each occurrence of s1 is replaced with s2. The std::string::find and std::string::substr functions can be used for this purpose.

5. The modified line is written to the new file using std::ofstream::operator<<.

6. This process is repeated until all lines from the original file have been read and processed.

7. Both the input and output files are closed using std::ifstream::close and std::ofstream::close.

8. The program handles unexpected inputs and errors by checking the state of the input and output streams after each operation. If an error occurs, an appropriate message is displayed and the program exits.

Classes :

FileHandler: This class could handle all file-related operations such as opening a file, reading from a file, writing to a file, and closing a file. It could have methods like openFile, readLine, writeLine, and closeFile.

StringReplacer: This class could handle the replacement of one string with another in a given text. It could have a method like replaceString that takes a string and two other strings, s1 and s2, and replaces all occurrences of s1 with s2 in the given string.