// return value from thread to main function

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void* roll_dice(){
    int value = (rand()%6) + 1;
    int* result = malloc(sizeof(int));
    *result = value;
    return (void*) result;
}

int main(){
    srand(time(NULL));
    pthread_t th1, th2;
    int *res1, *
    res2;
    if (pthread_create(&th1, NULL, &roll_dice, NULL)!=0)
        return 1;
    if (pthread_create(&th2, NULL, &roll_dice, NULL)!=0)
        return 2;
    if(pthread_join(th1, (void**) &res1)!=0)
        return 3;
    if(pthread_join(th2, (void**) &res2)!=0)
        return 4;

    printf("Result 1: %d \n", *res1);
    printf("Result 2: %d \n", *res2);
    return 0;
}