#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void GenerateRandomArray(int *A, int length){  //genero array con numeri random  e seed 13
    srand(13);
    for(int i = 0; i <= length; i++)
        A[i] = rand();

};

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
    int t_start;
    int t_end;

    int *A;

    for (instance = 1; instance <= max_instances; instance++){
        GenerateRandomArray(A,length);
        t_start = clock();
        InsertionSort(A,length);
        t_end = clock();
        t_elapsed = t_end - t_start;
        t_tot = t_tot + t_elapsed;
    }
    return t_tot/max_instances;
};

void Experiment(int min_length, int max_length) {
    int length;
    int step = 1000;
    int time=0;
    int max_instances = 50;


   for (length = min_length; length <= max_length; length = length+step){
       time = SingleExperiment(length, max_instances); 
       printf("%d", time);
}
       // printf("%d", time);
}

int main(void) {
    int max_length = 50000;
    int min_length = 1000;
    
    Experiment(min_length,max_length);

}