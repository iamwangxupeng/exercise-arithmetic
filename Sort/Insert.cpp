//
//  main.cpp
//  fee
//
//  Created by 王叙鹏 on 16/5/24.
//  Copyright (c) 2016年 王叙鹏. All rights reserved.
//

#include <iostream>
using namespace std;
void Insert(int a[],int s,int e){
    int j=0;
    for(int i=2;i<=e;i++){
        if(a[i]<a[i-1]){
            j=i-1;
            a[0]=a[i];//a[0]可做暂时储存用，也可做防止搜寻插入位置越界。
            while(a[j]>a[0]){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=a[0];
        }
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
    Insert(a,start,end);
    for(int z=start;z<=end;z++){
        cout<<a[z]<<"   ";
    }

    return 0;
}
