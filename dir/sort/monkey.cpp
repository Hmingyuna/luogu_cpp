#include <iostream>
#include <stdlib.h> 
#include <string.h>
using namespace std;
int source[10],flag[10],res[10];
int sort(){
    memset(flag,1,sizeof(flag));
    int num = 10,count=0;
    while(num){
        int t =rand()%10;   //����0-9֮�����
        if(flag[t]){
            res[count++] = source[t];
            num--;
        }
    }
    for(int i=0;i<9;i++){
        if(res[i]>res[i+1]){      //ֻ���Ǵ�С��������в���
            return 0;
        } 
    }
    return 1;
}
int main(){
    int count = 0;
    for(int i=0;i<10;i++){
        cin>>source[i];
    }
    while(sort()!=1){
        count++;
    }
    cout<<"��������"<<count<<"��"<<endl;
    return 0;
}
