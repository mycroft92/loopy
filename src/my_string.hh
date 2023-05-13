// Write a class to manage character string data using dynamically
// allocated arrays of characters.  The class should support the
// operations required such that the code in this directory compiles
// and runs without error.  When writing this, be sure to follow good
// object-oriented programming pratices, and clearly document your
// code.
//
// Restrictions: you may not use the std::string class in your implementation.
#include <cstring> // this is required only for strlen and strcpy, strcat functions which operate on c-char arrays
#include <iostream>
class my_string {
  // Your implementation goes here

  //The main pointer to all the char characters
  char *str = nullptr; 
  //We are not saving the string length currently since this is a simple implementation. 
  //Perhaps if the strings are too long or if there are too many calls to length it makes sense to have a length variable.
  public:
    

    // Default constructor for empty string
    my_string();

    //Constructor when I need to copy another character buffer contents
    my_string(const char* cbuf);

    //Copying needs this
    my_string(const my_string& src);
    //destructor is simple, just delete the pointer
    ~my_string() {delete str;}

    //OPERATORS TO BE OVERLOADED: 
    //ref(https://en.cppreference.com/w/cpp/language/operators, stream extraction section)
    //<< stream printing operator
    //Does this always need to be a friend class?
    //To avoid declaring it as friend, the only solution I can think of is to make str public which is bad.
    friend std::ostream& operator<<(std::ostream& os, const my_string& obj);

    //overriding == operators
    bool operator==(const my_string& rhs) const; // compares with my_string object
    bool operator==(const char* rhs) const; // compares with character array

    //overriding + operators
    my_string operator+(my_string& rhs);
    my_string operator+(char* operand);

    //overriding = operator (without this we get a use after free on alpha_and_omega = Alpha + " and the " + Omega;)
    my_string& operator=(const my_string& rhs);

    my_string reverse() const; //standard string reverse
};
