#include "MyQueue.h"
#include "Ingredient.h"
#include <queue>
#include <windows.h>

int main()
{
    std::priority_queue<Ingredient> Ing;
    int choice;
    bool isCook = false;
    do {
        cout << "\nEnter what you want to do:" << endl;
        cout << "1 - Add ingredient" << endl;
        cout << "2 - Cook a dish" << endl;
        cout << "0 - Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            Ingredient::addIng(Ing);
            isCook = false;
            break;
        case 2:
            cout << "Cooking " << Ing.top().name << " for " << Ing.top().prevIng << " seconds." << endl;
            Sleep(Ing.top().prevIng * 1000);
            system("CLS");
            Ingredient::cookDish(Ing);
            isCook = true;

            break;
        case 0:
            cout << "Exit" << endl;
            isCook = false;

            break;
        default:
            cout << "ErRoR !-error choice-!" << endl;
        }
        if (isCook == true)
        {
            std::priority_queue<Ingredient> queue = Ing;
            cout << "Current ingredients in queue: ";
            while (!queue.empty()) {
                Ingredient ing = queue.top();
                cout << ing.name << " (" << ing.prevIng << " seconds) ";
                queue.pop();
                
            }
            cout << endl;
            if (queue.empty())
            {
                cout << "You did it!";
            }
        }
        
    } while (choice != 0);
}
