#include "my_string.hh"

// Implement any code you do not want to put into the class header file here.

//Constructor simple
my_string::my_string() {
    //the empty string is not empty, it has null character
    str    = new char[1];
    str[0] = '\0';
    // std::cout<< "DEBUG: EMPTY ::"<< str<<"\n";
}

//Constructor from char buffer, if the cbuf is not null-terminated this needs a rewrite and we are screwed.
my_string::my_string(const char* cbuf) {
    if (cbuf == nullptr) {
        str    = new char[1]; //so easy compared to malloc and calloc
        str[0] = '\0';
    } else {
        //we need cstring for utility functions strlen, strcpy etc..
        str    = new char[strlen(cbuf)+1];
        //copy the buffer
        strcpy(str, cbuf);
    }
}


my_string::my_string(const my_string& src) {
    str = new char[strlen(src.str) +1]; // repeat ad-nauseum
    strcpy(str, src.str);
}

std::ostream& operator<<(std::ostream& os, const my_string& obj) {
    return os << obj.str;
}

bool my_string::operator==(const my_string& rhs) const {
    return !strcmp(str, rhs.str);
}

bool my_string::operator==(const char* rhs) const {
    return !strcmp(str, rhs);
}

my_string my_string::operator+(my_string& rhs) {
    // std::cout << "Current buff:" << str << std::endl;
    // std::cout << "Operand buff:" << rhs.str << std::endl; 
    int size   = strlen(str) + strlen(rhs.str);
    char* buff = new char[size+1]; // the usual +1 for null char
    strcpy(buff, str);
    strcat(buff, rhs.str); //needs a null terminated buffer
    // std::cout<< "DEBUG:: current buff:" << buff<< std::endl;
    my_string temp = my_string(buff); 
    delete buff; 
    // std::cout << "DEBUG:: Compound string= "<< temp <<std::endl;
    return temp ;// return a new string with the new contents
}

my_string my_string::operator+(char* rhs) {
    int size   = strlen(str) + strlen(rhs);
    char* buff = new char[size+1]; // the usual +1 for null char
    strcpy(buff, str);
    strcat(buff, rhs); //needs a null terminated buffer
    my_string temp = my_string(buff); 
    delete buff; 
    return temp ;// return a new string with the new contents
}

//Use after free fixes
my_string& my_string::operator=(const my_string& rhs){
    //Should I optimise for same contents?
    if (str == rhs.str) {
        return *this;
    }
    delete str;
    str = new char[strlen(rhs.str)+1];
    strcpy(str, rhs.str);
    return *this;
}

my_string my_string::reverse() const {
    // std::cout<< "buff:" <<str << std::endl;
    int size   = strlen(str);
    char* buff = new char[size+1]; //reversing doesn't change the length
    for(int i = 0; i < size ; i++) 
        buff[i] = str[size-1 -i]; // the -1 is needed, notice that in abcd index of d is 3    
    buff[size] = '\0';
    // std::cout<< "reversed buff:" <<buff << std::endl;
    my_string temp = my_string(buff);
    delete buff;
    return temp;

}