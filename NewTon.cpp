#include <iostream>
#include <vector>
using namespace std;
//Newton插值
double Newton(vector<double>x,vector<double>y,int n,double num,int times){
    vector<vector<double>> table(n+1);
    //初始化均差表
    for(int i=0;i<=n;i++)
        table[i].resize(n+1);
    for(int i=0;i<=n;i++)
        table[0][i]=y[i];
    //生成均差表
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            table[i][j]=(table[i-1][j]-table[i-1][j-1])/(x[j]-x[j-i]);
    //计算不同插值次数的结果

    double res=0.0;
    for(int i=0;i<=times;i++){
        double tmp=table[i][i];
        for(int j=0;j<i;j++){
            tmp*=num-x[j];
        }
        res+=tmp;
    }
    return res;
}

//拉格朗日插值
double Lagrange(vector<double>x,vector<double>y,double m,int n){
    double sum=0;//最终结果
		for(int i=0;i<=n;i++){
			double h=1;//L(x)
			for(int k=0;k<=n;k++){
				if(i==n-k){//x[i]==x[n-k]则跳出循环
					continue;
				}
				//计算L(x)
				h*=(m-x[n-k])/(x[i]-x[n-k]);
			}
			//结果累加至sum
			sum+=y[i]*h;
			
		}
    return sum;
}



int main(){
    //数组最大下标
    int n=4;
    double x[]={0,0.17,0.65,0.85,1};
	double y[]={1,0.5806,0.0865,0.0525,0.0385};
    //待计算的数据
    double num=0.9;
    //插值次数
    int times=4;
    
    //Newton Lagrange 1~4次插值
    for(int i=1;i<times+1;i++){
        //从第五个元素开始向前取值
        vector<double>x1(x+4-i,x+5);
        vector<double>y1(y+4-i,y+5);

        double res1=Lagrange(x1,y1,num,x1.size()-1);
        cout<<"Lagrange "<<i<<" times:"<<res1<<endl;
        double res=Newton(x1,y1,x1.size()-1,num,i);
        cout<<"Newton "<<i<<" times:"<<res<<endl;
        cout<<"=========================="<<endl;
    } 
   
    return 0;
}