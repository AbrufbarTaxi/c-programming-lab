#include<stdio.h>
#include<math.h>

// count the number of primes between l and m.
int isPrime(int n){
	if (n<2) return 0;
	int i = 2;
	for (; i <= sqrt(n); i++) { 
        if (n % i == 0)  
            return 0;  
    } 
    return 1;
}

int countPrime(int l, int h){
	int c = 0, i;
	for(i = l; i <= h; i++) 
		if(isPrime(i))
			c++;
	return c;
}


int main(){
	int l, h;
	scanf("%d%d", &l, &h);
	printf("%d\n", countPrime(l, h));
	return 0;
}