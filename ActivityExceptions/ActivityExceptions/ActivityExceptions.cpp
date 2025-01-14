// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/* This is the custom exception class and purely prints out a custom exception has occurred */
class CustomException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Custom exception occurred";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    throw std::logic_error("Standard exception occurred");

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    /* The following is the exception being caught from the call to do_even_more_custom_application_logic() */
    try
    {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    /* The following is the custom exception that I derived from std::exception */
    try
    {
        throw CustomException();
    }
    catch (const CustomException& e)
    {
        std::cerr << "Custom Exception Caught: " << e.what() << std::endl;
    }

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    /* The following is the exception being caught when dealing with dividing by zero occurs */
    if (den == 0)
    {
        throw std::runtime_error("Divide by zero error occurred");
    }

    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    /* The following is the exception handling for only the divide */
    try
    {
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try
    {
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomException& e)
    {
        std::cerr << "Custom Exception caught in main: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unhandled exception caught in main." << std::endl;
    }

    std::cout << "Exceptions Tests completed!" << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
