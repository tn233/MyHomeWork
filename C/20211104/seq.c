#include <stdio.h>
//BST，基于数组

typedef struct a{
    int id;
} info;

info seq_tree[100];
int len = 1;

int create_node(info seq_tree[],int id);
int find(info seq_tree[],int id);
int ForeachForward(info seq_tree[]);
int Zforeach(info seq_tree[]);

int main(){
    create_node(seq_tree,16);
    create_node(seq_tree,12);
    create_node(seq_tree,24);
    create_node(seq_tree,15);
    create_node(seq_tree,24);
    create_node(seq_tree,18);
    create_node(seq_tree,10);

    ForeachForward(seq_tree);
    Zforeach(seq_tree);
}

int create_node(info seq_tree[],int id){//添加节点
    int now = 1;//记录当前所指下标，1对应根节点
    
    if(seq_tree[1].id == 0){//没有根节点
        info r;
        r.id = id;
        seq_tree[1] = r;
        return 0;
    }

    int index = find(seq_tree,id);
    info a;
    a.id = id;
    seq_tree[index] = a;

    if(index > len){
        len = index;
        printf("len:%d\n",len);
    }
    
}

int find(info seq_tree[],int id){
    int now = 1;//记录当前所指下标，1对应根节点
    while(seq_tree[now].id != 0){
        int left = now * 2;//左子树
        int right = now * 2 + 1;//右子树
        if(id >= seq_tree[now].id){
            now = right;
        }else{
            now = left;
        }
    }
    return now;
}

int ForeachForward(info seq_tree[]){//前序遍历
    int now = 1;//记录当前所指下标，1对应根节点
    while(now <= len){
        printf("%d->",seq_tree[now].id);

        if(now == len){//防止死循环
            break;
        }

        int left = now * 2;//左子树
        int right = left + 1;//右子树

        if(seq_tree[left].id != 0 || seq_tree[right].id != 0){//下面还有子节点
            if(seq_tree[left].id != 0){
                now = left;
            }else{
                now = right;
            }
        }else{//下面没子节点，回溯或遍历右边
            if(now % 2 == 1){//当前为右叶子节点
                now = (int)(now/2) + 1;//回溯到右边的上一层节点
            }else{//左叶子节点
                now++;//兄弟右节点
            }
        }
    }
}

int Zforeach(info seq_tree[]){//中序遍历
    int now = len;//数组长度
}