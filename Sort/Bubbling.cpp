//
//  main.cpp
//  SORT
//
//  Created by 王叙鹏 on 16/5/24.
//  Copyright (c) 2016年 王叙鹏. All rights reserved.
//

#include <iostream>
using namespace std;
void Bubbling(int a[],int s,int e){
    int change=0;
    for(int i=s;i<=e;i++){
        change=0;
        for(int j=e;j>=i+1;j--){
            if(a[j]<a[j-1]){
                change=1;
                a[0]=a[j];
                a[j]=a[j-1];
                a[j-1]=a[0];
            }
        }
        if(change==0){
            break;
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
    Bubbling(a,start,end);
    for(int z=start;z<=end;z++){
        cout<<a[z]<<"   ";
    }
    return 0;
}
