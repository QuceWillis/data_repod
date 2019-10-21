//Quentin Thorpe
//Merge Sort: Sort a txt file with 30 integers using merge and send it sorted to another txt file

#include <stdio.h>
#include <stdlib.h>


//Merge algorithm
void merge(int arr[], int l, int m, int r)
{
        int i, j, k; //counters
        int n1 = m - l + 1; //0 positon
        int n2 = r - m; //500 position

        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
                L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];
        //puts data into lefthalf and righthalf of array

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) //compares
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
                k++; //count
        }
        while (i < n1) //add remaining to the left
        {
                arr[k] = L[i];
                i++;
                k++;
        }
        while (j < n2) //add remaining to the right
        {
                arr[k] = R[j];
                j++;
                k++;
        }
}


void mergeSort(int arr[], int l, int r)
{
        if (l < r)
        {
                int m = l + (r - l) / 2; //splits in half
                mergeSort(arr, l, m); //sorts left half
                mergeSort(arr, m+1, r); //sorts right half
                merge(arr, l, m, r);
        }
}


int main()
{

        FILE *fp, *fp2; //Calls files
        int arr[30] = {0}; //sets size of array to 30
        int length = sizeof(arr)/sizeof(arr[0]); //length
        int i = 0; //counter

        fp = fopen("data1.txt", "r"); //Opens file
        if (fp == NULL)
        {
                printf("Cannot open file \n");
                exit(0);
        }

        fp2 = fopen("out1.txt", "w"); //Opens file
        if (fp2 == NULL)
        {
                printf("Cannot open file \n");
                exit(0);
        }

        for (i = 0; i < length; i++) //takes value from file
        {
        fscanf(fp, "%d", &arr[i]);
        }

        mergeSort(arr, 0, length - 1); //calls merge sort to sort

        for (i = 0; i < length; i++) //sends sorted value to out file
        {
                printf("num[%d] = %d\n", i, arr[i]);
                fprintf(fp2, "%d ", arr[i]);
        }

        printf("\nContents sorted and sent to out1.txt\n");

        fclose(fp); //close files
        fclose(fp2); //close files

        return 0;
}
