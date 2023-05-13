#include "my_string.hh"

// Implement any code you do not want to put into the class header file here.

//Constructor simple
my_string::my_string() {
    //the empty string is not empty, it has null character
    str    = new char[1];
    str[0] = '\0';
    std::cout<< "DEBUG: EMPTY ::"<< str<<"\n";
}

//Constructor from cbuf, we need to explicitly copy the null character here since it is not guaranteed to be present.
my_string::my_string(char* cbuf) {
    if (cbuf == nullptr) {
        str    = new char[1]; //so easy compared to malloc and calloc
        str[0] = '\0';
    } else {
        //we need cstring for utility functions strlen, strcpy etc..
        str    = new char[strlen(cbuf)+1];
        //copy the buffer
        strcpy(str, cbuf);
        //Terminate it properly
        str[strlen(cbuf)] = '\0';
    }
}


my_string::my_string(const my_string& src) {
    str = new char[strlen(src.str) +1]; // repeat ad-nauseum
    strcpy(str, src.str);
}

std::ostream& operator<<(std::ostream& os, const my_string& obj) {

    return os << obj.str;
}