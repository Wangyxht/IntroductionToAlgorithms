#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//冒泡排序算法
int* BullleSort(int*,int);

int main(void)
{
    int test[SIZE]={23,4,67,89,23,56,43,78,34,8};
    int i;

    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');


    BullleSort(test,SIZE);

    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');

    system("pause");
    return 0;
}

int* BullleSort(int* array,int arraySize)
{
    int i;
    int j;
    int temp;

    for(i=0;i<arraySize-1;i++)
    {
        for(j=0;j<arraySize-i-1;j++)//因为每次外循环完毕最大数已经处于最后位置，所以每次最后i个数不需要扫描排序
        {
            if(array[j]>array[j+1])
            {
                //如果数组角标小的数大，交换相邻两个数的次序。
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }

    return array;
}