//
//  main.cpp
//  fee
//
//  Created by 王叙鹏 on 16/5/24.
//  Copyright (c) 2016年 王叙鹏. All rights reserved.
//

#include <iostream>
using namespace std;
void ShellSort(int a[],int s,int e,int d){//直接插入的改进算法，
    int j=0;
    for(int i=1+d;i<=e;i++){//循环增量不是d，因为每个数都要进行插入排序
        if(a[i]<a[i-d]){
            j=i-d;
            a[0]=a[i];//a[0]可做暂时储存用，也可做防止搜寻插入位置越界。
            while(a[j]>a[0]&&j>0){
                a[j+d]=a[j];
                j-=d;
            }
            a[j+d]=a[0];
        }
    }
}
void Shell(int a[],int s,int e){
    int increase=5;
    while(increase>1){
        increase=increase/3+1;
        ShellSort(a,s,e,increase);//上句和这句语序不能交换，这样才可以取到1，若increase取1则会陷入死循环
    }
}
int main(int argc, const char * argv[]) {
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
    Shell(a,start,end);
    for(int z=start;z<=end;z++){
        cout<<a[z]<<"   ";
    }

    return 0;
}
