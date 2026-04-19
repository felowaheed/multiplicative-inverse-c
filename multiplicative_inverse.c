//felopateer waheed william 
#include <stdio.h>
int extendedEuclideanAlgorithm(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclideanAlgorithm(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}
int multiplicativeInverse(int a, int mod) {
    int x, y;
    int gcd = extendedEuclideanAlgorithm(a, mod, &x, &y);
    if (gcd != 1)
        return 0; 
    else
        return (x % mod + mod) % mod; 
}
int main() {
    char choice;
    do {
        int a, mod;
        printf("Enter the number (a): ");
        scanf("%d", &a);
        printf("Enter the mod number (m): ");
        scanf("%d", &mod);
        int inverse = multiplicativeInverse(a, mod);
        if (inverse != 0)
            printf("The multiplicative inverse of %d mod %d is %d\n", a, mod, inverse);
        else
            printf("There is no multiplicative inverse of %d mod %d\n", a, mod);
        
        printf("Press 'f' to enter another (a) and (m), or press 'k' to close the code: ");
        scanf(" %c", &choice); 
    } while (choice == 'f' || choice == 'F');
    
    printf("Exiting the program. Goodbye!\n");
    return 0;
}
