//归并排序


#include <stdio.h>
#include <stdlib.h>

#define SENTRY 0x3f3f3f //设置哨兵，哨兵的要求为比任何数组的数都大。
#define SIZE 10 //设置数组长度


//两数组按大小合并的函数。
void Merge( int*, int, int ,int );

//归并排序函数
void MergeSort(int* ,int, int);

int main(void)
{
    int test[SIZE]={23,4,8,9,34,55,2,32,43,10};
    int i;

    for(i=0;i<SIZE;i++)//打印原值。
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');


    MergeSort(test,0,SIZE-1);//调用归并排序函数

    for(i=0;i<SIZE;i++)//打印排序后的数值。
    {
        printf("%d\t",test[i]);
    }
    putchar('\n');

    system("pause");
    return 0;
}



void Merge(int* array, int arrayStart ,int preArrayEnd, int arrayEnd)//数组组合函数。
{
    int lengthA=preArrayEnd-arrayStart+1;//定义已排序的左数组的长度
    int lengthB=arrayEnd-preArrayEnd;//定义已排序的右数组的长度
    int i , j , k;

    int* mergeArraryA=(int*)malloc((lengthA+1)*sizeof(int));//建立一个与比左数组大小多1的空数组。
    int* mergeArraryB=(int*)malloc((lengthB+1)*sizeof(int));//建立一个与比右数组大小多1的空数组。
    k=arrayStart;

    for(i=0;i<lengthA;i++)//复制左数组
    {
        mergeArraryA[i]=array[arrayStart+i];
    }

    for(j=0;j<lengthB;j++)//复制右数组
    {
        mergeArraryB[j]=array[preArrayEnd+j+1];
    }

    mergeArraryA[lengthA]=SENTRY;//在左右复制数组最后填入哨兵
    mergeArraryB[lengthB]=SENTRY;



    for(i=0,j=0,k=arrayStart;k<=arrayEnd ;k++)//将左右数组按从大到小顺序填入原数组，使原数组排序完整，注意哨兵的作用。
    {
        if(mergeArraryA[i]<=mergeArraryB[j])
        {
            array[k]=mergeArraryA[i];
            i++;
        }

        else
        {
            array[k]=mergeArraryB[j];
            j++;
        }


                
    }
    free(mergeArraryA);//清空内存。
    free(mergeArraryB);    
}

void MergeSort(int *array ,int arrayStart ,int arrayEnd)//建立归并排序函数
{
    int middle;
    
    if(arrayStart<arrayEnd)
    {
        middle=(arrayStart+arrayEnd)/2;//求数组下标中值

        MergeSort(array,arrayStart,middle);//排序左半数组（递归调用）
        MergeSort(array,middle+1,arrayEnd);//排序右半数组（递归调用）

        Merge(array,arrayStart,middle,arrayEnd);//对左半、右半数组组合


    }
}