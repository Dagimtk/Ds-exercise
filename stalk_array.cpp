#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class stalk
{
private:
    int maxsize = 10;
    int size;
    int array[];

public:
    stalk()
    {
        int size = -1;
        int array[maxsize];
    }
    bool is_empty()
    {
        if (size < 0)
            return true;
        else
            return false;
    }
    bool is_full()
    {
        if (size == maxsize - 1)
            return true;
        else
            return false;
    }
    void display()
    {
        for (int i = 0; i < maxsize; i++)
        {
            if (array[i] == NULL)
                break;
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void push_back(int data)
    {
        if (is_full() == true)
        {
            cout << "full" << endl;
        }
        else
        {
            for (int i = 0; i < maxsize; i++)
            {
                if (array[i] == NULL)
                {
                    array[i] = data;
                    size++;
                    break;
                    cout << array[i] << " ";
                }
            }
        }
    }
    int pop_back()
    {
        if (is_empty() == true)
        {
            cout << "empty" << endl;
        }
        else
        {
            for (int i = 0; i < maxsize; i++)
            {
                if (array[i] == NULL)
                {
                    size--;
                    return array[i - 1];
                }
            }
        }
    }
};
int main()
{
    stalk s;
    return 0;
}