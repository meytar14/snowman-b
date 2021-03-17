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
    const int ten=10;
    const int hundred=100;
    const int thousend=1000;
    const int two=2;

    int checkRightHandUp(int x)
    {
        if((x/hundred)%ten==two)
        {
            return 1;
        }
        return 0;
    }
    int checkLeftHandUp(int x)
    {
        if((x/(thousend))%ten==two)
        {
           return 1;
        }
        return 0;
    }
    void checkValidInput(int x)
    {
        int temp=x;
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
    }
    string Hat(int x)
    {
       return hat.at((x/(ten*thousend*thousend))-1);
    }
    string head(int x,int isLeftArmUp,int isRightArmUp )
    {
        string s;
        if(isLeftArmUp!=0)
        {
            s=s+leftArm.at(1);
        }
        else{
            s=s+" ";
        }
        s=s+"("+leftEye.at(((x/(hundred*thousend))%ten)-1);
        s=s+nose.at(((x/(thousend*thousend))%ten)-1);
        s=s+rightEye.at(((x/(ten*thousend))%ten)-1)+")";
        if(isRightArmUp!=0)
        {
            s=s+rightArm.at(1)+"\n";
        }
        else{
            s=s+"\n";
        }
        return s;
    }
    string body(int x,int isLeftArmUp,int isRightArmUp)
    {
        string s;
        if(isLeftArmUp==0)
        {
            s=s+leftArm.at(((x/(thousend))%ten)-1);
        }
        else{// add " "before the torso
            s=s+" ";
        }
        s=s+torso.at(((x/ten)%ten)-1);
        if(isRightArmUp==0)
        {
            s=s+rightArm.at(((x/hundred)%ten)-1)+"\n";
        }
        else
        {
            s=s+"\n";
        }
        return s;
    }
    string Base(int x)
    {
        string s=" "+base.at((x%ten)-1);
        return s;
    }


    string snowman(int x)
    {
        //check if the input is valid
        checkValidInput(x);
        int isRightArmUp=checkRightHandUp(x);
        int isLeftArmUp=checkLeftHandUp(x);
        
        //build the snowman
        string s=Hat(x)+head(x, isLeftArmUp, isRightArmUp)+body(x, isLeftArmUp, isRightArmUp)+Base(x);
        return s;
    }
}

