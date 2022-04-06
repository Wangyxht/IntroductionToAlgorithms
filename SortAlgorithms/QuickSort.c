#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

//快速排序函数
void QuickSort(int*,int,int);
//交换数值函数
void Swap(int*,int*);
//数组初始划分函数（快速排序）
int Partition(int*,int,int);

int main (void)
{
    int test[SIZE]={89,4,1000,9,34,55,999,876,43,10};
    int i;

    for(i=0;i<SIZE;i++)//打印原值。
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');

    QuickSort(test,0,SIZE);//快速排序

    for(i=0;i<SIZE;i++)//打印排序后的数值。
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');

    system("pause");
    return 0;

}

void QuickSort(int* array,int startNum ,int arraySize)
{
    
    int newArraySize;//定义初始划分后两个数组的边界下标。

    if(startNum<arraySize)//当传入数组不是空数组时
    {
        newArraySize=Partition(array,startNum,arraySize-1);//进行初始划分

        QuickSort(array,startNum,newArraySize);//对划分的左部分继续快速排序（递归调用）；
        QuickSort(array,newArraySize+1,arraySize);//对划分的右部分继续快速排序（递归调用）；
    }

    return ;
}

void Swap(int*numberA ,int*numberB)
{
    int temp;
    
    temp=*numberA;
    *numberA=*numberB;
    *numberB=temp;
 //输入两个数的地址作为参数交换两个数的值。
    return ;
}

int Partition(int* array ,int startNumber,int arraySize)
{
    int i=startNumber-1, j=startNumber;
    int pivotElement=array[arraySize];//设置一个主元，主元将于数组中的元素进行比较。

    while(j<arraySize)
    {
        if(array[j]<pivotElement)
        {
            i++;
            Swap(&array[j],&array[i]);
            
        }

        j++;
    }

    Swap(&array[arraySize],&array[i+1]);
 //此过程具体图示详见《算法导论》P96 图7-1、7-2
    return i+1;

}