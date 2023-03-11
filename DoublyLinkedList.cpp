#include <iostream>
#include<string.h>

using namespace std;

struct student
{
    char name[20];
    string id; 
    char section[8]; 
    student *next;
    student *prev;
};

student *first = NULL;
student *current;		 // Used to move along the list
student *temp, *temp1, *temp2;   // Temporary pointers
int option = 0;
int count = 0;

void create_student(){
    // Reserve space for new student and fill it with data
    temp = new student;
    cout << "Enter the name of the student: ";
    cin >> temp->name;
    cout << "Enter the id of the student : ";
    cin >> temp->id;
    cout << "Enter the section of the student : ";
    cin >> temp->section;
    temp->next = NULL;
    temp->prev = NULL;
    count++;
}

void insert_beg(){
    create_student();

    if(first == NULL){ 
        first = temp;
        first->next = NULL;
        first->prev = NULL;
        current = first;
        cout<<"List was Empty. Student inserted at the beginning!\n";               
    }
    else {
        temp2 = first;
        first = temp;
        temp->next = temp2;
        temp2->prev = temp;
    }
}

void add_student_at_end()
{

    create_student();

    // Set up link to this student
    if (first == NULL)
    {
        first = temp;
        current = first;
    }
    else
    {
        temp2 = first;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
    }
}

void add_student_at(int n){

    if(n > count && n > 0){
        add_student_at_end();
        cout<<"There are less than " << n <<" students…! Only "<< count << endl << "Added student to the End!" << endl;
        return;
    }

    create_student();
    if (first == NULL)
    {
        first = temp;
        current = first;
    }
    else
    {
        temp2 = first;
        for (int i = 1; i < n-1; i++)
        {
            if (temp2->next != NULL)
                temp2 = temp2->next;
            else
                break;
        }
        temp1 = temp2->next;
        temp2->next = temp;
        temp->next = temp1;
        temp->prev = temp2;

    }
}

void display_list()
{
    student *temp;
    temp = first;
    cout << endl;
    if (temp == NULL)
        cout << "The list is empty!" << endl;
    else
    {
        cout << "Students list\n-------" << endl;
        int c = 1;
        while (temp != NULL)
        {
            // Display details for what temp points to
            cout << c << ". Name : " << temp->name << " ";
            cout << "id : " << temp->id << " ";
            cout << "Section : " << temp->section;
            // if (temp == current)
            //     cout << " <-- Current student";
            cout << endl;
            temp = temp->next;
            c++;
        }
        cout << "-------\nEnd of list!" << endl;
    }
}

void display_list_reverse()
{
    student *temp;
    temp = first;
    cout << endl;
    if (temp == NULL)
        cout << "The list is empty!" << endl;
    else
    {
        cout << "Students list\n-------" << endl;

        while(temp->next != NULL){
            temp = temp->next;
        }

        int c = count;
        do{
            cout << c << ". Name : " << temp->name << " ";
            cout << "id : " << temp->id << " ";
            cout << "Section : " << temp->section;
            cout << endl;
            temp = temp->prev;
        }while(temp!= NULL);
        c--;
        cout << "-------\nEnd of list!" << endl;
    }
}

void delete_first_student()
{
    student *temp;
    temp = first;
    first = first->next;
    first->prev = NULL;

    if (temp == current)
        current = current->next;
    delete temp;
    count--;
}

void delete_student_at(int n)
{
    student *temp1, *temp2;
    if (first == NULL)
        cout << "The list is empty!" << endl;
    else if(n > count)
        cout<<"Less than " << n <<" students…! Only "<< count << endl;
    else
    {
        temp1 = first;
        if (n == 1){
            delete_first_student();
            count--;
        }
        else {
            int i;
            for (i = 1; i < n; i++){
               if (temp1->next != NULL)
                {
                    temp2 = temp1;
                    temp1 = temp2->next;
                }else
                    break;
            }
            temp2->next = temp1->next;
            temp1->next->prev = temp2;

            if (temp1 == current)
                current = current->next;
            delete temp1;
            count--;
        }
    }
}

void delete_end_student()
{
    if (first == NULL)
        cout << "The list is empty!" << endl;
    else
    {
        temp1 = first;
        if (temp1->next == NULL)
        {
            if (temp1 == current)
                current = current->next;
            delete temp1;
            first = NULL;
        }
        else
        {
            while (temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            if (temp1 == current)
                current = temp2;
            
            delete temp1;
            temp2->next = NULL;
            count--;
        }
    }
}

void searching(){

    student *temp;
    temp = first;
    string id1;
    bool found = false;
    cout << "Enter Id to search: ";
    cin >> id1;

    if (first == NULL)
        cout << "The list is empty!" << endl;
    else{
        while(temp->next != NULL){

            if( temp->id == id1){
                cout << endl << "Student Found" << endl << "Name : " << temp->name << " ";
                cout << "id : " << temp->id << " ";
                cout << "Section : " << temp->section;
                cout << endl;
                found = true;
                break;
            }
            
            temp = temp->next;
        }
    }

    if( temp->id == id1 && !found){
        cout << endl << "Student Found" << endl << "Name : " << temp->name << " ";
        cout << "id : " << temp->id << " ";
        cout << "Section : " << temp->section;
        cout << endl;
        found = true;

    }
    if (!found){
        cout << endl << "Student Not Found" << endl;
    }
}

void menu()
{
    // clrscr();
    first = NULL;
    do
    {
        // display_list();
        cout<<endl;
        cout<<"1. Add a student at the beginning of the list"<<endl;
        // cout<<"2. Add a student in middle of the list" << endl;
        cout<<"2. Add at position n."<<endl;
        cout<<"3. Add a student to the end of the list." << endl;
        cout<<"4. Delete the first student from the list." << endl;
        cout<<"5. Delete the middle student from the list." << endl;
        cout<<"6. Delete the last student from the list." << endl;
        cout<<"66. Delete at position n."<<endl;

        cout<<"7. Search"<<endl;
        // cout<<"5. Update"<<endl;
        cout<<"8. Display"<<endl;
        cout<<"9. Display Reverse"<<endl;

        cout<<"0. Exit the program." << endl;
        cout << endl << "Please select an option : ";
            cout << endl << " >> ";
            cin >> option;

            switch (option)
        {
            case 1 : insert_beg();break;
            case 2: int m; cout << "Add student at number: "; cin >> m; add_student_at(m);break;
            case 3 : add_student_at_end(); break;

            case 4 : delete_first_student(); break;
            case 5 : delete_student_at(count/2); break;
            case 6 : delete_end_student(); break;
            case 66: int n; cout << "Delete student number: "; cin >> n; delete_student_at(n);break;

            case 7: searching();break;
            case 8: display_list();break;
            case 9: display_list_reverse();break;
        }
    }
        while (option != 0);
}

int main(){
    menu();    
    return 0;
}