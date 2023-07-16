#include <iostream>

using namespace std;

int main() {
    int choice;
    cout << "[1] For\n[2] While\nChoice: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            for (int i = 0; i <= 20; i++)
            {
                if (i % 2 != 0) {
                    cout << i+1 << endl;
                } 
            }
            break;
        }
        
        case 2: {
            int i = 1;
            while (i <= 20)
            {
                if (i % 2 != 0) {
                    cout << i+1 << endl;
                }
                i++;
            }
            break;
        }

        default: {
            cout << "Invalid choice";
            break;
        }
    }
    
    system("PAUSE");
}