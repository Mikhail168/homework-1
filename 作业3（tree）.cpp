#include<iostream>
/*此程序由于存在问题无法完整运行*/
void buildTestTree(int* tree,int n){
    for(int i=0;i<n;i++){
        for(int k=0;;k++){

        }
    }//这里原本期望打印出一个由遍历后的数组组成的树，但由于寻找规律发现该树每一行元素数量呈2^i（i=0,i++）规律分布。很难找到合适的方法在双循环逻辑中进行次方运算，故只保留逻辑在此
    
}//构建树

void preorderTraversal(const int* tree,int n,int i){
    if(i>=n||tree[i]==-1){
        return;
    }
    std::cout<<tree[i]<<" ";
    preorderTraversal(tree,n,2*i+1);
    preorderTraversal(tree,n,2*i+2);
}//前序遍历


int main(){
   int n=0;
   int i=0;
   std::cout<<"请输入n值\n";
   std::cin>>n;
   int tree[n];
   
   std::cout<<"请输入数组\n";
   for(int i=0;i<n;i++){
    std::cin>>tree[i];
   }

   preorderTraversal(tree,n,i);
   //std::cout<<"\n";
   //std::cout<<sizeof(tree)<<std::endl;
}