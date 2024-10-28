// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string> // Added to utilze the std::getline() method

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  std::string user_input; // Changed to work with input without stackoverflow application abort prompt
  std::cout << "Enter a value: ";
  std::getline(std::cin, user_input); // Changed to work with input without stackoverflow application abort prompt

  // Check the length of the input
  if (user_input.length() > 20) {
      std::cout << "Error: Input too long." << std::endl;
      return 1;
  }

  // Add a null terminator at the end of the input
  user_input += '\0';

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;

  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
