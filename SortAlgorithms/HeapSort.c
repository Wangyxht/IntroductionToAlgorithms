

#include<stdio.h>
#include<stdlib.h>

//左孩子对应数组下标
#define LEFTDATANUMBER (2*i+1)

//右孩子对应数组下标。
#define RIGHTDATANUMBER (2*i+2)

//数组长度
#define SIZE 10


//使每一个树节点调整为最大堆
void MaxHeapify(int*,int,int);
//构建最大堆的数组并维护
void BuildMaxHeap(int*,int);
//堆排序函数
void HeapSort(int* ,int);

int main (void)
{
    int test[SIZE]={23,56,90,67,33,88,54,89,84,12};
    int i=0;

    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');

    
    HeapSort(test,SIZE-1);
    
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');



    system("pause");
    return 0;
}




void MaxHeapify(int* array,int start,int n)
{
    int i=start;
    int largest;
    int left=LEFTDATANUMBER;
    int right=RIGHTDATANUMBER;
    int temp;

    if(left<=n && array[left]>=array[i])
    {
        largest=LEFTDATANUMBER;
    }

    else
    {
        largest=i;
    }

    if(right<=n && array[right]>=array[largest])
    {
        
        largest=RIGHTDATANUMBER;
    }

    if (largest!=i)//分别比较节点元素、左孩子元素、右孩子元素，若不符合最大堆性质，交换位置是节点具有最大堆性质。
    {
        temp=array[i];       
        array[i]=array[largest];
        array[largest]=temp;

        MaxHeapify(array,largest,n);//交换后，被交换的元素之后的节点可能不会维持最大堆性质，所以要对被交换位置进行最大堆维持。
    }

    
}

void BuildMaxHeap(int*array,int length)//构建一个最大堆。
{
    int i;
    
    for(i=(length/2);i>=0;i--)//遍历数据，使每个叶节点进行有效堆的维持，整个数组具有最大堆的性质。
    {
        MaxHeapify(array,i,length);
    }    
}

void HeapSort(int*array, int n)
{
    int i;
    int heapSize=n;
    int temp;

    BuildMaxHeap(array,heapSize);//建立初始最大堆。
    
    for(i=n;i>=1;i--)//对于数组最后一个值到第二个值
    {        
        temp=array[0];
        array[0]=array[i];
        array[i]=temp;//对已排序为最大堆的数组将最大值排在最后

        heapSize--;//数组最后一个值已经为最大值，堆的有效元素-1.
        MaxHeapify(array,0,heapSize);//对数组有效堆中的元素进行有效堆的维持，以便继续进行排序。
          
    }
}