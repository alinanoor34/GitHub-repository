#include <iostream>
using namespace std;

struct stu
{
    int id;
    string nname;
    float cgpa;
    stu *next;
};

stu *first = NULL;
stu *last = NULL;

void display()
{
    stu *temp = first;
    while (temp != NULL)
    {
        cout << temp->id << " ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertAtStart(int value)
{
    stu *curr = new stu;
    curr->id = value;
    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        curr->next = first;
        first = curr;
    }
}

void insertInMiddle(int value, int pos)
{
    stu *curr = new stu;
    curr->id = value;
    curr->next = NULL;
    if (pos == 0 || first == NULL)
    {
        first->next = curr;
        first = curr;
    }
    stu *prevNode = NULL;
    stu *temp = first;
    int i = 0;
    while (temp != NULL && i < pos)
    {
        prevNode = temp;
        temp = temp->next;
        i++;
    }
    prevNode->next = curr;
    curr->next = temp;
}

int main()
{
    int i = 5;
    while (i != 0)
    {
        insertAtStart(i);
        i--;
    }

    cout << "Original:";
    display();
    cout << "Afterwards";
    insertInMiddle(78, 3);
    display();
    return 0;
}