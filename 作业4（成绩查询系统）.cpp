#include <cstddef>
#include<iostream>

void initScores(int* scores,int n){
    for(int i=0;i<n;i++){
        scores[i]={};
    }
}//初始化成绩数组

void inputScores(int* scores,int n){
    std::cout<<"请依次录入成绩： \n";
    for(int i=0;i<n;i++){
        std::cin>>scores[i];
    }
}//录入成绩至成绩数组

double calcAverage(const int* scores,int n){
    double sum =0.0;double result=0.0;
    for(int i=0;i<n;i++){
        if(scores[i]<0||scores[i]>100){
            return -1.0;
        }//如果成绩数组中出现任何一个数据非法，则对外返回数值-1.0（错误代码）
        else{
           sum +=scores[i];
        }
        
    } 
    result =sum/n;
    return result;
}//计算平均值

int safeGet(const int* scores,int n,int index){
    if(index<=0){
        return -1;
    }
    if(scores[index]==0){
        return -1;
    }
    if(scores[index]<0||scores[index]>100){
        return -1;
    }//当序列号非法、无成绩数据或成绩数据在范围以外时返回错误代码-1
    else{
       return scores[index-1];
    }
    
}//安全查询

void countGrades(const int*scores,int n,int* counts){
    
    for(int i=0;i<n;i++){
        int a=scores[i];
        if(a<0||a>100){
            continue;
        }
        else if(a<50){
           counts[4]++;
        }
        else if(a<60){
            counts[3]++;
        }
        else if(a<70){
            counts[2]++;
        }
        else if(a<90){
            counts[1]++;
        }
        else if(a<=100){
            counts[0]++;
        }
    }    
}//统计各分数段人数

void findMinMax(const int* scores,int n, int& max,int& min){
    for(int i=0;i<n;i++){
        if(scores[i]>max){
            max=scores[i]; 
        }
        if(scores[i]<min){
            min=scores[i];          
        }

    }
}//取成绩最大/小值

void printResults(const int* scores,int n,double avg,const int* counts,int max,int min){
    std::cout<<"以下为成绩的完全统计\n";
    for(int i=1;i<=n;i++){
        std::cout<<i<<"\t";
    }std::cout<<"\n";
    for(int i=0;i<n;i++){
        std::cout<<scores[i]<<"\t";
    }std::cout<<"\n";
    
    
    std::cout<<"90至100为A等；70至89为B等；60至69为C等；50至59为D等；0至49为E等。以下为人数统计\n";
    std::cout<<"A\tB\tC\tD\tE"<<std::endl;
    for(int i=0;i<5;i++){
        std::cout<<counts[i]<<"\t";
    }
    std::cout<<"\n";

    if(avg==-1.0){
        std::cout<<"平均分：--\n";
    }
    else{
        std::cout<<"平均分："<<avg<<std::endl;
    }//进行平均分合法性判断（若函数返回数值-1.0则用“--”符号隐藏平均分显示）

    

    if(max>100||max<=0){
        std::cout<<"最高分：--\n";  
    }
    else {
        std::cout<<"最高分："<<max<<std::endl;
    }
    if(min<0||min>=100){
       std::cout<<"最低分：--\n";
    }
    else{
       std::cout<<"最低分："<<min<<std::endl;
    }//进行最大/小值合法性判断，若最大/小值非法，处理办法同平均值
    
}//打印结果

int main(){
    int n=0;
    std::cout<<"请输入人数"<<std::endl;
    std::cin>>n;
    int scores[n];
    int counts[5]={0,0,0,0,0};
    int max=0;int min=100;
    double avg=0.0;
    int index;//设置参数

    initScores(scores, n);

    inputScores(scores, n);

    avg=calcAverage(scores,n);

    findMinMax(scores,n,max,min);


    countGrades(scores,n,counts);//调用函数功能

    std::cout<<"请输入要查询的序列号： \n";
    std::cin>>index;
    int queried=safeGet(scores,n,index);
    if(queried == -1){
        std::cout<<"查询失败\n";
    }
    else{
        std::cout<<"序列号"<<index<<" 的成绩是： "<<queried<<std::endl;
    }//安全查询测试

    printResults(scores, n,avg,counts,max,min);//打印最终结果

    return 0;
     

}