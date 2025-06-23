#include <iostream>
#include <bitset>
#include <limits>
#include <sstream>
#include <iomanip>
using namespace std;
// Function to validate binary input
bool isValidBinary(string str) 
{
    for (char ch : str) 
	{
        if (ch != '0' && ch != '1') 
		{
			return false;
		}
    }
    return true;
}
// Function to convert Binary (string) to Decimal (int)
int binaryToDecimal(string binary) 
{
    return stoi(binary, 0, 2);
}
// Function to convert Decimal (int) to Binary (string)
string decimalToBinary(int decimal) 
{
    if (decimal == 0) 
	{
		return "0";
	}
    return bitset<32>(decimal).to_string().substr(bitset<32>(decimal).to_string().find('1'));
}
// Function to convert Decimal (int) to Hexadecimal (string)
string decimalToHex(int decimal) 
{
    stringstream ss;
    ss << hex << uppercase << decimal;
    return ss.str();
}
// Function to perform arithmetic operations and print in all number systems
void performCalculation(int num1, int num2, char operation) 
{
    float result;
    switch (operation) 
	{
        case '+': 
		          result = num1 + num2; 
				  break;
        case '-': 
		          result = num1 - num2; 
				  break;
        case '*': 
		          result = num1 * num2; 
				  break;
        case '/':
            if (num2 == 0) 
			{
                cout << "Error: Division by zero is not allowed.\n";
                return;
            }
            result = float(num1) / num2;
            break;
        default:
            cout << "Invalid operation selected!\n";
            return;
    }
    // Display results in all number systems
    system("cls");
    cout << "\n================== Result ==================\n";
    cout << "      Decimal:     " << result << endl;
    cout << "      Binary :     " << decimalToBinary(result) << endl;
    cout << "      Hexadecimal: " << decimalToHex(result) << endl;
    cout << "============================================\n";
}
int main() 
{
    int choice;
    cout << "\t\t===========Binary & Decimal Arithmetic Calculator===========\n";
    cout << "\nChoose Input Type:\n";
    cout << "1. Binary Numbers\n";
    cout << "2. Decimal Numbers\n\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    if (choice == 1) 
	{
        // Binary Input Mode
        string bin1, bin2;
        cout << "Enter first binary number: ";
        cin >> bin1;
        cout << "Enter second binary number: ";
        cin >> bin2;
        // Validate binary input
        if (!isValidBinary(bin1) || !isValidBinary(bin2)) 
		{
            cout << "Invalid binary input! Only 0s and 1s are allowed.\n";
            return 1;
        }
        int num1 = binaryToDecimal(bin1);
        int num2 = binaryToDecimal(bin2);
        char operation;
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        performCalculation(num1, num2, operation);
    } 
	else if (choice == 2) 
	{
        // Decimal Input Mode
        int num1, num2;
        cout << "Enter first decimal number: ";
        cin >> num1;
        cout << "Enter second decimal number: ";
        cin >> num2;
        char operation;
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        performCalculation(num1, num2, operation);
    }
	else 
	{
        cout << "Invalid choice! Please restart the program and enter 1 or 2.\n";
    }
    return 0;
}
