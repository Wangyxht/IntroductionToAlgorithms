#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define SIZE 10

//快速排序函数
void QuickSort(int*,int,int);
//交换数值函数
void Swap(int*,int*);
//数组初始划分函数（快速排序）
int Partition(int*,int,int);



int main (void)
{
    int test[SIZE]={89,4,1000,39,34,55,2,999,43,34};
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
    int pivotElement,pivotNumber;//设置一个主元，主元将于数组中的元素进行比较。
    
    //随机化版本的快速排序主要针对主元的选取进行了优化，采用随机抽样选取主元让排序算法有较好的性能。
    //以下为与快速排序不同的随机数生成代码
    srand((unsigned int)time(0));        
    pivotNumber=rand()%(arraySize-startNumber+1)+startNumber;
    pivotElement=array[pivotNumber];
    
    //选定好主元后切记要将主元与主元区（一般为数组最后一个值）进行交换。
    Swap(&array[pivotNumber],&array[arraySize]);

    //剩余代码与原快速排序源码相同。
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


