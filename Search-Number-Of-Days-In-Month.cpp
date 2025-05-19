#include<iostream>
using namespace std;
int month,year,choice;
string result;
string CalculateDays(int year,int month)
{
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        return "31 Days";
    }
    else if(month==2)
    {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            return "29 Days";
        }
        else
        {
            return "28 Days";
        }
    }
    else
    {
        return "30 Days";
    }
}
int main()
{
    do
    {
        cout<<"\n=== Days Finder In A Month ===\n";
        cout<<"Enter Year:";
        cin>>year;
        cout<<"Enter Month No (January-1 To December-12):";
        cin>>month;
        result = CalculateDays(year,month);
        cout<<result;
        cout<<"\n-------\n";
        cout<<"\nDo You Want To Use Again(Yes-1 Or No-2):";
        cin>>choice;
        
    } while (choice==1);
    cout << "Goodbye! See you next time.\n";
    return 0;
}