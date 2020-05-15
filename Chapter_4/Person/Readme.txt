Title: Listings 4.8 through 4.10 - Example "Printable" class.
Author: Norman Dunbar
URL: 
Circuit: N/A

Purpose: An example of using a "Printable" class descendant.

The "Person" class is a "Printable" class descendant and
inherits various properties of the Printable base class. This example
does nothing much other than to create a couple of Persons, and
displays details on the Serial Monitor.

This sketch also demonstrates the "String" class, which shouldn't be
used much, if at all, in am embedded system with limited Static RAM as
it will do a lot of dynamic allocation and deallocation and could run
out of RAM with "undefined" consequences.

In this example, however, there is no dynamic allocation etc after the
initialisation of the two Person objects. It should be safe. Should!

No breadboard is required.

