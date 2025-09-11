#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int v) : data(v), next(nullptr) {}
};

class SinglyCircular
{
private:
    Node *tail;

public:
    SinglyCircular() : tail(nullptr) {}
    ~SinglyCircular()
    {
        if (!tail)
            return;
        Node *cur = tail->next;
        tail->next = nullptr;
        while (cur)
        {
            Node *t = cur;
            cur = cur->next;
            delete t;
        }
    }

    void InsertAtBeg(int v)
    {
        Node *n = new Node(v);
        if (!tail)
        {
            tail = n;
            n->next = n;
        }
        else
        {
            n->next = tail->next;
            tail->next = n;
        }
        cout << "\nNode added at beginning.\n";
    }

    void InsertAtEnd(int v)
    {
        Node *n = new Node(v);
        if (!tail)
        {
            tail = n;
            n->next = n;
        }
        else
        {
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
        cout << "\nNode added at end.\n";
    }

    void InsertAfter(int value, int after)
    {
        if (!tail)
        {
            InsertAtBeg(value);
            return;
        }
        Node *cur = tail->next;
        do
        {
            if (cur->data == after)
            {
                Node *n = new Node(value);
                n->next = cur->next;
                cur->next = n;
                if (cur == tail)
                    tail = n;
                cout << "\nNode added after " << after << ".\n";
                return;
            }
            cur = cur->next;
        } while (cur != tail->next);
        cout << "\nValue " << after << " not found.\n";
    }

    void DeleteFromBeg()
    {
        if (!tail)
        {
            cout << "Empty list.\n";
            return;
        }
        Node *head = tail->next;
        if (head == tail)
        {
            delete head;
            tail = nullptr;
        }
        else
        {
            tail->next = head->next;
            delete head;
        }
        cout << "Deleted from beginning.\n";
    }

    void DeleteFromEnd()
    {
        if (!tail)
        {
            cout << "Empty list.\n";
            return;
        }
        Node *head = tail->next;
        if (head == tail)
        {
            delete tail;
            tail = nullptr;
            cout << "Deleted last node.\n";
            return;
        }
        Node *cur = head;
        while (cur->next != tail)
            cur = cur->next;
        cur->next = tail->next;
        delete tail;
        tail = cur;
        cout << "Deleted from end.\n";
    }

    void Display()
    {
        if (!tail)
        {
            cout << "List empty.\n";
            return;
        }
        Node *cur = tail->next;
        cout << "Circular List: ";
        do
        {
            cout << cur->data << " -> ";
            cur = cur->next;
        } while (cur != tail->next);
        cout << "(back to head)\n";
    }
};

int main()
{
    SinglyCircular list;
    int choice = 0, v, key;
    while (choice != 0)
    {
        cout << "\n1.InsertBeg \n2.InsertEnd \n3.InsertAfter \n4.DeleteBeg \n5.DeleteEnd \n6.Display \n0.Exit\nChoice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Val: ";
            cin >> v;
            list.InsertAtBeg(v);
            break;
        case 2:
            cout << "Val: ";
            cin >> v;
            list.InsertAtEnd(v);
            break;
        case 3:
            cout << "Val: ";
            cin >> v;
            cout << "After: ";
            cin >> key;
            list.InsertAfter(v, key);
            break;
        case 4:
            list.DeleteFromBeg();
            break;
        case 5:
            list.DeleteFromEnd();
            break;
        case 6:
            list.Display();
            break;
        case 0:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid Choice !!\n";
        }
    }
    return 0;
}
