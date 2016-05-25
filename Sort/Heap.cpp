//
//  main.cpp
//  fee
//
//  Created by 王叙鹏 on 16/5/24.
//  Copyright (c) 2016年 王叙鹏. All rights reserved.
//

#include <iostream>
using namespace std;
int max(int a[],int n,int s,int e){//判断该节点是否需要和子节点调换位置
    int r=0;
    int max=0;
    if(n*2+1>e){
        if(a[2*n]<=a[n])
            r=0;//不用调整
        else if(a[2*n]>a[n])
            r=1;
    }//只有左子
    else {
        if(a[2*n]>=a[2*n+1]){
            max=a[2*n];
            r=1;
        }
        else if(a[2*n]<a[2*n+1]){
            max=a[2*n+1];
            r=2;
        }//求出两子较大的
        if(a[n]>=max){
            r=0;
        }//不需要调整
    }
    return r;
}
void Heapify(int a[],int n,int s,int e){//只有根不满足堆，局部调整
    int change=0;//若父大为0，不用调，若子大，与左子交换为1，右子交换为2；
    int temp=0;
    if(n*2<=e){
        change=max(a,n,s,e);
        if(change==1){
            temp=a[n];
            a[n]=a[2*n];
            a[2*n]=temp;
            Heapify(a,2*n,s,e);
        }
        else if(change==2){
            temp=a[n];
            a[n]=a[2*n+1];
            a[2*n+1]=temp;
            Heapify(a,2*n+1,s,e);
        }
    }
}
void Buildheap(int a[],int s,int e){//将初始的无序调整成堆，全面调整
    int startnode=e/3+1;//最开始调整的节点
    for(int i=startnode;i>=1;i--){
        Heapify(a,i,s,e);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[16];
    int i=1;
    int start,end;
    while(cin>>a[i]){
        if(a[i]<0){
            start=1;
            end=i-1;
            break;
        }
        i++;
    }//输入数组
    Buildheap(a,start,end);//进行一次全面调整
    for(int t=end;t>start;t--){
        a[0]=a[t];
        a[t]=a[start];
        a[start]=a[0];//交换排好堆的根节点与最后一个节点
        Heapify(a,start,start,t-1);//局部调整
    }
    for(int z=start;z<=end;z++){
        cout<<a[z]<<"   ";
    }

    return 0;
}
