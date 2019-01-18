#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
//帧定界符
#define flag "01111110"
//首部无用字符
#define none "1111111100000011"
//首部协议
#define agreement "0000000000100001"
//CRC-16的除数为11000000000000101
#define CRC_16 "11000000000000101"

//随机生成50字节IP数据报，共400位
string IPData()
{
 //更新随机数种子，保证每次的随机数不同
 srand((unsigned)time(NULL));
 string data="";
 char perData=' ';
 for(int i=1;i<=400;i++)
 {
  perData=rand()%(1-0+1)+0+48;
  data=data+perData;
 }
 return data;
}
//零比特填充法
string zeroBitFill(string data)
{
	//从0开始查找第一个“11111”的位置
	int index=data.find("11111",0);
	//如果能够查找到
	while(index!= data.npos)
	{
		//在“11111”的后面加0
		string midstr1=data.substr(0,index+5);
		string midstr2=data.substr(index+5);
		data=midstr1+"0"+midstr2;
		//查找下一个“11111”
		index=data.find("11111",index+5);
	}
	return data;
}
//字符填充
string stringFill(string data)
{
    //从0开始查找第一个“01111110”的位置
	int index=data.find("01111110",0);
	//如果能够查找到
	while(index!= data.npos)
	{
		//将“01111110”(7E)的转换为"01111011 01011110"(7D 5E)
		string midstr1=data.substr(0,index);
		string midstr2=data.substr(index+8);
		data=midstr1+"0111110101011110"+midstr2;
		//查找下一个“01111110”
		index=data.find("01111110",index+16);
	}
	return data;
}
//模2加减
char mod2_add_sub(char a,char b)
{
	//相当于异或
 if((a=='0' &&b=='0')||(a=='1' &&b=='1'))
 {
  return '0';
 }
 else
 {
  return '1';
 }
}

//模2除法
string mod2_division(string a,string b)
{
	for(int i=0;i<b.length()-1;i++)
	{
	 a=a+"0";
	}
	//长度
	int alength=a.length();
	int blength=b.length();
    //运算次数
	int n=alength-blength+1;

	string shang=b;
	//除法运算
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<blength;k++)
		{
			 a[k]=mod2_add_sub(a[k],shang[k]);
		}
		a=a.substr(1);
		if(a[0]=='0')
		{
			shang="";
			for(int j=0;j<blength;j++)
			{
				shang=shang+"0";
			}
		}
		else
		{
			shang=b;
		}
	}
	return a;
}
//根据CRC冗余校验生成FCS
string FCS_CRC(string data)
{
	string fcs="";
	fcs=mod2_division(data,CRC_16);
	return fcs;
}

//生成PDU,参数n说明，n=1时零比特填充，n=2时字符填充
string PDU(string ipData,int n)
{
 string pdu="";
 //首部
 pdu=flag;
 pdu=pdu+none;
 pdu=pdu+agreement;
 //ip数据报
 //时零比特填充
 if(n==1)
 {
  pdu=pdu+zeroBitFill(ipData);
 }
 //字符填充
 else if(n==2)
 {
  pdu=pdu+stringFill(ipData);
 }
 //尾部
 //FCS
 pdu=pdu+FCS_CRC(ipData);
 //帧定界
 pdu=pdu+flag;
 return pdu;
}

int main()
{
 cout<<"生成的IP数据报为："<<endl;
 string data=IPData();
 cout<<data<<endl;
 cout<<endl;
 cout<<"处理后的pdu帧(0比特填充)为："<<endl;
 cout<<PDU(data,1)<<endl;
 cout<<"处理后的pdu帧(字符填充)为："<<endl;
 cout<<PDU(data,2)<<endl;
 system("pause");
 return 0;
}
