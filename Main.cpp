#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include "snowman.hpp"
#include <cstdlib> 
#include <ctime> 
using namespace std;
using namespace ariel;
string tree()
{
    string s="   /\\\n  /  \\\n /    \\\n  |  |\n  |  |";
    return s;
}
int generateNumber()
{
    
    int x=0;
    int r;
    for(int i=0;i<8;i++)
    {
        r=rand()%4+1;
        x=x*10+r;
    }
    return x;
}
int main(int argc, char const *argv[])
{
    srand (time(NULL));
    cout<<snowman(generateNumber())+"\n\n"<<endl;
    cout<<tree()+"\n"<<endl;
    cout<<snowman(generateNumber())+"\n\n"<<endl;
    cout<<tree()+"\n"<<endl;
    cout<<snowman(generateNumber())+"\n\n"<<endl;
    return 0;
}
