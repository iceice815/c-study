//proc/hardware文件中获取tring kirin970
//传入给xml解析器，获取禁止的powerHint的数组。    
//string name[5]={″Zhang″,″Li″,″Fun″,″Wang″,″Tan″};
#include <fstream>
#include <iostream>
using namespace std;
 
// main() 是程序开始执行的地方
 
int main()
{
   //cout << "Hello World"<< endl; // 输出 Hello World
   //string forbid[3] = {"VSYNC", "VRMODE","INTERACTION"};
//    for ( int i = 0; i < 10; i++ ){
// 	   if (forbid[i]=="VSYNC"){
// 		   cout << "yes" << endl;
// 		   break;
// 	   }
// 	   cout << "no" << endl;
//    }
//    return 0;
	string chip;
	fstream infile;
	infile.open("/Users/iceice/Desktop/iceice/c++/hardware");
	
	//cout << "Reading from the file" << endl; 
    infile >> chip;
	// 在屏幕上写入数据
    cout << chip << endl;
	// 再次从文件读取数据，并显示它
	infile >> chip; 
    cout << chip << endl; 
	// 关闭打开的文件
    infile.close();
}