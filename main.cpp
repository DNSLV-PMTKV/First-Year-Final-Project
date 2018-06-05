#include <iostream>
#include "functions.h"
#include "element.h"
#include "point.h"
#include "vector.h"
using namespace std;


int main()
{
    int choice;
    char cont = 'y';
    do
    {
        cout << "Choose an object: "<<endl;
        cout << "1. Point" << endl;
        cout << "2. Vector" << endl;
        cout << "3. Line" << endl;
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
    }while(cont != 'n');
    return 0;
}