#pragma once
#include <iostream>
#include <string>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Ingredient
{
public:
	string name;
	int prevIng;

	Ingredient(string name, int prevIng) {
		this->name = name;
		this->prevIng = prevIng;
	}

    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ing) {
        os << ing.name << " (" << ing.prevIng << " sec)";
        return os;
    }

    static void addIng(std::priority_queue<Ingredient>& queue) {
        string name;
        int prepTime;
        cout << "Enter name of ingredient: ";
        cin >> name;
        cout << "Enter time of cooking(seconds): ";
        cin >> prepTime;
        queue.push(Ingredient(name, prepTime));
    }

    static void cookDish(std::priority_queue<Ingredient>& queue) {
        if (queue.empty()) {
            cout << "No ingredients to cook!" << endl;
            return;
        }

        queue.pop();
    }

	bool operator<(const Ingredient& other) const {
		return prevIng < other.prevIng;
	}


};

