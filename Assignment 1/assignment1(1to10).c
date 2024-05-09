#include <stdio.h>
#include <string.h>

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int sum(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);
}

int stringCompare(char s1[], char s2[])
{
    if (strlen(s1) == 0 && strlen(s2) == 0)
        return 0;
    else if (s1[0] < s2[0])
        return -1;
    else if (s1[0] > s2[0])
        return 1;
    else
        return stringCompare(s1 + 1, s2 + 1);
}

int findLargest(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    else
    {
        int maxRest = findLargest(arr + 1, n - 1);
        return (arr[0] > maxRest) ? arr[0] : maxRest;
    }
}

int findHCF(int n1, int n2)
{
    if (n1 % n2 == 0)
        return n2;
    else
        return findHCF(n2, n1 % n2);
}

int search(int num, int L[], int n)
{
    if (n == 0)
        return 0;
    else if (L[0] == num)
        return 1;
    else
        return search(num, L + 1, n - 1);
}

void printReverse(int L[], int n)
{
    if (n == 0)
        return;
    else
    {
        printReverse(L + 1, n - 1);
        printf("%d ", L[0]);
    }
}

int isPalindrome(char S[], int n)
{
    if (n == 0 || n == 1)
        return 1;
    else if (S[0] != S[n - 1])
        return 0;
    else
        return isPalindrome(S + 1, n - 2);
}

void replaceChar(char S[], char c1, char c2)
{
    if (strlen(S) == 0)
        return;
    else
    {
        if (S[0] == c1)
            S[0] = c2;
        replaceChar(S + 1, c1, c2);
    }
}

void sortArray(int A[], int n)
{
    if (n == 1)
        return;
    else
    {
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (A[j] > A[i])
                i = j;
        }
        int temp = A[i];
        A[i] = A[n - 1];
        A[n - 1] = temp;
        sortArray(A, n - 1);
    }
}

int main()
{
    int z;
    printf("Enter a number to find its factorial and sum of the first those no of integers: ");
    scanf("%d", &z);

    printf("Factorial of %d: %d\n", z, factorial(z));
    printf("Sum of the first %d integers: %d\n", z, sum(z));

    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("String comparison: %d\n", stringCompare(str1, str2));

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Largest integer in the array: %d\n", findLargest(arr, size));

    int n1, n2;
    printf("Enter two numbers to find their HCF: ");
    scanf("%d%d", &n1, &n2);
    int hcfResult = findHCF(n1, n2);
    printf("HCF of %d and %d: %d\n", n1, n2, hcfResult);

    int searchNum;
    printf("Enter a number to search in the list: ");
    scanf("%d", &searchNum);
    int list[size];
    printf("Enter the elements of the list: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    printf("Search for %d in the list: %d\n", searchNum, search(searchNum, list, size));

    int reverseList[size];
    printf("Enter the elements of the list to reverse: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &reverseList[i]);
    }
    printf("Reverse of the list: ");
    printReverse(reverseList, size);
    printf("\n");
    printf("Enter n i.e, length of the string to check it is palindrome or not\n");
    int v;
    scanf("%d", &v);
    char palindromeStr[v];
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", palindromeStr);
    printf("Is \"%s\" a palindrome: %d\n", palindromeStr, isPalindrome(palindromeStr, strlen(palindromeStr)));

    char replaceStr[size];
    char c1, c2;
    printf("Enter a string: ");
    scanf("%s", replaceStr);
    printf("Enter the character to replace: ");
    scanf(" %c", &c1);
    printf("Enter the character to replace with: ");
    scanf(" %c", &c2);
    replaceChar(replaceStr, c1, c2);
    printf("After replacing '%c' with '%c': %s\n", c1, c2, replaceStr);

    int arrayToSort[size];
    printf("Enter the size of the array to sort: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arrayToSort[i]);
    }
    sortArray(arrayToSort, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrayToSort[i]);
    }
    printf("\n");

    return 0;
}