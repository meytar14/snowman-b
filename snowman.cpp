#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <array>
#include <exception>

#include "snowman.hpp"
using namespace std;
namespace ariel{
    array<string,4> hat={" _===_\n","  ___\n .....\n","   _\n  /_\\\n", "  ___\n (_*_)\n"};
    array<string,4> nose={",",".","_", " "};
    array<string,4> leftEye ={".","o","O","-"};
    array<string,4> rightEye ={".","o","O","-"};
    array<string,4> leftArm ={"<","\\","/"," "};
    array<string,4> rightArm ={">","/","\\"," "};
    array<string,4> torso={"( : )","(] [)","(> <)","(   )"};
    array<string,4> base={"( : )","(\" \")","(___)","(   )"};


    string snowman(int x)
    {
        int temp=x;
        
        const int ten=10;
        const int hundred=100;
        const int thousend=1000;
        

        //check if the input is valid
        const int eight=8;
        const int four=4;
        for(int i=0;i<eight;i++)
        {
            if(temp%ten>four||temp%ten<1)
            {
                throw invalid_argument("invalid input");
            }
            temp=temp/ten;
        }
        if(temp!=0)
        {
            throw invalid_argument("invalid input");
        }


        
       
        bool isRightArmUp=false;
        bool isLeftArmUp=false;
        if((x/hundred)%ten==2)
        {
            isRightArmUp=true;
        }
         if((x/(thousend))%ten==2)
        {
            isLeftArmUp=true;
        }

        
        //build the snowman
        string s;
        s=s+hat.at((x/(ten*thousend*thousend))-1);
        if(isLeftArmUp)
        {
            s=s+leftArm.at(1);
        }
        else{
            s=s+" ";
        }
        s=s+"("+leftEye.at(((x/(hundred*thousend))%ten)-1);
        s=s+nose.at(((x/(thousend*thousend))%ten)-1);
        s=s+rightEye.at(((x/(ten*thousend))%ten)-1)+")";
        if(isRightArmUp)
        {
            s=s+rightArm.at(1)+"\n";
        }
        else{
            s=s+"\n";
        }
        if(!isLeftArmUp)
        {
            s=s+leftArm.at(((x/(thousend))%ten)-1);
        }
        else{// add " "before the torso
            s=s+" ";
        }
        s=s+torso.at(((x/ten)%ten)-1);
        if(!isRightArmUp)
        {
            s=s+rightArm.at(((x/hundred)%ten)-1)+"\n";
        }
        else
        {
            s=s+"\n";
        }
        s=s+" "+base.at((x%ten)-1);
        return s;
    }
}

// int main(int argc, char const *argv[])
// {
//     ariel::snowman(11111111);
//     return 0;
// }

