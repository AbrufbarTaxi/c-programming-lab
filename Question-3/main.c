#include <stdio.h>
#include <math.h>

// Print a 16-bit binary representation (keep existing format/spacing)
void printBinary(unsigned int n)
{
    for (int i = 15; i >= 0; i--) {
        printf("%u", (n >> i) & 1);
    }
    printf("\n");
}

// Return how many bits are 1 in the 16-bit value
int countSetBits(unsigned int n)
{
    unsigned long mask=1;
    int count =0;
    for(int i=15; i>0; i--) {
        if(n&mask) count++;
        mask*=2;
    }
    return count;
}

// Set bit at position k (1 = LSB). Return updated value.
unsigned int setBit(unsigned int n, unsigned int k)
{
    // unsigned long mask =pow(2,k-1);
    unsigned long mask = 1U << (k-1);
    unsigned int n_ = n | (mask);
    return n_;
}

// Clear bit at position k (1 = LSB). Return updated value.
unsigned int clearBit(unsigned int n, unsigned int k)
{
    unsigned long mask = 1U << (k - 1);
    unsigned int n_ = n & ~(mask);
    return n_;
}

// Toggle bit at position k (1 = LSB). Return updated value.
unsigned int toggleBit(unsigned int n, unsigned int k)
{
    unsigned long mask = 1U << (k - 1);
    unsigned int n_ = n ^ (mask);
    return n_;
}

// Return 1 if bit at position k is set, else 0.
int isBitSet(unsigned int n, unsigned int k)
{
    return (n>>(k-1))&1;
}

// Swap bits at positions i and j. Return updated value.
unsigned int swapBits(unsigned int n, unsigned int i, unsigned int j)
{
    unsigned int bit_i = (n >> (i - 1)) & 1;
    unsigned int bit_j = (n >> (j - 1)) & 1;

    if (bit_i != bit_j) {
        n ^= (1U << (i - 1));
        n ^= (1U << (j - 1));
    }
    return n;
}

int main()
{
    unsigned int n;
    unsigned int k_set, k_clear, k_toggle, k_check, i_swap, j_swap;

    // Input order (one per line except last two on one line):
    // n, k_set, k_clear, k_toggle, k_check, i_swap j_swap
    scanf("%u", &n);
    scanf("%u", &k_set);
    scanf("%u", &k_clear);
    scanf("%u", &k_toggle);
    scanf("%u", &k_check);
    scanf("%u %u", &i_swap, &j_swap);

    printf("Initial:            ");
    printBinary(n);

    n = setBit(n, k_set);
    printf("After set bit:      ");
    printBinary(n);

    n = clearBit(n, k_clear);
    printf("After clear bit:    ");
    printBinary(n);

    n = toggleBit(n, k_toggle);
    printf("After toggle bit:   ");
    printBinary(n);

    int checked = isBitSet(n, k_check);
    printf("Bit %u is %s\n", k_check, checked ? "SET" : "NOT SET");

    n = swapBits(n, i_swap, j_swap);
    printf("After swap bits:    ");
    printBinary(n);

    int count = countSetBits(n);
    printf("Total SET bits: %d\n", count);

    return 0;
}
