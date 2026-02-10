#include <stdio.h>
#include <string.h>
// count the number of vowels in a input string
int count_vowels(char* str) {
    int count = 0;
    int n = strlen(str);
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<5; j++) {
            if (str[i] == vowels[j]) { 
                count++;
                continue; 
            }
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    
    int result = count_vowels(s);
    printf("Number of vowels: %d\n", result);
}