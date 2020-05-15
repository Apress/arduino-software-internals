#include <Print.h>
#include "Person.h"

// Constructor 1:
Person::Person(const String foreName, const String surName) :  
    _foreName(foreName), 
    _surName(surName) {
};

// Constructor 2:
Person::Person(const char *foreName, const char *surName) :  
    _foreName(String(foreName)), 
    _surName(String(surName)) {
};

// Constructor 3:
Person::Person() :
    _foreName("Norman"), 
    _surName("Dunbar") {
};
    

// This is for Printable:
size_t Person::printTo(Print &p) const {
    size_t bytesPrinted = 0;

    bytesPrinted += p.print(_surName);
    bytesPrinted += p.print(", ");
    bytesPrinted += p.print(_foreName);

    return bytesPrinted;
}
