#include <bits/stdc++.h>
using namespace std;

vector<pair<int, double>> ans;

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

bool check(vector<int> &dice1, vector<int> &dice2)
{
    sort(dice1.begin(), dice1.end());
    sort(dice2.begin(), dice2.end());

    // cout << "Here" << endl;
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << dice1[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << dice2[i] << " ";
    // }
    // cout << endl;

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
            return false;
        }
    }

    return true;
}

bool DoomedDice(vector<int> &dice1, vector<int> &dice2, int indx1, int indx2)
{
    if (indx1 == 6)
    {
        if (indx2 == 6)
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

                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (indx2 < 6)
            {
                for (int j = 1; j <= 8; j++)
                {
                    dice2[indx2] = j;
                    if (DoomedDice(dice1, dice2, indx1, indx2 + 1))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        dice1[indx1] = i;

        if (indx2 < 6)
        {
            for (int j = 1; j <= 8; j++)
            {
                dice2[indx2] = j;
                if (DoomedDice(dice1, dice2, indx1 + 1, indx2 + 1))
                {
                    return true;
                }
            }
        }
        else
        {
            if (DoomedDice(dice1, dice2, indx1 + 1, indx2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    return false;
}

int main()
{
    probability();
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }
    vector<int> dice1 = {1, 2, 3, 4, 0, 0};
    vector<int> dice2 = {8, 0, 0, 0, 0, 0};

    // cout << check(dice1, dice2);
    // int n = 6;

    DoomedDice(dice1, dice2, 4, 1);

    return 0;
}
