#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Food {
    string name, category;
    int calories;
    Food(string n, int c, string cat) : name(n), calories(c), category(cat) {}
};

int main() {
    vector<Food> foods = {
        // Fruits
        {"Apple", 95, "Fruit"}, {"Banana", 105, "Fruit"}, {"Orange", 62, "Fruit"}, {"Grapes", 62, "Fruit"},
        {"Strawberry", 4, "Fruit"}, {"Blueberry", 1, "Fruit"}, {"Watermelon", 46, "Fruit"}, {"Pineapple", 50, "Fruit"},
        {"Mango", 99, "Fruit"}, {"Papaya", 59, "Fruit"},
        // Proteins
        {"Chicken", 165, "Protein"}, {"Beef", 271, "Protein"}, {"Pork", 231, "Protein"}, {"Egg", 78, "Protein"},
        {"Salmon", 208, "Protein"}, {"Tuna", 132, "Protein"}, {"Shrimp", 85, "Protein"}, {"Tofu", 76, "Protein"},
        {"Lentils", 116, "Protein"}, {"Turkey", 189, "Protein"},
        // Carbohydrates
        {"Rice", 206, "Carbohydrate"}, {"Bread", 79, "Carbohydrate"}, {"Pasta", 131, "Carbohydrate"}, {"Potato", 163, "Carbohydrate"},
        {"Oats", 389, "Carbohydrate"}, {"Quinoa", 120, "Carbohydrate"}, {"Corn", 86, "Carbohydrate"}, {"Sweet Potato", 86, "Carbohydrate"},
        {"Tortilla", 104, "Carbohydrate"}, {"Muffin", 377, "Carbohydrate"},
        // Dairy
        {"Milk", 122, "Dairy"}, {"Cheese", 113, "Dairy"}, {"Yogurt", 59, "Dairy"}, {"Butter", 102, "Dairy"},
        {"Cream", 52, "Dairy"}, {"Ice Cream", 137, "Dairy"}, {"Cottage Cheese", 98, "Dairy"}, {"Sour Cream", 60, "Dairy"},
        {"Kefir", 59, "Dairy"}, {"Mozzarella", 85, "Dairy"},
        // Snacks
        {"Almonds", 164, "Snack"}, {"Walnuts", 185, "Snack"}, {"Chips", 150, "Snack"}, {"Popcorn", 55, "Snack"},
        {"Granola Bar", 120, "Snack"}, {"Trail Mix", 200, "Snack"}, {"Peanuts", 170, "Snack"}, {"Cashews", 157, "Snack"},
        {"Chocolate", 210, "Snack"}, {"Cookies", 160, "Snack"}
    };

    vector<string> categories = {"Fruit", "Protein", "Carbohydrate", "Dairy", "Snack"};
    int choice;

    do {
        cout << "\n=== FOOD CATEGORY MENU ===\n";
        for(int i=0; i<categories.size(); i++)
            cout << i+1 << ". " << categories[i] << "\n";
        cout << "6. Exit\nChoice: ";
        cin >> choice; cin.ignore();

        if(choice >= 1 && choice <= 5){
            string selectedCat = categories[choice-1];
            vector<Food> catFoods;
            for(auto &f : foods)
                if(f.category == selectedCat)
                    catFoods.push_back(f);

            // Sort foods alphabetically
            sort(catFoods.begin(), catFoods.end(), [](Food &a, Food &b){ return a.name < b.name; });

            cout << "\n--- " << selectedCat << " LIST ---\n";
            for(int i=0; i<catFoods.size(); i++)
                cout << i+1 << ". " << catFoods[i].name << "\n";

            cout << "Select a food to view details (0 to cancel): ";
            int fchoice; cin >> fchoice; cin.ignore();
            if(fchoice > 0 && fchoice <= catFoods.size()){
                Food f = catFoods[fchoice-1];
                cout << "\nName: " << f.name << "\nCalories: " << f.calories << " kcal\nCategory: " << f.category << "\n";
            }
        } else if(choice == 6) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while(choice != 6);
}