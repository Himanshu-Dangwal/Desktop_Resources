#include <bits/stdc++.h>
using namespace std;

vector<pair<int, double>> ans;
unordered_map<string, bool> memo;

void probability()
{
    const int num_dice = 2;
    const int sides_per_die = 6;
    const int total_outcomes = sides_per_die * sides_per_die;

    vector<int> sum_counts(2 * sides_per_die + 1, 0);
    for (int die1 = 1; die1 <= sides_per_die; ++die1)
    {
        for (int die2 = 1; die2 <= sides_per_die; ++die2)
        {
            int sum = die1 + die2;
            sum_counts[sum]++;
        }
    }

    for (int i = 1; i <= 2 * sides_per_die; ++i)
    {
        double probability = static_cast<double>(sum_counts[i]) / total_outcomes;
        ans.push_back({i, probability});
    }
}

bool check(const vector<int> &dice1, const vector<int> &dice2)
{
    string state = "";
    for (int val : dice1)
        state += to_string(val) + " ";
    for (int val : dice2)
        state += to_string(val) + " ";

    if (memo.find(state) != memo.end())
        return memo[state];

    sort(dice1.begin(), dice1.end());
    sort(dice2.begin(), dice2.end());

    const int sides_per_die = 6;
    const int total_outcomes = sides_per_die * sides_per_die;
    vector<int> sum_counts(2 * sides_per_die + 1, 0);

    for (int die1 : dice1)
    {
        for (int die2 : dice2)
        {
            int sum = die1 + die2;
            sum_counts[sum]++;
        }
    }

    vector<pair<int, double>> temp;
    for (int i = 1; i <= 2 * sides_per_die; ++i)
    {
        double probability = static_cast<double>(sum_counts[i]) / total_outcomes;
        temp.push_back({i, probability});
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (abs(ans[i].second - temp[i].second) > 1e-6)
        {
            memo[state] = false;
            return false;
        }
    }

    memo[state] = true;
    return true;
}

bool DoomedDice(vector<int> &dice1, vector<int> &dice2, int indx1, int indx2)
{
    string state = to_string(indx1) + " " + to_string(indx2);
    if (memo.find(state) != memo.end())
        return memo[state];

    if (indx1 == 6 && indx2 == 6)
    {
        if (check(dice1, dice2))
        {
            cout << "Dice1: ";
            for (int x : dice1)
            {
                cout << x << " ";
            }
            cout << endl;

            cout << "Dice2: ";
            for (int x : dice2)
            {
                cout << x << " ";
            }
            cout << endl;

            memo[state] = true;
            return true;
        }
        else
        {
            memo[state] = false;
            return false;
        }
    }

    vector<int> &currentDice = (indx1 < 6) ? dice1 : dice2;
    int possibilities = (indx1 < 6) ? 4 : 12;

    for (int i = 1; i <= possibilities; i++)
    {
        currentDice[indx1 % 6] = i;
        if (DoomedDice(dice1, dice2, indx1 + 1, indx2 + (indx1 < 6)))
        {
            memo[state] = true;
            return true;
        }
    }

    memo[state] = false;
    return false;
}

int main()
{
    probability();
    vector<int> dice1(6, 0);
    vector<int> dice2(6, 0);
    int n = 6;
    DoomedDice(dice1, dice2, 0, 0);

    return 0;
}
