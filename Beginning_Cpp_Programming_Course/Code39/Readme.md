# Reverse a std::string using Pointers (Challenging!)
## Exercise: Reverse a std::string using Pointers

### Specification:

Write a C++ function `reverse_string` that takes a `std::string` as input and returns a new `std::string` with the characters in `reverse` order. The function should use pointers to perform the reversal.

### Function Signature:
```
std::string reverse_string(const std::string& str);
```
#### Input:
```str: The input string.```

#### Output:

The function should return a new string with the characters of str reversed.

### Example:
```
std::string input = "Hello, World!";
std::string reversed = reverse_string(input);
```
// reversed should be "!dlroW ,olleH"