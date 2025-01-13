# Adding public methods that access private class attributes
Given the following Dog class in `Dog.h` add the following public getter and setter methods that get and set each class attribute as follows:

* get_name returns the name attribute of the dog 

* set_name sets the name attribute of the dog to the string that is passed into the method.

* get_age returns the age attribute of the dog

* set_age sets the age attribute of the dog to the int passed into the method.

-------------------------------


# Add more public methods to an existing class
Given an existing Dog class in Dog.h, add the following public method to the class:

* `get_human_years()` return the `dog's age * 7`

* `speak()`  returns the `std::string "Woof"`
-------------------------------


# Add a Default Constructor to an Existing Class
Given the Dog class in `Dog.h`, add a default no-args constructor that initializes the dog's name to "None" and the dog's age to zero.

-------------------------------

# Add an Overloaded Constructor to an Existing Class
Given the Dog class defined in `Dog.h,` add an overloaded constructor that expect a `std::string` and `int` as parameters.

The constructor should allow us to create  Dog objects as follows:
```
Dog fido {"Fido", 4};
Dog spot {"Spot", 5};
```
-------------------------------


# Add a Copy Constructor to an Existing Class
Given the Dog class defined in `Dog.h`, add a `Copy constructor`.

The copy constructor should copy `the attributes` from one object to another.
Also, please display, `"Copy Constructor"` to cout in the body of your copy constructor. 

The copy constructor should allow us to create  Dog objects as follows:
```
Dog spot {"Spot", 5};   // Overloaded constuctor
Dog twin {spot};        // Copy constructor, twin will be a copy of spot
```