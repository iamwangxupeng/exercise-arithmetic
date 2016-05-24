//
//  main.cpp
//  Sort
//
//  Created by 王叙鹏 on 16/5/24.
//  Copyright (c) 2016年 王叙鹏. All rights reserved.
//

#include <iostream>
using namespace std;
int split(int a[],int i,int j){//一次排列算法，算法核心
    int pivot=a[i];
    while(i<j){
        while(i<j&&pivot<=a[j]){//若已排好序则会越界，例如越界到0
            j--;
        }
        if(i<j)//防止“若已是排序好的，则i会越界加”
            a[i++]=a[j];
        while(i<j&&pivot>=a[i]){
            i++;
        }
        if(i<j)//同理
            a[j--]=a[i];
    }
    a[i]=pivot;//把标准值放入中间位置
    return i;
    
}
void QuickSort(int a[],int s,int e){//排序算法框架
    if(s<e){
        int pivotpos=split(a,s,e);
        QuickSort(a,s, pivotpos-1);
        QuickSort(a,pivotpos+1,e);
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
    QuickSort(a,start,end);
    for(int z=start;z<=end;z++){
        cout<<a[z]<<"   ";
    }
    return 0;
    
}

