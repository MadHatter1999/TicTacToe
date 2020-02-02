//
// Created by Antho on 2019-09-11.
//

#include "board.h"
#include <iostream>

//Author Anthony Healy
//This file will deal with boards re darwing and and redarwing the board
//multidementional array
// The Board starts empty
// 0=empty 1=X 2=O
using namespace std;

class board{

//this uses the int provided to assign it to the correct value
    char PositionTranslator(int Player){
        if(Player==0){//if Zero its a space
            return ' ';
        } else if(Player==1){//if One its X
            return 'X';
        }else if(Player==2){//if Two its 0
            return 'O';
        }else{
            return 'E';//error
        }
    }
    // repaint the board
    void rePaint(int Positions[3][3]){

        char TrChars[3][3]={//These are getting translated
                {PositionTranslator(Positions[0][0]),PositionTranslator(Positions[0][1]),PositionTranslator(Positions[0][2])},
                {PositionTranslator(Positions[1][0]),PositionTranslator(Positions[1][1]),PositionTranslator(Positions[1][2])},
                {PositionTranslator(Positions[2][0]),PositionTranslator(Positions[2][1]),PositionTranslator(Positions[2][2])}
        };
        cout << '|'<<TrChars[0][0]<<'|'<<TrChars[0][1]<<'|'<<TrChars[0][2]<< '|'<< endl;
        cout << '|'<<TrChars[1][0]<<'|'<<TrChars[1][1]<<'|'<<TrChars[1][2]<< '|'<< endl;
        cout << '|'<<TrChars[2][0]<<'|'<<TrChars[2][1]<<'|'<<TrChars[2][2]<< '|'<< endl;
    }
    board(int positionArray[3][3]){
        rePaint(positionArray);
    }
};



