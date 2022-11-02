
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Job {
   
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
} Job;
 
int compare(const void* a, const void* b)
{
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return (temp2->profit - temp1->profit);
}
 
int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}
 
void printJobScheduling(Job arr[], int n)
{
    qsort(arr, n, sizeof(Job), compare);
 
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n]; // To keep track of free time slots
 
    for (int i = 0; i < n; i++)
        slot[i] = false;
 
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }
 
    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%c ", arr[result[i]].id);
}

int main()
{
    int n;
    printf("Enter the No. Of Jobs: ");
    scanf("%d",&n);
    Job arr[n];
    int deadline,profit;
    char job[10];

   for(int i=0; i < n; i++){
        printf("Enter Job Name : ");
        scanf("%s", &arr[i].id);
        printf("Enter Deadline for %s : ",&arr[i].id);
        scanf("%d",&arr[i].dead);
        printf("Enter the profit for %s : ", &arr[i].id);
        scanf("%d", &arr[i].profit);
    }

    printf("Following is maximum profit sequence of jobs \n");
    printJobScheduling(arr, n);
    return 0;
}
