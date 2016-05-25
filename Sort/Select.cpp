//
//  main.cpp
//  fee
//
//  Created by 王叙鹏 on 16/5/24.
//  Copyright (c) 2016年 王叙鹏. All rights reserved.
//

#include <iostream>
using namespace std;
void Select(int a[],int s,int e){//直接选择排序，初始的排序选择算法
    int min=999999;
    int pos=0;
    for(int i=s;i<e;i++){
        min=999999;
        for(int j=i;j<=e;j++){
            if(a[j]<min){
                min=a[j];
                pos=j;
            }
        }
        a[0]=a[pos];
        a[pos]=a[i];
        a[i]=a[0];
        
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
    Select(a,start,end);
    for(int z=start;z<=end;z++){
        cout<<a[z]<<"   ";
    }

    return 0;
}
