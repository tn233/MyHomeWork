#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huf{
    int num;
    char *word;
    struct huf *Lchild;
    struct huf *Rchild;
}huffman;

typedef struct d{
    huffman *pointer;
}data;

int *min(int rate[],int len);
int huffman_create(data *bucket,char *word[],int rate[],int len);
int huffman_node_init(huffman *res,char *word,int number);

int main(){
    char *word[] = {"一","蓑","烟","雨","任","平","生"};
    int rate[7] = {60,45,13,69,14,5,3};
    int len = (sizeof(rate)/sizeof(int));
    //500个用于储存Huffman类型指针的数组，用作临时储存（需要根据你的压缩长度进行调整）
    data *bucket = (data*)malloc(sizeof(data*) * 500 + 1);
    //huffman *tree = (huffman*)malloc(sizeof(huffman));
    huffman_create(bucket,word,rate,len);

}

int huffman_create(data *bucket,char *word[],int rate[],int len){

    int i = 0;
    huffman *parent = NULL;
    int pre[2] = {-1,-1};
    for(;i < len - 1;i++){
        //取当前arr的最小两个数(下标)
        int *m = min(rate,len);
        int min = m[0],min2 = m[1];//m[0]最小值下标,m[1]次小值下标
        if(min == pre[0] && min2 == pre[1]){
            break;
        }
        printf("%d,%d\n",min,min2);

        if(bucket[rate[min]].pointer != NULL && bucket[rate[min]].pointer->num == rate[min]){//如果最小值是前父树（新二叉树左侧）
            //左侧是老父树，右侧空
            bucket[rate[min2]].pointer = (huffman*)malloc(sizeof(huffman) + 1);
            huffman_node_init(bucket[rate[min2]].pointer,word[min2],rate[min2]);//right

            //他俩的父节点的num属性就是他俩的频率和
            int parent_num = rate[min]+rate[min2];
            bucket[parent_num].pointer = (huffman*)malloc(sizeof(huffman) + 1);
            huffman_node_init(bucket[parent_num].pointer,NULL,parent_num);

            //左右节点分配
            bucket[parent_num].pointer->Lchild = bucket[rate[min]].pointer;
            bucket[parent_num].pointer->Rchild = bucket[rate[min2]].pointer;

            parent = bucket[parent_num].pointer;

            //频率和计算后，合并这两个最小频率
            rate[min] = rate[min] + rate[min2];
            rate[min2] = -1;
        }else if(bucket[rate[min]].pointer != NULL && bucket[rate[min2]].pointer->num == rate[min2]){//如果次小值是前父树（新二叉树右侧）
            //右侧是老父树，左侧空
            bucket[rate[min]].pointer = (huffman*)malloc(sizeof(huffman) + 1);
            
            huffman_node_init(bucket[rate[min]].pointer,word[min],rate[min]);//left
            //他俩的父节点的num属性就是他俩的频率和
            int parent_num = rate[min]+rate[min2];
            bucket[parent_num].pointer = (huffman*)malloc(sizeof(huffman) + 1);
            huffman_node_init(bucket[parent_num].pointer,NULL,parent_num);
            //左右节点分配
            bucket[parent_num].pointer->Lchild = bucket[rate[min]].pointer;
            bucket[parent_num].pointer->Rchild = bucket[rate[min2]].pointer;

            parent = bucket[parent_num].pointer;

            //频率和计算后，合并这两个最小频率
            rate[min] = rate[min] + rate[min2];
            rate[min2] = -1;
        }else{
            //根据这两个最小频率构建二叉树
            bucket[rate[min]].pointer = (huffman*)malloc(sizeof(huffman) + 1);//left
            huffman_node_init(bucket[rate[min]].pointer,word[min],rate[min]);//left

            bucket[rate[min2]].pointer = (huffman*)malloc(sizeof(huffman) + 1);//right
            huffman_node_init(bucket[rate[min2]].pointer,word[min2],rate[min2]);//right

            //他俩的父节点的num属性就是他俩的频率和
            int parent_num = rate[min]+rate[min2];
            bucket[parent_num].pointer = (huffman*)malloc(sizeof(huffman) + 1);//parent
            huffman_node_init(bucket[parent_num].pointer,NULL,parent_num);

            bucket[parent_num].pointer->Lchild = bucket[rate[min]].pointer;
            bucket[parent_num].pointer->Rchild = bucket[rate[min2]].pointer;

            parent = bucket[parent_num].pointer;

            //频率和计算后，合并这两个最小频率
            rate[min] = rate[min] + rate[min2];
            rate[min2] = -1;
            
        }
        pre[0] = min;
        pre[1] = min2;
    }

    printf("tmp");
    return 0;
}

int huffman_node_init(huffman *res,char *word,int number){
    //huffman *res = (huffman*)malloc(sizeof(huffman) + 1);
    res->num = number;
    res->word = word;
    res->Lchild = NULL;
    res->Rchild = NULL;
    return 0;
}

int huffman_output(){

}

//函数内行参和外部的实参是没有瓜葛的，但是指针除外
//一般指针传递行参得到的都是指针地址，意味着可以直接通过行参对行参进行修改
//数组就是特殊的指针
int *min(int rate[],int len){
    int i = 0,min_tmp = 9999999,min = 0,min2 = 0;
    //最小值
    for(;i < len;i++){
        if(rate[i] == -1){
            continue;
        }
        if(rate[i] < min_tmp){
            min = i;
            min_tmp = rate[i];
        }
    }

    //次小值
    min_tmp = 9999999;
    i = 0;
    for(;i < len;i++){
        if(rate[i] == -1 || i == min){
            continue;
        }
        if(rate[i] < min_tmp){
            min2 = i;
            min_tmp = rate[i];
        }
    }
    int *res = (int*)malloc(sizeof(int*) * 3);
    res[0] = min;
    res[1] = min2;
    return res;
}