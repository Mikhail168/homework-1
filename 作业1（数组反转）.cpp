#include<iostream>
#include<vector>

void reverseArray(int* arr,int n){//反转函数
    int start=0;int end=n-1;//原文 int end=sizeof(arr)/sizeof(arr[0])-1  
    while(start<end){//上行的arr 是函数参数，类型是 int*，它已经退化成了指针(8字节)，不再是数组
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;end--;
    }
    
}
int main(){
    int n=0;
    std::cout<<"请输入n值： \n";
    std::cin>>n;
    if(n<=0){
        std::cout<<"n为非零正整数\n";
        return 0;
    }//输入n值
    int arr[n];//初始化数组
    std::cout<<"请输入数组： \n";
    for(int k=0;k<n;k++){
        
        std::cin>>arr[k];
    }//数组数据录入

    reverseArray( arr, n);//调用反转函数
    std::cout<<"反转后数组为： \n";
    for(int k=0;k<n;k++){
        std::cout<<arr[k]<<"\t";
    }//输出结果

}