#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Node {
public:
    char name[30], type[15];
    Node *left, *right;

    Node(char n[], char t[]) {
        strcpy(name, n);
        strcpy(type, t);
        left = right = NULL;
    }
};

class FileSystem {
    Node *root;

    Node* insert(Node *r, char n[], char t[]) {
        if (r == NULL)
            return new Node(n, t);

        int c = strcmp(n, r->name);

        if (c < 0)
            r->left = insert(r->left, n, t);
        else if (c > 0)
            r->right = insert(r->right, n, t);
        else
            cout << "Name already exists!\n";

        return r;
    }

    Node* search(Node *r, char n[]) {
        if (r == NULL || strcmp(n, r->name) == 0)
            return r;

        if (strcmp(n, r->name) < 0)
            return search(r->left, n);

        return search(r->right, n);
    }

    Node* minimum(Node *r) {
        while (r->left != NULL)
            r = r->left;
        return r;
    }

    Node* remove(Node *r, char n[]) {
        if (r == NULL)
            return NULL;

        int c = strcmp(n, r->name);

        if (c < 0)
            r->left = remove(r->left, n);
        else if (c > 0)
            r->right = remove(r->right, n);
        else {
            if (r->left == NULL) {
                Node *temp = r->right;
                delete r;
                return temp;
            }
            if (r->right == NULL) {
                Node *temp = r->left;
                delete r;
                return temp;
            }

            Node *temp = minimum(r->right);
            strcpy(r->name, temp->name);
            strcpy(r->type, temp->type);
            r->right = remove(r->right, temp->name);
        }
        return r;
    }

    void display(Node *r) {
        if (r != NULL) {
            display(r->left);
            cout << r->name << " (" << r->type << ")\n";
            display(r->right);
        }
    }

public:
    FileSystem() {
        root = NULL;
    }

    void add(char n[], char t[]) {
        if (strcmp(t, "File") != 0 &&
            strcmp(t, "Directory") != 0) {
            cout << "Enter File or Directory only!\n";
            return;
        }

        if (search(root, n) != NULL) {
            cout << "Name already exists!\n";
            return;
        }

        root = insert(root, n, t);
        cout << "Entry added!\n";
    }

    void find(char n[]) {
        Node *r = search(root, n);

        if (r != NULL)
            cout << "Found: " << r->name
                 << " (" << r->type << ")\n";
        else
            cout << "Entry not found!\n";
    }

    void erase(char n[]) {
        if (search(root, n) == NULL) {
            cout << "Entry not found!\n";
            return;
        }
        root = remove(root, n);
        cout << "Entry deleted!\n";
    }

    void show() {
        if (root == NULL)
            cout << "No entries available.\n";
        else
            display(root);
    }
};

int main() {
    FileSystem fs;
    int choice;
    char name[30], type[15];

    do {
        cout << "\n--- FILE MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Entry\n";
        cout << "2. Search Entry\n";
        cout << "3. Delete Entry\n";
        cout << "4. Display Entries\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name (no spaces): ";
            cin >> setw(30) >> name;
            cout << "Enter type (File/Directory): ";
            cin >> setw(15) >> type;
            fs.add(name, type);
            break;

        case 2:
            cout << "Enter name to search: ";
            cin >> setw(30) >> name;
            fs.find(name);
            break;

        case 3:
            cout << "Enter name to delete: ";
            cin >> setw(30) >> name;
            fs.erase(name);
            break;

        case 4:
            cout << "\nEntries in alphabetical order:\n";
            fs.show();
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
/*
OUTPUT

PS C:\DSA_CCE3> g++ FileManagement.cpp -o FileManagement

PS C:\DSA_CCE3> .\FileManagement.exe

--- FILE MANAGEMENT SYSTEM ---
1. Add Entry
2. Search Entry
3. Delete Entry
4. Display Entries
0. Exit
Enter choice: 1
Enter name (no spaces): notes
Enter type (File/Directory): File
Entry added!

--- FILE MANAGEMENT SYSTEM ---
1. Add Entry
2. Search Entry
3. Delete Entry
4. Display Entries
0. Exit
Enter choice: 1
Enter name (no spaces): pictures
Enter type (File/Directory): Directory
Entry added!

--- FILE MANAGEMENT SYSTEM ---
1. Add Entry
2. Search Entry
3. Delete Entry
4. Display Entries
0. Exit
Enter choice: 2
Enter name to search: notes
Found: notes (File)

--- FILE MANAGEMENT SYSTEM ---
1. Add Entry
2. Search Entry
3. Delete Entry
4. Display Entries
0. Exit
Enter choice: 4

Entries in alphabetical order:
notes (File)
pictures (Directory)

--- FILE MANAGEMENT SYSTEM ---
1. Add Entry
2. Search Entry
3. Delete Entry
4. Display Entries
0. Exit
Enter choice: 0
Program ended.
*/