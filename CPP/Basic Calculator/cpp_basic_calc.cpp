/*
 * @author scuttyrht
 * @date 2022-10-7
 * @version 1.0
 */

#include <iostream>
#include <cctype>
#include <limits>
using namespace std;

int main()
{
  int op, num1, num2;
  cout << "Calculator Project\n©ScuttyRHT\n";
  while (true)
  {
    while (true)
    {
      op = 0;
      cout << "\n[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n[5] Exit\nEnter Operation [1/2/3/4/5]: ";
      
      cin >> op;
      if (!cin)
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } 
      
      if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5)
      {
        break;
      } else {
        cout << "\nInvalid Operation\n";
      }
    }

    switch (op)
    {
      case 1:
        cout << "\n=== Addition ===\n";
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "The result for '" << num1 << "' + '" << num2 << "' is: " << num1 + num2 << "\n";
        break;

      case 2:
        cout << "\n=== Subtraction ===\n";
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "The result for '" << num1 << "' - '" << num2 << "' is: " << num1 - num2 << "\n";
        break;

      case 3:
        cout << "\n=== Multiplication ===\n";
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "The result for '" << num1 << "' x '" << num2 << "' is: " << num1 * num2 << "\n";
        break;

      case 4:
        cout << "\n=== Division ===\n";
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "The result for '" << num1 << "' / '" << num2 << "' is: " << num1 / num2 << "\n";
        break;

      case 5:
        exit(0);

      default:
        break;
    }

    while (true)
    {
      string response;
      cout << "Again? [Y/N]: ";
      cin >> response;
      if (response == "Y" || response == "y")
      {
        break;
      } else
      {
        exit(0);
      }
    }
  }
  
  system("pause");
  return 0;
}