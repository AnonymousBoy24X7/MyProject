//Convert Money Between INR, USD, And EUR
#include <iostream>
#include <iomanip>
using namespace std;

float Convert_INR_To_USD(float INR) { return INR * 0.012; }
float Convert_USD_To_INR(float USD) { return USD * 83.20; }
float Convert_USD_To_EUR(float USD) { return USD * 0.92; }
float Convert_EUR_To_USD(float EUR) { return EUR * 1.09; }
float Convert_INR_To_EUR(float INR) { return INR * 0.01102; }
float Convert_EUR_To_INR(float EUR) { return EUR * 90.688; }

int main()
{
    int option;
    float result, amount;

    cout << fixed << setprecision(2);
    cout << "=============================================" << endl;
    cout << "      Welcome To The Currency Converter      " << endl;
    cout << "   Convert Money Between INR, USD, And EUR   " << endl;
    cout << "=============================================" << endl;

    do
    {
        cout << "\n===== Currency Converter Command Prompt =====" << endl;
        cout << "[1] INR to USD    - Convert Rupees to Dollars" << endl;
        cout << "[2] USD to INR    - Convert Dollars to Rupees" << endl;
        cout << "[3] USD to EUR    - Convert Dollars to Euros" << endl;
        cout << "[4] EUR to USD    - Convert Euros to Dollars" << endl;
        cout << "[5] INR to EUR    - Convert Rupees to Euros" << endl;
        cout << "[6] EUR to INR    - Convert Euros to Rupees" << endl;
        cout << "[7] Exit          - Close The Converter" << endl;
        cout << "=============================================" << endl;
        cout << "Select Option [1-7]: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter The Amount In INR: ";
            cin >> amount;
            result = Convert_INR_To_USD(amount);
            cout << "Conversion Successful!" << endl;
            cout << amount << " INR = " << result << " USD" << endl;
            break;
        case 2:
            cout << "Enter The Amount In USD: ";
            cin >> amount;
            result = Convert_USD_To_INR(amount);
            cout << "Conversion Successful!" << endl;
            cout << amount << " USD = " << result << " INR" << endl;
            break;
        case 3:
            cout << "Enter The Amount In USD: ";
            cin >> amount;
            result = Convert_USD_To_EUR(amount);
            cout << "Conversion Successful!" << endl;
            cout << amount << " USD = " << result << " EUR" << endl;
            break;
        case 4:
            cout << "Enter The Amount In EUR: ";
            cin >> amount;
            result = Convert_EUR_To_USD(amount);
            cout << "Conversion Successful!" << endl;
            cout << amount << " EUR = " << result << " USD" << endl;
            break;
        case 5:
            cout << "Enter The Amount In INR: ";
            cin >> amount;
            result = Convert_INR_To_EUR(amount);
            cout << "Conversion Successful!" << endl;
            cout << amount << " INR = " << result << " EUR" << endl;
            break;
        case 6:
            cout << "Enter The Amount In EUR: ";
            cin >> amount;
            result = Convert_EUR_To_INR(amount);
            cout << "Conversion Successful!" << endl;
            cout << amount << " EUR = " << result << " INR" << endl;
            break;
        case 7:
            cout << "\nYou Have Chosen To Exit The Currency Converter." << endl;
            break;
        default:
            cout << "\nInvalid Option! Please Enter A Number Between 1 And 7." << endl;
        }

    } while (option != 7);

    cout << "Thanks For Using The Currency Converter! Have A Great Day!\n" << endl;

    return 0;
}
