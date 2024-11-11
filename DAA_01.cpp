//Write a program to implement Fractional knapsack using Greedy algorithm.
//Name:Kalash Malge
//RollNo:TIA31
//Batch:B


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 

using namespace std;

class Greedy {
public:
    int id;
    float wt, pft, pw, amt;
    bool selected;  // To mark if an item is selected

    Greedy() : selected(false) {}  // Initialize selected to false

    void calculateratio() {
        pw = pft / wt;
    }
};

int main() {
    int n;
    float capacity, totalWeight = 0, totalProfit = 0;

    cout << "Enter total number of objects: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    vector<Greedy> items(n);

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        items[i].amt = 0;

        cout << "Enter weight of object " << (i + 1) << ": ";
        cin >> items[i].wt;

        cout << "Enter profit of object " << (i + 1) << ": ";
        cin >> items[i].pft;

        items[i].calculateratio();
    }

    sort(items.begin(), items.end(), [](const Greedy& a, const Greedy& b) {
        return a.pw > b.pw;
    });

    cout << "\nItems sorted by profit/weight ratio:\n";
    cout << "id\tweight\tprofit\tp/w\n";
    for (const auto& item : items) {
        cout << item.id << "\t" << item.wt << "\t" << item.pft << "\t" << fixed << setprecision(2) << item.pw << "\n";
    }

    cout << "\nKnapsack solution:\n";
    cout << "id\tweight\tprofit\tp/w\tamount\n";

    for (auto& item : items) {
        if (totalWeight < capacity) {
            if (item.wt <= (capacity - totalWeight)) {
                item.amt = 1; 
                item.selected = true;  // Mark item as selected
                totalWeight += item.wt;
                totalProfit += item.pft;
            } else {
                item.amt = (capacity - totalWeight) / item.wt;  // Xi
                item.selected = true;  // Mark item as selected
                totalWeight = capacity;
                totalProfit += item.amt * item.pft;  // Xi * Pi
                break; 
            }
        } else {
            break; 
        }
    }

    for (const auto& item : items) {
        cout << item.id << "\t" << item.wt << "\t" << item.pft << "\t" << item.pw << "\t" << fixed << setprecision(2) << item.amt << "\t" << (item.selected ? "Selected" : "Not Selected") << "\n";
    }

    cout << "\nSelected object ids: ";
    for (const auto& item : items) {
        if (item.selected) {
            cout << item.id << " ";
        }
    }

    cout << "\n\nNon-selected object ids: ";
    for (const auto& item : items) {
        if (!item.selected) {
            cout << item.id << " ";
        }
    }

    cout << "\nTotal Profit is: " << totalProfit << endl;

    return 0;
}