long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

