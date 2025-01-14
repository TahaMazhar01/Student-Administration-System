#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Student class
class Student {
public:
    string name;
    string id; // Changed from int to string for ARID number
    string domain; // New attribute for domain

    Student(string n, string i, string d) : name(n), id(i), domain(d) {}
};

// Node for Linked List
class Node {
public:
    Student* student;
    Node* next;

    Node(Student* s) : student(s), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(Student* student) {
        // Check for unique ID
        Node* current = head;
        while (current) {
            if (current->student->id == student->id) {
                cout << "Error: Student ID " << student->id << " already exists. Student not added." << endl;
                delete student; // Free memory if not added
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node(student);
        newNode->next = head;
        head = newNode;
        cout << "Student " << student->name << " added successfully with ID " << student->id << " in domain " << student->domain << "." << endl;
    }

    void display() {
        if (!head) {
            cout << "No students to display in the linked list." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << "ID: " << current->student->id 
                 << ", Name: " << current->student->name 
                 << ", Domain: " << current->student->domain << endl;
            current = current->next;
        }
    }

    void deleteStudent(const string& id) {
        Node* current = head;
        Node* prev = nullptr;

        while (current && current->student->id != id) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            cout << "Error: Student ID " << id << " not found." << endl;
            return; // Student not found
        }

        if (prev) {
            prev->next = current->next;
        } else {
            head = current->next; // Deleting head
        }
        cout << "Student " << current->student->name << " removed successfully." << endl;
        delete current->student;
        delete current;
    }

    void displayByDomain(const string& domain) {
        Node* current = head;
        cout << "Students in Domain " << domain << ":\n";
        bool found = false;
        while (current) {
            if (current->student->domain == domain) {
                cout << "ID: " << current->student->id 
                     << ", Name: " << current->student->name << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No students found in Domain " << domain << "." << endl;
        }
    }

    void bubbleSort() {
        if (!head || !head->next) {
            cout << "No students to sort." << endl;
            return; // No need to sort
        }

        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next) {
                if (current->student->name > current->next->student->name) {
                    swap(current->student, current->next->student);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
        cout << "Students sorted by name." << endl;
    }
};

// Node for Binary Tree
class TreeNode {
public:
    Student* student;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Student* s) : student(s), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
private:
    TreeNode* root;

    void insert(TreeNode*& node, Student* student) {
        if (!node) {
            node = new TreeNode(student);
        } else if (student->id < node->student->id) {
            insert(node->left, student);
        } else {
            insert(node->right, student);
        }
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << "ID: " << node->student->id 
                 << ", Name: " << node->student->name 
                 << ", Domain: " << node->student->domain << endl;
            inorder(node->right);
        }
    }

    void preorder(TreeNode* node) {
        if (node) {
            cout << "ID: " << node->student->id 
                 << ", Name: " << node->student->name 
                 << ", Domain: " << node->student->domain << endl;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << "ID: " << node->student->id 
                 << ", Name: " << node->student->name 
                 << ", Domain: " << node->student->domain << endl;
        }
    }

    void displayTree(TreeNode* node, string indent, bool last) {
        if (node) {
            cout << indent;
            if (last) {
                cout << "R---- ";
                indent += "   ";
            } else {
                cout << "L---- ";
                indent += "|  ";
            }
            cout << "ID: " << node->student->id 
                 << ", Name: " << node->student->name 
                 << ", Domain: " << node->student->domain << endl;
            displayTree(node->left, indent, false);
            displayTree(node->right, indent, true);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(Student* student) {
        insert(root, student);
    }

    void display(int orderType) {
        if (!root) {
            cout << "No students to display in the binary tree." << endl;
            return;
        }
        switch (orderType) {
            case 1:
                cout << "Preorder Traversal:\n";
                preorder(root);
                break;
            case 2:
                cout << "Inorder Traversal:\n";
                inorder(root);
                break;
            case 3:
                cout << "Postorder Traversal:\n";
                postorder(root);
                break;
            case 4:
                cout << "Tree Structure:\n";
                displayTree(root, "", true);
                break;
            default:
                cout << "Invalid order type." << endl;
        }
    }
};

// Function to validate input
void validateInput(const string& name, const string& id, const string& domain) {
    if (name.empty() || name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos) {
        throw invalid_argument("Error: Name must contain only characters and spaces.");
    }
    if (domain != "AI" && domain != "GC") {
        throw invalid_argument("Error: Domain must be either 'AI' or 'GC'.");
    }
    if (id.empty() || id.find_first_not_of("0123456789") != string::npos) {
        throw invalid_argument("Error: ID must be a numeric value.");
    }
}

// Main function
int main() {
    LinkedList studentList;
    BinaryTree studentTree;

    int choice;
    do {
        cout << "\nUniversity Administration System\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Students (Linked List)\n";
        cout << "4. Display Students (Binary Tree)\n";
        cout << "5. Display Students by Domain\n";
        cout << "6. Sort Students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, domain;
                string id; // Changed from int to string for ARID number
                cout << "Enter Student Name: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, name); // Allow spaces in the name
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Domain (AI/GC): ";
                cin >> domain;

                try {
                    validateInput(name, id, domain);
                    Student* newStudent = new Student(name, id, domain);
                    studentList.insert(newStudent);
                    studentTree.insert(newStudent);
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 2: {
                string id;
                cout << "Enter Student ID to delete: ";
                cin >> id;
                studentList.deleteStudent(id);
                break;
            }
            case 3:
                cout << "Students in Linked List:\n";
                studentList.display();
                break;
            case 4:
                cout << "Students in Binary Tree:\n";
                studentTree.display(4); // Display tree structure
                break;
            case 5: {
                string domain;
                cout << "Enter Domain to display (AI/GC): ";
                cin >> domain;
                studentList.displayByDomain(domain);
                break;
            }
            case 6:
                studentList.bubbleSort();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
