for(int i = 0; i < n; i++) {
    if(amount - coins[i] >= 0) {
        int chotaAmount = amount - coins[i];
        int chotaAns = minCoinsNeeded(coins, n, chotaAmount);

        if(chotaAns < ans) {
            ans = chotaAns;
        }
    }
    }