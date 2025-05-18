#include<iostream>
using namespace std;
int main()
{
    float a,b;
    int choice;
    do{
    cout<<"-- Smart Calculator --";
    cout<<"\n1) Addition\n2) Substraction\n3) Multiplication\n4) Division\n5) Exponent\n6) SquareRoot\n7) Exit";
    cout<<"\nEnter Your Choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"Enter first Number:";
            cin>>a;
            cout<<"Enter Second Number:";
            cin>>b;
            cout<<endl<<a<<" + "<<b<<" = "<<a+b;
            break;
        }
        case 2:
        {
            cout<<"Enter first Number:";
            cin>>a;
            cout<<"Enter Second Number:";
            cin>>b;
            cout<<endl<<a<<" - "<<b<<" = "<<a-b;
            break;
        }
        case 3:
        {
            cout<<"Enter first Number:";
            cin>>a;
            cout<<"Enter Second Number:";
            cin>>b;
            cout<<endl<<a<<" * "<<b<<" = "<<a*b;
            break;
        }
        case 4:
        {
            cout << "Enter the numerator: ";
            cin >> a;
            cout << "Enter the denominator: ";
            cin >> b;
            cout << endl << a<< " / " << b <<" = "<< a / b;
            break;
        }
        case 5:
        {
            cout<<"Enter Base Number:";
            cin>>a;
            cout<<"Enter Exponent:";
            cin>>b;
            int result=1;
            for(int i=0;i<b;i++)
            {
                result *= a;
            }
            cout<<endl<<a<<" ^ "<<b<<" = "<<result;  
            break;
        }
        case 6:
        {
            double num;
            label:
            cout << "Enter Number To Find It's Square Root: ";
            cin >> num;
            if(num<0)
            {
                cout << "\nSquare root of negative number is not real Try Again.";
                cout <<"\n----------------------------------------------------\n";
                goto label;
            }
            double guess = num;
            double accuracy = 0.00001;
            while ((guess * guess - num) > accuracy || (num - guess * guess) > accuracy)
            {
                guess = (guess + num / guess) / 2.0; 
            }
            cout << "\nSquare Root Of "<<num<<" Is "<<guess;
            break;
        }
        case 7:
            cout<<"\nProgram Is Exited";
            break;
        default:
            cout<<"\nInvalid Choice!";           
    }
    cout<<"\n----------------------\n\n";
}
while(choice!=7);

return 0;

}