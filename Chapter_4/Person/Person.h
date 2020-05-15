#ifndef Person_h
#define Person_h

#include <Printable.h>

class Person : public Printable {

    private:
        String _foreName;
        String _surName;

    public:
        // Constructors:
        Person(const String foreName, const String surName);
        Person(const char *foreName, const char *surName);
        Person();

        // Printable requires this:
        virtual size_t printTo(Print& p) const;
};

#endif // Person_h
