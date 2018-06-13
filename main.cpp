#include <iostream>
#include "functions.h"
#include "element.h"
#include "point.h"
#include "vector.h"
#include "line.h"

using namespace std;

int main()
{
    int choice;
    char cont = 'y';
    do
    {
        cout << "Choose an object: \n";
        cout << "1. Point\n";
        cout << "2. Vector\n";
        cout << "3. Line\n";
        cout << "4. Segment\n";
        cout << "5. Triangle\n";
        cout << "9. Exit\n";
        cout << "> "; cin >> choice;
        if(choice == 1)
        {
            POINT();
            cout << "Would you like to choose another object?[y/n]";
            cin>>cont;
        }
        else if (choice == 2)
        {
            VECTOR();
            cout << "Would you like to choose another object?[y/n]";
            cin>>cont;
        }
        else if(choice == 3)
        {
            LINE();
            cout << "Would you like to choose another object?[y/n]";
            cin>>cont;
        }
        else if(choice == 4)
        {
            SEGMENT();
            cout << "Would you like to choose another object?[y/n]";
            cin>>cont;
        }
        else if(choice == 5)
        {
            TRIANGLE();
            cout << "Would you like to choose another object?[y/n]";
            cin>>cont;
        }
        else if(choice == 9) cont = 'n';
        system("CLS");
    }while(cont != 'n');
    return 0;
}