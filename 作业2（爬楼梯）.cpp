#include<iostream>

long long climbStairsIter(int n){//迭代
    long long  step1=1;long long step2=2;
    if(n<=1){
        return n;
    }
    if(n==2){
        return 2;
    }//对0,1,2三种特殊情况进行讨论
    for(long long  i=3;i<=n;i++){
        long long nextstep=0;
        nextstep=step1+step2;
       step1=step2;
       step2=nextstep;
       

    }
    return step2;

}

long long climbStairsRecur(int n){//递归
    if(n<=1){
        return n;
    }
    if(n==2){
        return 2;
    }//对0,1,2三种情况进行讨论
    return climbStairsRecur(n-1)+climbStairsRecur(n-2);
}

int main(){
    int n=0;
    std::cout<<"请输入n值： \n";
    std::cin>>n;//输入n值

    long long method1=climbStairsIter(n);
    std::cout<<method1<<std::endl;

    long long method2=climbStairsRecur(n);
    std::cout<<method2<<std::endl;//调用及输出
}