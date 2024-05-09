#include <stdio.h>
#include <stdlib.h>
int findLargestNode(int A[], int n, int index)
{
    if (index >= n)
    {
        return -1;
    }

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    int largest = A[index];

    if (leftChild < n)
    {
        int leftMax = findLargestNode(A, n, leftChild);
        if (leftMax > largest)
        {
            largest = leftMax;
        }
    }

    if (rightChild < n)
    {
        int rightMax = findLargestNode(A, n, rightChild);
        if (rightMax > largest)
        {
            largest = rightMax;
        }
    }

    return largest;
}
int main()
{
    int treeSize;
    printf("\nEnter the size of the tree array: ");
    scanf("%d", &treeSize);

    int *treeArray = (int *)malloc(treeSize * sizeof(int));

    printf("Enter the elements of the tree array:\n");
    for (int i = 0; i < treeSize; i++)
    {
        scanf("%d", &treeArray[i]);
    }

    int largest = findLargestNode(treeArray, treeSize, 0);
    printf("Largest Node in the Tree: %d\n", largest);

    free(treeArray);

    return 0;
}