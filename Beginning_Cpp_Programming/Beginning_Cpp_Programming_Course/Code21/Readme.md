# Do-while loop exercise
## Exercise: Find the First Vowel in a Vector

Specification: Write a C++ program that uses a `do-while loop` to find the first English `vowel` in a hard-coded std::vector of characters.

The vector should contain a mixture of vowels and consonants (for example: {'h', 'e', 'l', 'l', 'o'}). The program should print the first vowel found in the vector. If no vowel is found, it should print a message indicating that `no vowel was found`.

### Instructions

* You will be writing your code within the provided function find_first_vowel(const std::vector<char>&  vec). Do not change the function name or its parameter.

* Do-While Loop: Utilize a do-while loop to iterate through the characters in the provided std::vector<char> named vec.

* Vowel Identification: In each iteration, check if the current character is a lowercase English vowel ('a', 'e', 'i', 'o', 'u').

### Output:

* If a vowel is found, use cout to display: `"Vowel found: "` followed by the vowel.

* If no vowel is found in the entire vector, display: `"No vowel was found"`.

### Examples: 
Here are some sample vectors and the expected output:

* For vector {'f','r','a','n','k'}, your function should output: Vowel found: a.

* For vector {'F','R','A','N','K'}, your function should output: No vowel was found.

* For vector {'h','e','l','l','o'}, your function should output: Vowel found: e.

* For an empty vector {}, your function should output: No vowel was found.

* For vector {'x','y','z','o'}, your function should output: Vowel found: o.
