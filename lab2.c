#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#define SIZE 24
#define nRows 8
#define nCols 3

// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr[], int length);
void rem_align(int arr[], int length, int pos);
void insert_align(int arr[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[nRows][nCols]);
void print_trans_matrix(int arr2d[nRows][nCols]);
bool found_duplicate(int arr[], int length);
void flip_array(int arr[], int length);

int main()
{
    int arr[SIZE];
    int arr2d[nRows][nCols];

    // Initialize the 1D array
    set_array(arr, SIZE);

    // Call other functions and test them
    rem_align(arr, SIZE, 2);
    print_array(arr, SIZE);

    insert_align(arr, SIZE, 2, 100);
    print_array(arr, SIZE);

    int arr3[nRows * nCols]; // New 1D array for reshaping
    reshape(arr, SIZE, arr2d);
    print_matrix(arr2d, nRows);

    print_trans_matrix(arr2d);

    if (found_duplicate(arr, SIZE))
        printf("Duplicates found.\n");
    else
        printf("No duplicates found.\n");

    flip_array(arr, SIZE);
    print_array(arr, SIZE);

    return 0;
}

// FUNCTION IMPLEMENTATIONS

void print_array(int array[], int length) 
{
    for (int i = 0; i < length; i++)
        printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows) 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < nCols; j++)
            printf("mat[%d][%d]= %d\n", i, j, mat[i][j]);
        puts("");
    }
}

void set_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        arr[i] = i;
}

void rem_align(int arr[], int length, int pos)
{
    if (pos < 0 || pos >= length)
    {
        printf("Invalid index. Deletion failed.\n");
        return;
    }
    for (int i = pos; i < length - 1; i++)
        arr[i] = arr[i + 1];
    arr[length - 1] = 0; // deleting the last element
}

void insert_align(int arr[], int length, int pos, int value)
{
    if (pos < 0 || pos >= length)
    {
        printf("Invalid index. Insertion failed.\n");
        return;
    }
    for (int i = length - 1; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
}

void reshape(int arr[], int length, int arr2d[nRows][nCols])
{
    if (length != nRows * nCols)
    {
        printf("Error: Array length does not match the 2D array size.\n");
        return;
    }
    int k = 0;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            arr2d[i][j] = arr[k];
            k++;
        }
    }
}

void print_trans_matrix(int arr2d[nRows][nCols])
{
    for (int j = 0; j < nCols; j++)
    {
        for (int i = 0; i < nRows; i++)
        {
            printf("mat[%d][%d] = %d\n", i, j, arr2d[i][j]);
        }
        puts("");
    }
}

bool found_duplicate(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

void flip_array(int arr[], int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        int invert = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = invert;
    }
}

