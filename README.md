# Student-Administration-System
This C++ program implements a simple university administration system that manages student records using linked lists and binary trees. It allows users to add, delete, and display students, as well as sort them by name and filter by domain (AI or GC). The program  also includes input validation .


This program consists of several classes that work together to manage student information:
Student Class: Represents a student with attributes for name, ID (as a string for ARID numbers), and domain.
Node Class: Represents a node in a linked list, containing a pointer to a Student object and a pointer to the next node.
LinkedList Class: Manages a linked list of students, providing methods to insert, display, delete, and sort students. It checks for unique IDs during insertion and allows filtering by domain.
TreeNode Class: Represents a node in a binary tree, containing a pointer to a Student object and pointers to left and right children.BinaryTree Class: Manages a binary tree of students, providing methods to insert and display students in various traversal orders (preorder, inorder, postorder) and in a structured format.
Input Validation: The program includes a validateInput function that checks for valid student names, IDs, and domains, throwing exceptions with appropriate error messages if the inputs are invalid.
Main Function: Provides a user interface for interacting with the system, allowing users to choose actions such as adding or deleting students, displaying lists, and sorting.
Usage
Compile and run the program.
Follow the prompts to add students, delete them, or display their information.
Input validation ensures that only valid data is accepted, enhancing the robustness of the application.
