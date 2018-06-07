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
        else if(choice == 3)
        {
            point a(1,2,3);
            point b(2,3,4);
            point test(1,2,3);
            point abrg(5,4,9);
            line i(test, abrg);
            line l(a, b);
            cout << i.operator||(l);
            cout << "Would you like to choose another object?[y/n]";
            cin>>cont;
        }
        system("CLS");
    }while(cont != 'n');
    return 0;
}