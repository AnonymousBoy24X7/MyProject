//Temperature Converter
#include <iostream>
#include <iomanip>
using namespace std;

// Conversion functions
float CelsiusToFahrenheit(float c) {
    return (c * 9 / 5) + 32;
}

float FahrenheitToCelsius(float f) {
    return (f - 32) * 5 / 9;
}

float CelsiusToKelvin(float c) {
    return c + 273.15;
}

int main() {
    int choice;
    float temperature, result;

    do {
        cout << "\n==========================================\n";
        cout << "          TEMPERATURE CONVERTER           \n";
        cout << "==========================================\n";
        cout << "  1) Convert Celsius To Fahrenheit\n";
        cout << "  2) Convert Fahrenheit To Celsius\n";
        cout << "  3) Convert Celsius To Kelvin\n";
        cout << "  4) Exit\n";
        cout << "------------------------------------------\n";
        cout << "Enter Your Choice (1-4): ";
        cin >> choice;

        cout << fixed << setprecision(2);

        switch (choice) {
            case 1:
                cout << "\nEnter Temperature In Celsius: ";
                cin >> temperature;
                result = CelsiusToFahrenheit(temperature);
                cout << "Result: " << temperature << " C = " << result << " F\n";
                break;

            case 2:
                cout << "\nEnter Temperature In Fahrenheit: ";
                cin >> temperature;
                result = FahrenheitToCelsius(temperature);
                cout << "Result: " << temperature << " F = " << result << " C\n";
                break;

            case 3:
                cout << "\nEnter Temperature In Celsius: ";
                cin >> temperature;
                result = CelsiusToKelvin(temperature);
                cout << "Result: " << temperature << " C = " << result << " K\n";
                break;

            case 4:
                cout << "\nExiting The Program. Thank You For Using The Converter.\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Enter A Number Between 1 And 4.\n";
        }

    } while (choice != 4);

    return 0;
}
