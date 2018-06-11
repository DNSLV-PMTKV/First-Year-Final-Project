#include <iostream>
#include "element.h"
#include "point.h"
#include "vector.h"
#include "line.h"
#include "functions.h"

using namespace std;

int POINT()
{
    int choice;
    char cont = 'y';
    point p1;
    cin >> p1;
    do{
        cout <<"Chose an option: \n";
        cout <<"0. Print point parameters.\n";
        cout <<"1. Check if two point are equal.\n";
        cin >> choice;
        if(choice == 1)
        {
            point p2;
            cin >> p2;
            (p1 == p2) ? cout <<"Equal\n": cout<<"Not equal.\n";
            cout << "Would you like to choose another point option?[y/n] ";
            cin>>cont;
        }
        else if(choice == 0)
        {
            cout << p1 << endl;
            cout << "Would you like to choose another point option?[y/n] ";
            cin>>cont;
        }
        else cout << "Wrong input. Try again.\n";
    }while(cont != 'n');
    return 0;
}

int VECTOR()
{
    vector v;
    int choice1, choice2;
    char cont = 'y';
    cout << "How would you like to create vector?\n";
    cout << "1. By two points\n";
    cout << "2. By three digits\n";
    cout << "> ";
    cin >> choice1;
    if(choice1 == 1)
    {
        cout << "First point parameters: \n";
        point p1; cin >> p1;
        cout << "Second point parameters:\n";
        point p2; cin >> p2;
        vector v1(p1,p2);
        v = v1;
    }
    else if (choice1 == 2)
    {
        vector v2;
        cin >> v2;
        v = v2;
    }
    else
    {
        system("CLS");
        cout << "Wrong input! Try again." << endl;
        VECTOR();
    }
    do
    {
        cout <<"Chose an option: \n";
        cout <<"0. Print vector parameters\n";
        cout <<"1. Get length\n";
        cout <<"2. Get direction\n";
        cout <<"3. Projection over another vector\n";
        cout <<"4. Check for zero vector\n";
        cout <<"5. Check for parallelism of two vectors\n";
        cout <<"6. Check for perpendicularity of two vectors\n";
        cout <<"7. Add two vectors\n";
        cout <<"8. Multiply by real number\n";
        cout <<"9. Vector multiplication\n";
        cout <<"10. Scalar multiplication\n";
        cout << "11. Mixed multiplication\n";
        cout << "> "; cin >> choice2;
        if(choice2 == 1)
        {
            cout << "Lenght is " << v.length() <<endl;
            cout << "Would you like to choose another point option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 2)
        {
            cout << "Not available yet.\n";
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 3)
        {
            cout << "Not available yet.\n";
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 4)
        {
            v.zeroV() ? cout <<"Zero vector\n":cout <<"Not zero vector\n";
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 5)
        {
            vector v2;
            cin >> v2;
            v.parallel(v2)?cout<<"Vectors are parallel\n":cout <<"Vectors are not parallel\n";
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 6)
        {
            vector v2;
            cin >> v2;
            v.perpendicular(v2)?cout<<"Vectors are perpendicular\n":cout <<"Vectors are not perpendicular\n";
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 7)
        {
            vector v2;
            cin >> v2;
            cout << v + v2;
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 8)
        {
            double num;
            cout << "Enter a number: "; cin >> num;
            cout << v * num << endl;
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 9)
        {
            vector v2;
            cin >> v2;
            cout << v*v2 << endl;
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 10)
        {
            vector v2;
            cin >> v2;
            vector v3 = v^v2;
            cout << v3;
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 11)
        {
            cout << "Not ready yet.\n";
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 0)
        {
            cout << v << endl;
            cout << "Would you like to choose another vector option?[y/n] ";
            cin>>cont;
        }
        else cout << "Wrong input. Try again.\n";
    }while(cont != 'n');
}

int LINE()
{
    int choice1, choice2;
    char cont = 'y';
    line L;
    cout << "How would you like to create line?\n";
    cout << "1. By two points\n";
    cout << "2. By vector and point\n";
    cout << "> "; cin >> choice1;
    if(choice1 == 1)
    {
        cout << "First point parameters: \n";
        point p1; cin >> p1;
        cout << "Second point parameters:\n";
        point p2; cin >> p2;
        line L1(p1, p2);
        L = L1;
    }
    else if(choice1 == 2)
    {
        cout << "Vector parameters: \n";
        vector v; cin >> v;
        cout << "Point parameters: \n";
        point p; cin >> p;
        line L1(v,p);
        L = L1;
    }
    else
    {
        system("CLS");
        cout << "Wrong input! Try again." << endl;
        LINE();
    }
    do
    {
        cout <<"Chose an option: \n";
        cout <<"0. Print line parameters\n";
        cout <<"1. Get normal vector\n";
        cout <<"2. Get angle between two lines\n";
        cout <<"3. Check if point lies on line\n";
        cout <<"4. Check if two lines are parallel\n";
        cout <<"5. Check if two lines match\n";
        cout <<"6. Check if two lines intersect\n";
        cout <<"7. Check if two lines are skew\n";
        cout <<"8. Check if two lines are perpendicular\n";
        cout << "> "; cin >> choice2;
        if(choice2 == 0)
        {
            cout << L;
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 1)
        {
            cout << L.normalVector();
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 2)
        {
            cout << "Enter parameters for second line\n";
            point one, two;
            cout << "First point: \n"; cin >> one;
            cout << "Second point: \n"; cin >> two;
            line L2(one,two);
            cout <<"Angle is " << L.angle(L2) << endl;
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 3)
        {
            point p;
            cout << "Enter point parameters: "; cin >> p;
            (L+p)?cout << "Point lies on the line.\n":cout <<"Point doesn't lie on the line.\n";
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 4)
        {
            cout << "Enter parameters for second line\n";
            point one, two;
            cout << "First point:\n"; cin >> one;
            cout << "Second point:\n"; cin >> two;
            line L2(one,two);
            (L||L2)?cout<<"Parallel.\n":cout<<"Not parallel.\n";
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if (choice2 == 5)
        {
            cout << "Enter parameters for second line\n";
            point one, two;
            cout << "First point:\n"; cin >> one;
            cout << "Second point:\n"; cin >> two;
            line L2(one,two);
            (L==L2)?cout<<"The two lines match.\n":cout<<"The two lines do not match.\n";
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 6)
        {
            cout << "Buy premium to see this option.\n";
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 7)
        {
            cout << "Buy premium to see this option.\n";
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else if(choice2 == 8)
        {
            cout << "Enter parameters for second line\n";
            point one, two;
            cout << "First point:\n"; cin >> one;
            cout << "Second point:\n"; cin >> two;
            line L2(one,two);
            (L|L2)?cout<<"Perpendicular.\n":cout<<"Not perpendicular.\n";
            cout << "Would you like to choose another line option?[y/n] ";
            cin>>cont;
        }
        else cout << "Wrong input. Try again.\n";
    }while(cont != 'n');
}

int SEGMENT(){}