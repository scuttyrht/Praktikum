/*
 * @author scuttyrht
 * @date 2022-11-24
 * @version 1.0
 */

#include <iostream>

using namespace std;

int calculation(int, int, int);
int roll_dice();

int main() {
    char ans;

    do {
        int choice;
        cout << "Math Functions (Skootl)\n[1] Calculation\n[2] Roll Dice\n[9] Exit\nChoose Option [1/2/9]: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int op, x, y;
            cout << "\nChoose Operation\n[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\nChoose Option [1/2/3/4]: ";
            cin >> op;
            cout << "Insert for 1st number: "; cin >> x;
            cout << "Insert for 2nd number: "; cin >> y;
            cout << "Result: " << calculation(op, x, y) << endl;
            cout << "Go again? (Y/N) "; cin >> ans;
            break;

        case 2:
            int dice[2];
            dice[0] = roll_dice();
            dice[1] = roll_dice();
            if (dice[0] == dice[1]) {
                cout << "You rolled a DOUBLE of a " << dice[0] << " and a " << dice[1] << "!" << endl;
            } else {
                cout << "You rolled a " << dice[0] << " and a " << dice[1] << "!" << endl;
            }
            cout << "Go again? (Y/N) "; cin >> ans;
            break;

        case 9:
            exit(1);
            break;
        
        default:
            cout << "Invalid option";
            ans = 'Y';
            break;
        }
    } while (ans == 'y' || ans == 'Y');
    
}

int calculation (int op, int x, int y) {
    switch (op) {
    case 1:
        return(x + y);
        break;
    
    case 2:
        return(x-y);
        break;

    case 3:
        return(x*y);
        break;

    case 4:
        return(x/y);
        break;

    default:
        cout << "Invalid option";
        break;
    }
}

int roll_dice() {
    return rand() % 6 + 1;
}