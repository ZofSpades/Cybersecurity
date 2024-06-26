#include <stdio.h>
#include <string.h>

void encrypt(char s[], int shift) {
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }
        s[i] = ch;
    }
}

void decrypt(char s[], int shift) {
    encrypt(s, 26 - (shift % 26));
}

int main() {
    char s[100];
    int shift, n;
    int i = 0;
    char ch;
    printf("What would you like to do?\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &n);
    getchar();
    printf("Enter the string: ");
    while (i < 99 - 1 && (ch = getchar()) != '\n') {
        s[i++] = ch;
    }
    s[i] = '\0';
    printf("Enter the shift number: ");
    scanf("%d", &shift);
    if (n == 1) {
        encrypt(s, shift);
        printf("Encrypted string: %s\n", s);
    } else if (n == 2) {
        decrypt(s, shift);
        printf("Decrypted string: %s\n", s);
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}