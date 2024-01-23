#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
    const int num_dice = 2;
    const int sides_per_die = 6;
    const int total_outcomes = sides_per_die * sides_per_die;

    // Initialize an array to store the count of occurrences for each sum
    std::vector<int> sum_counts(2 * sides_per_die + 1, 0);

    // Iterate through all possible combinations of two dice rolls
    for (int die1 = 1; die1 <= sides_per_die; ++die1)
    {
        for (int die2 = 1; die2 <= sides_per_die; ++die2)
        {
            int sum = die1 + die2;
            sum_counts[sum]++;
        }
    }

    // Calculate and display the probabilities
    std::cout << "Sum\tProbability\n";
    for (int i = 2; i <= 2 * sides_per_die; ++i)
    {
        double probability = static_cast<double>(sum_counts[i]) / total_outcomes;
        std::cout << i << "\t" << std::fixed << std::setprecision(4) << probability << "\n";
    }

    return 0;
}
