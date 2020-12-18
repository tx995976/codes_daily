#include <fstream>
#include <iostream>
using namespace std;

int main()
{   
    char txt[100];
    ifstream infile;
    infile.open("1.txt");

    if(!infile.is_open())
    {
        cout<<"txt文件打开失败"<<endl;
        exit(0);
    }

    while(!infile.eof())
    {       
        infile.getline(txt,100);
        cout<<txt<<endl;
    }

    infile.close();
    getchar();
}