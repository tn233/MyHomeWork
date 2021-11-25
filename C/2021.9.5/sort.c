#include <stdio.h>
#include <string.h>
void sortA(int start,int end,int *pointer);
void sort(int *pointer,int size);//declear

int main(){
    int arr[] = {21,46,25,16,8,7,10,48,50,100};
    //前小后大排序（尝试用快排算法）
    int *pointer = arr;
    sortA(0,9,pointer);//sizeof(arr)不可用，待解决
    printf(pointer);
}

void sortA(int start,int end,int *pointer){
    if(start >= end){//如果开始下标大于等于结束下标（也就是说“从后向前查找”和“从前向后查找”碰到甚至相交）则结束排序
        return;
    }
    int key = *pointer;//关键数据(这里代表的就是arr[0])
    int j = end;//从后向前
    int i = start;//从前向后
    while(i < j){//他俩不相碰的时候继续执行
        while(i < j && key <= *(pointer + j)){//从后向前查找，如果没有比key值小的就继续向前查找
            j--;
        }
        //交换算法（如果找到了比key值小的就进行交换，也就是把当前值排到key值的前面）
        int swagA = *(pointer + j);
        *(pointer + j) = *(pointer + i);
        *(pointer + i) = swagA;
        //交换算法-end
        
        while(i < j && key >= *(pointer + i)){//从前向后查找，如果没有比key值大的就继续向后查找
            i++;
        }
        //交换算法（如果找到了比key值大的就进行交换，也就是把当前值排到key值的后面）
        int swagB = *(pointer + j);
        *(pointer + j) = *(pointer + i);
        *(pointer + i) = swagB;
        //交换算法-end
    }
    //快排算法本质是一种分治思想，这里就是分开了临界值（i=j）然后各自再排序
    sortA(start,i-1,pointer);
    sortA(i+1,end-1,pointer);
}

/**
void sort(int *pointer,int size){
    sortA(0,size - 1,pointer);
    sortA(0,size - 1,pointer);
    int key = *pointer;//关键数据([0])
    int j = size - 1;//从后向前
    int i = 0;//从前向后
    while(1){
        while(1){
            j--;
            if(*(pointer + j) < key){
                //交换算法
                int swag = *(pointer + j);
                *(pointer + j) = *(pointer + i);
                *(pointer + i) = swag;
                //交换算法-end
                break;
            }
        }
        while(1){
            i++;
            if(*(pointer + i) > key){
                //交换算法
                int swag = *(pointer + j);
                *(pointer + j) = *(pointer + i);
                *(pointer + i) = swag;
                //交换算法-end
                break;  
            }
        }

        printf(pointer);

        if(i == j){
            break;
        }
    }
}
**/

/**
void sort(int *pointer){
    int size = sizeof(pointer);
    int i = 0;
    int loop = size * (size - 1);
    for(;i<loop;i++){
        if((pointer+i)>(pointer+i+1)){//前一个大于后一个
            int tmp = *(pointer+i);
            *(pointer+i) = *(pointer+i+1);

        }else if((pointer+i)<(pointer+i+1)){//前一个小于后一个

        }else{//等于直接continue
            continue;
        }
        //相当于pointer[i]
    }
}
**/