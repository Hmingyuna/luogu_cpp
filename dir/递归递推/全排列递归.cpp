#include <iostream>  
  
using namespace std;  
int total = 0;  
//��������  
void swapArray(int &a,int &b)  
{  
    int temp;  
    temp = a;  
    a = b;  
    b = temp;  
}  
//�ݹ麯��  
void fullPermutation(int * fullArray,int start,int end,int number){  
    //����ȿ�����">=",Ҳ������">",��Ӧ��Ҳ������"=="  
    if(start>=end){  
        for(int i=0;i<number;i++){  
            cout<<fullArray[i];  
        }  
        cout<<endl;  
        total++;  
    }  
    else{  
        for(int i=start;i<=end;i++){  
            swapArray(fullArray[start],fullArray[i]);//����  
            fullPermutation(fullArray,start+1,end,number);  
            swapArray(fullArray[start],fullArray[i]);//ע��ָ�ԭ��  
        }  
    }  
}  
int main()  
{  
    int number;//ȫ���еĳ���  
    cout<<"Number:"<<endl;  
    cin>>number;  
    int * fullArray = new int[number];//��̬����ȫ���е�����  
    //��ʼ��  
    for (int i=0;i<number;i++)  
    {  
        fullArray[i] = i+1;  
    }  
    fullPermutation(fullArray,0,number-1,number);  
    cout<<"Total = "<<total;  
    return 0;  
} 
