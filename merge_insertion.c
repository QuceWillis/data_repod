//Quce Willis
//Merge and Insertion Sort

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIZE 50

//Merge function
void merge(int arr[], int l, int m, int r)
{
        int i, j, k; //counters
        int n1 = m - l + 1; //left half
        int n2 = r - m; //right half

        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
                L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];
        //Assigning values to left half and right half arrays

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) 
        {
                if (L[i] <= R[j])
                {
                        arr[k] = L[i];
                        i++;
                }
                else
                {
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }
        while (i < n1) //Add remainder to left
        {
                arr[k] = L[i];
                i++;
                k++;
        }
        while (j < n2) //Add remainder to right
        {
                arr[k] = R[j];
                j++;
                k++;
        }
}

void insertionSort(int *arr, int length)
{
        int i, key, j; //counter and value
        for (i = 1; i < length; i++)
        {
                key = arr[i]; //size
                j = i - 1;

                while (j >= 0 && arr[j] > key)

                {
                        arr[j + 1] = arr[j]; //move values ahead

                        j = j - 1;
                }
                arr[j + 1] = key;
        }
}

void mergeSort(int *arr, int l, int r)
{
        if (l < r)
        {
                if (r - l <= 10) //calls insertion sort if less than or equal to 10
                {
                        int m = l + (r - 1) / 2;
                        insertionSort(arr, r);
                }
                else
                {
                        int m = l + (r - l) / 2; //splits
                        mergeSort(arr, l, m); //Left half
                        mergeSort(arr, m+1, r); //Right half
                        merge(arr, l, m, r); //Merge them together
                }
        }
}


int main()
{

        int *arr = malloc(SIZE *sizeof(int));
        int length = 0; //Counter
        int userInput;

        if (arr == NULL)
        {
                printf("Failed to return memory");
                exit(0);
        }


        printf("Enter up to 50 integers seperated by <enter>. input a character (c) to stop\n");

        while ((scanf(" %d", &userInput)) == 1) //User inputted loop to gather data for array
        {
                arr = realloc(arr, (length + 1) * SIZE * sizeof(int));
                arr[length] = userInput;
                length++;
        }

        mergeSort(arr, 0, length); //Sorting


        for (int i = 0; i < length; i++) //Values after sorted
        {
                printf("num[%d] = %d\n", i, arr[i]);
        }



        printf("\nContents sorted\n");

        free(arr);

        return 0;
}


