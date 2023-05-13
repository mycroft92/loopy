#include <iostream>
#include "my_string.hh"

my_string reverse(const my_string& original) {
    // Return a new string that is the reverse of the original string
    // I implemented the function as a part of class, if one needs an external implementation it either needs to be a friend class like "my_string_utils" or make the str buffer buffer public
    return original.reverse();
}

//Fixed a brace here
my_string alpha() {
    return "Alpha";
}


int main()
{
    //my_string empty(); // Create an empty string
    //This line (above) is changed because it is semantically wrong. It declares a function that creates a my_string according to syntax, but that is not the intent.
    // We get a proper warning for this on 11.3.0 gcc but not on 9.4.0!
    //   Warning on 9.4.0: 
    //      test_my_string.cpp:20:49: warning: the address of ‘my_string empty()’ will never be NULL [-Waddress]
    //       20 |     std::cout << "This is an empty string: " << empty << std::endl;
    //   Warning on 11.3.0: (not on the same code, ran on a similar example)
    //      test.cpp:18:13: warning: empty parentheses were disambiguated as a function declaration [-Wvexing-parse]
    //       18 |     test one();
    //       |             ^~
    // test.cpp:18:13: note: remove parentheses to default-initialize a variable
    //    18 |     test one();
    //       |             ^~
    //       |             --
    // test.cpp:18:13: note: or replace parentheses with braces to value-initialize a variable
    // The correction is to remove the parenthesis or replace it with braces
    my_string empty; //or empty{}
    std::cout << "This is an empty string: " << empty << std::endl;

    //This works because the VALUE passed disambiguates it from a function declaration and does the job that we want.
    my_string non_empty("This string is initialized"); //suggested to run with {} instead of ()
    std::cout << "This is a non-empty string: " << non_empty << std::endl;

    my_string* non_empty2 = new my_string("this string is also initialized");
    std::cout << "This is also a non-empty string: " << *non_empty2 << std::endl;

    //I guess this was to test move vs copy traits of assignment? I didn't spend much time on this since it was working out of box.
    my_string string_copy = *non_empty2;
    std::cout << "This is a copy of a non-empty string: " << string_copy << std::endl;

    delete non_empty2;
    std::cout << "Only the original is deleted; the copy is still valid: " << string_copy << std::endl;

    my_string Alpha = alpha();
    my_string Omega = "Omega";
    // std::cout << "testing equality checks: " << (Alpha == "Alpha") <<std::endl;
    my_string alpha_and_omega = Alpha + Omega;
    std::cout << "The Alpha and the Omega: " << alpha_and_omega << std::endl;
    alpha_and_omega = Alpha + " and the " + Omega;
    std::cout << "The Alpha and the Omega: " << alpha_and_omega << std::endl;

    std::cout << "The Omega and the Alpha: " << reverse(alpha_and_omega) << std::endl;
    std::cout << "The Alpha and the Omega: " << alpha_and_omega << std::endl;

    return 0;
}
