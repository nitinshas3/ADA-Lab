#include <stdio.h>

int count;  // single counter

// Euclid's algorithm (modulo version)
int gcdEuclid(int m, int n) {
    count = 0;
    while (n != 0) {
        int temp = m % n;
        m = n;
        n = temp;
        count++;
    }
    return m;
}

// Consecutive integer checking method
int gcdConsecutive(int m, int n) {
    count = 0;
    int t = (m < n) ? m : n;
    for (int i = t; i > 0; i--) {
        count++;
        if (m % i == 0 && n % i == 0)
            return i;
    }
    return 1;
}

// Repeated subtraction method
int gcdSubtraction(int m, int n) {
    count = 0;
    while (m != n) {
        count++;
        if (m > n) m -= n;
        else n -= m;
    }
    return m;
}

void tester() {
    int m, n;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &m, &n);

    printf("Euclid GCD: %d (comparisons=%d)\n", gcdEuclid(m, n), count);
    printf("Consecutive GCD: %d (comparisons=%d)\n", gcdConsecutive(m, n), count);
    printf("Subtraction GCD: %d (comparisons=%d)\n", gcdSubtraction(m, n), count);
}

void plotter() {
    FILE *f1 = fopen("euclid.txt", "w");
    FILE *f2 = fopen("consec.txt", "w");
    FILE *f3 = fopen("subtraction.txt", "w");

    for (int n = 10; n <= 100; n += 10) {
        // Worst case chosen as (n, n-1) for all methods
        gcdEuclid(n, n-1);
        fprintf(f1, "%d\t%d\n", n, count);

        gcdConsecutive(n, n-1);
        fprintf(f2, "%d\t%d\n", n, count);

        gcdSubtraction(n, n-1);
        fprintf(f3, "%d\t%d\n", n, count);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    int ch;
    printf("Enter\n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);

    if (ch == 1) tester();
    else if (ch == 2) plotter();
    else printf("Invalid choice\n");

    return 0;
}
