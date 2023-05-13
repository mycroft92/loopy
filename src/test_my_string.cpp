#include <iostream>
#include "my_string.hh"

// my_string reverse(const my_string& original) {
//     // Return a new string that is the reverse of the original string
// }

// my_string alpha()
//     return "Alpha";
// }


int main()
{
    //my_string empty(); // Create an empty string
    //This line (above) is changed because it is semantically wrong. It declares a function that creates a my_string according to syntax, but that is not the intent.
    // The correction is to remove the parenthesis
    my_string empty;
    std::cout << "This is an empty string: " << empty << std::endl;

    //This works because the VALUE passed disambiguates it from a function declaration and does the job that we want.
    my_string non_empty("This string is initialized");
    std::cout << "This is a non-empty string: " << non_empty << std::endl;

    // my_string* non_empty2 = new my_string("this string is also initialized");
    // std::cout << "This is also a non-empty string: " << *non_empty2 << std::endl;

    // my_string string_copy = *non_empty2;
    // std::cout << "This is a copy of a non-empty string: " << string_copy << std::endl;

    // delete non_empty2;
    // std::cout << "Only the original is deleted; the copy is still valid: " << string_copy << std::endl;

    // my_string Alpha = alpha()
    // my_string Omega = "Omega";
    // my_string alpha_and_omega = Alpha + Omega;
    // std::cout << "The Alpha and the Omega: " << alpha_and_omega << std::endl;
    // alpha_and_omega = Alpha + " and the " + Omega;
    // std::cout << "The Alpha and the Omega: " << alpha_and_omega << std::endl;

    // std::cout << "The Omega and the Alpha: " << reverse(alpha_and_omega) << std::endl;
    // std::cout << "The Alpha and the Omega: " << alpha_and_omega << std::endl;

    // return 0;
}
