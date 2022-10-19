#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void GenerateRandomArray(int *A, int length){  //genero array con numeri random  e seed 13
    srand(13);
    for(int i = 0; i <= length; i++)
        A[i] = rand();

};

int IsSorted(int *A, int length){
    for (int i = 1; i < length; i++)
{
    if (A[i - 1] > A[i])
    {
    return 0; // not sorted - false
    }
}
return 1; // sorted - true 
}


void InsertionSort(int *A, int length)
{
    int key;
    int i;
    int j = 0;
    for (i=1; i < length; i++) 
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) 
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
};
  
int SingleExperiment(int length, int max_instances) {

    int t_tot = 0;
    int instance;
    float t_elapsed;
    float t_start;
    float t_end;

    int *A = malloc(length);

    for (instance = 1; instance <= max_instances; instance++){
        GenerateRandomArray(A,length);
        IsSorted(A, length);
        t_start = clock();
        InsertionSort(A,length);
        IsSorted(A,length);
        t_end = clock();
        t_elapsed = t_end - t_start;
        t_tot = t_tot + t_elapsed;
    }
    return t_tot/max_instances;
    
    free(A);
};

void Experiment(int min_length, int max_length) {
    //FILE *fp;
    int length;
    int step = 1000;
    float time=0;
    int max_instances = 50;


   for (length = min_length; length <= max_length; length = length+step){
       time = SingleExperiment(length, max_instances);
       //fprintf(fp, "length:%d : %f \n",length, time);
       printf("%f\n", time);
    }
    //fclose(fp);
    }


int main(void) {
    int max_length = 50000;
    int min_length = 1500;
    
    Experiment(min_length,max_length);
    return 1;
}