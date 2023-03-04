#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct node
{
    string name;
    int id;
    struct node *next;
};
node *start = NULL;
// start = malloc(sizeof(struct node));

void display(node *n);
void search(node *n, int id);

void del_mid(int c);
void del_last();
void del_first();

void insert_beg(node *p);
void insert_end(node *p);
void insert_mid(int c, node *p);

int main()
{
    // node *add=NULL;
    //  add = malloc(sizeof(struct node));
    node *add = NULL;
    add = (struct node *)malloc(sizeof(struct node));
    add->id = 1123123;
    add->name = "asdsfqwer";
    // cout << add->name << " " << add->id << endl;

    cout << endl
         << "1.inset at begining";
    cout << endl
         << "2.inset at middle (any)";
    cout << endl
         << "3.inset at end";
    cout << endl
         << "4.delete first";
    cout << endl
         << "5.delete last";
    cout << endl
         << "6.delete middle(any)";
    cout << endl
         << "7.search a student by name or id";
    cout << endl
         << "8.display a list of students first to last";
    cout << endl
         << "9.display a list of students last to first" << endl;
    cout << "0.exit" << endl;
    // cout << add->name << " " << add->id << endl;
    int num;
    cin >> num;
    int c;
    switch (num)
    {
    case 1:
        insert_beg(add);
        main();
        break;
    case 2:
        cout << "enter position to insert:";
        cin >> c;
        insert_mid(c, add);
        main();
        break;
    case 3:
        insert_end(add);
        main();
        break;
    case 4:
        del_first();
        main();
        break;
    case 5:
        del_last();
        main();
        break;
    case 6:

        cout << "enter position to delete:";
        cin >> c;
        del_mid(c);
        main();
        break;
    case 7:

        cout << "enter id to find:";
        cin >> c;
        search(start, c);
        main();
        break;
    case 8:
        display(start);
        main();
        break;
    case 9:
        main();
        break;
    case 0:
        exit(0);
        break;
    default:
        main();
        break;
    }

    return 0;
}

void display(node *n)
{
    while (n != NULL)
    {
        cout << n->name << " ";
        cout << n->id << endl;
        n = n->next;
    }
}
void search(node *n, int id)
{
    cout << "id";
    while (n != NULL)
    {
        if (n->id == id)
        {
            cout << "found" << endl;
            cout << n->name << " ";
            cout << n->id << endl;
        }

        n = n->next;
    }
}
void insert_end(node *p)
{
    node *q = start;

    if (start == NULL)
    {
        start = p;
    }
    else
    {
        while (q->next != NULL)
            q = q->next;

        q->next = p;
    }
    cout << "inserted at end";
}

void insert_mid(int c, node *p)
{
    node *q;
    q = start;

    for (int i = 1; i < c - 1; i++)
        q = q->next;

    if (q == NULL)
    {
        cout << "Less than " << c << " nodes…!";
        return;
    }

    p->next = q->next;
    q->next = p;
    cout << "inserted ";
}

void insert_beg(node *p)
{
    node *temp;
    if (start == NULL)
    { // if the list is empty
        start = p;
    }
    else
    {
        temp = start;
        start = p;
        p->next = temp;
    }
    cout << " inserted at beginning";
}

void del_first()
{

    if (start == NULL)
        cout << "empty" << endl;

    else
    {
        node *temp = start;
        start = temp->next;
        delete temp;
        cout << "\n First node deleted!";
    }
}

void del_last()
{
    if (start == NULL)
        cout << "\n empty";
    else
    {
        node *q = start;
        while (q->next->next != NULL)
            q = q->next;

        node *temp = q->next;
        q->next = NULL;
        delete temp;
        cout << "\n last node Deleted";
    }
}

// void del( node *x, node *y);
// void insert( node *x,  node *y);
// void display( node *x);

void del_mid(int c)
{
    node *q = start;

    for (int i = 1; i < c - 1; i++)
    {
        q = q->next;
        if (q == NULL)
            cout << "\n Node not found\n";
    }
    node *p = q->next; // node to be deleted
    q->next = p->next; // disconnecting the node p
    delete p;
    cout << "Deleted ";
}
