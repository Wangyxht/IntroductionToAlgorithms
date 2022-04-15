#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//选择排序
int* SelectSort(int*,int);

int main(void)
{
    int test[SIZE]={23,4,67,89,90,56,43,78,34,8};
    int i;

    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');


    SelectSort(test,SIZE);

    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');

    system("pause");
    return 0;
}

int* SelectSort(int* array,int arraySize)
{
    int i;
    int j;
    int minNumber;
    int temp;

    for(i=0;i<arraySize-1;i++)
    {

        temp=i;
        for(j=i+1,minNumber=array[i];j<arraySize;j++)
        {
            if(array[j]<minNumber)
            {
                minNumber=array[j];//对于从数组第i+1的值到第n个值，寻找此区间的最小值
                temp=j;//存储下标
            }

        }
        if(temp!=i)//如果最小值不是数组第i个值
        {
            array[temp]=array[i];
            array[i]=minNumber;//交换第i个值与最小值的次序.
        }    
    }

    return array;
}