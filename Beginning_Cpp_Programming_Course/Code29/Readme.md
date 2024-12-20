# Using Default Argument Values - Grocery List
In this exercise you will create a program that will be used to automatically print a grocery list. Most weeks the grocery list is the same and so you may begin by declaring the function prototype `print_grocery_list` which has the default argument values:

* mangos = 13

* apples = 3

* oranges = 7

The function `print_grocery_list` has no return statement and so the return type of the function prototype should be `void`.

## IMPORTANT:
 Before declaring the function prototype, read the entire exercise to determine the proper order of arguments in the function parameter list. Remember that default argument values that do not change should be placed at the tail end of the parameter list, and those which change most often should be placed at the beginning.

Once the function prototype is declared, complete the parameter list of the function definition at the bottom of the file.

Now, print this weeks grocery list by calling the function print_grocery_list from the function body of modify_grocery_list.

The next week, you decide that you would like 5 apples instead of 3. Print the new grocery list by calling the function print_grocery_list from the function body of modify_grocery_list and passing the new apples argument.

For the final week,  you are having a party and would like to serve a fruit punch so you will need 7 apples, 11 oranges, and the default number of mangos. Print the new grocery list by calling the function print_grocery_list from the function body of modify_grocery_list and passing the new apples and oranges arguments. 