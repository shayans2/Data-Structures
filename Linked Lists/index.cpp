#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() // Constructor
    {
        head = NULL;
    }

    void unshift(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        Node *temp = head;

        if (temp != NULL)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
        else
        {
            head = newNode;
        }
    }

    int length()
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            i++;
            temp = temp->next;
        }

        return i;
    }

    int findIndex(int value)
    {
        Node *temp = head;
        int i = 0;
        while (temp->data != value)
        {
            if (temp->next == NULL)
            {
                throw invalid_argument("Item not found!");
            }
            else
            {
                i++;
                temp = temp->next;
            }
        }

        return i;
    }

    void remove(int index) // This way of implementation has got more time complexity -> O(n)
    {
        if (length() == 0 || index > length() - 1)
        {
            throw invalid_argument("Index out of range.");
        }
        else if (length() == 1)
        {
            head = NULL;
        }
        else
        {
            Node *temp = head;
            int i = 0;
            while (i < index - 1)
            {
                i++;
                temp = temp->next;
            }
            Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            cout << length();
            free(nodeToDelete);
        }
    }

    void print()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.";
        }
    }
};

int main()
{
    LinkedList myList;
    myList.unshift(1);
    myList.push(2);
    cout << "Index of 1 is " << myList.findIndex(1) << "\n";
    myList.print();

    return 0;
}