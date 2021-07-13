

int Factorial (int n) {
    int out = 1;
    for (int i = 2; i <= n; i++)
        out *= i;
    return out;
}