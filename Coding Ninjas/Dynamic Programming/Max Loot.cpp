int maxMoneyLooted(int *houses, int n)
{
    /*
        We are assuming that the n houses are numbered from 0 to n - 1.
        maxMoney[i] stores the maximum amount of money that can be looted
        from houses numbered 0 to i (both inclusive).
    */        
        
    int *maxMoney = new int[n];
    maxMoney[0] = houses[0];

    if (n > 1)
    {
        maxMoney[1] = max(houses[1], maxMoney[0]);
    }

    for (int i = 2; i < n; i++)
    {
        //maxMoney[i-2] + houses[i] : In case we are including current element
        //maxMoney[i-1] : In case we are excluding current element

        maxMoney[i] = max(maxMoney[i - 2] + houses[i], maxMoney[i - 1]);
    }
    cout<<endl;

    int result = maxMoney[n - 1];

    delete[] maxMoney;

    return result;
}
