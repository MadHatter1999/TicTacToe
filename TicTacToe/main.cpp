#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
//Author Anthony Healy

using namespace std;
///Globle variable
//index Array[0][0]->[0][2] first vertical
//index Array[1][0]->Array[1][2] second vertical
//index Array[2][0]->Array[2][2] third line
int Array[3][3]={{0,0,0},{0,0,0},{0,0,0}};
//This class handles the board
class board{

public:
    bool checkWin(int board[3][3],int value){
        char currentPlayer;
        switch(value) {
            case 1:
                currentPlayer='X';
                break;
            case 2:
                currentPlayer='Y';
                break;

        }
        for (int i = 0; i < 3; ++i) {
            //horizontal
            if(board[i][0]==value && board[i][1]==value && board[i][2]==value){
                return true;
            }
            //vertical
            if(board[0][i]==value && board[1][i]==value && board[2][i]==value){
                return true;
            }

        }
        //diagonals
        if(board[0][0]==value && board[1][1]==value && board[2][2]==value){
            return true;
        }
        if(board[0][2]==value && board[1][1]==value && board[2][0]==value){
            return true;
        }
        else{
            return false;
        }
    }
    board(int positionArray[3][3]){
        rePaint();
    }
//Clear board gotta do
void clear(){

    }
    void ClearScreen()
    {
        cout << string( 100, '\n' );
    }
// repaint the board
void rePaint(){
    ClearScreen();
    char TrChars[3][3]={//These are getting translated
            {PositionTranslator(Array[0][0]),PositionTranslator(Array[0][1]),PositionTranslator(Array[0][2])},
            {PositionTranslator(Array[1][0]),PositionTranslator(Array[1][1]),PositionTranslator(Array[1][2])},
            {PositionTranslator(Array[2][0]),PositionTranslator(Array[2][1]),PositionTranslator(Array[2][2])}
    };
    clear();
    cout << '|'<<TrChars[0][0]<<'|'<<TrChars[0][1]<<'|'<<TrChars[0][2]<< '|'<< endl;
    cout << '|'<<TrChars[1][0]<<'|'<<TrChars[1][1]<<'|'<<TrChars[1][2]<< '|'<< endl;
    cout << '|'<<TrChars[2][0]<<'|'<<TrChars[2][1]<<'|'<<TrChars[2][2]<< '|'<< endl;
}
//this sets the board after the verification;
void setPlace(int location,int value){
        switch(location){
            //top row
            case 1:
                Array[0][0]=value;
                rePaint();
                break;
            case 2:
                Array[0][1]=value;
                rePaint();
                break;
            case 3:
                Array[0][2]=value;
                rePaint();
                break;
                //Second row
            case 4:
                Array[1][0]=value;
                rePaint();
                break;
            case 5:
                Array[1][1]=value;
                rePaint();
                break;
            case 6:
                Array[1][2]=value;
                rePaint();
                break;
                //Third row
            case 7:
                Array[2][0]=value;
                rePaint();
                break;
            case 8:
                Array[2][1]=value;
                rePaint();
                break;
            case 9:
                Array[2][2]=value;
                rePaint();
                break;
            default:
                break;
        }

    }

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
};

//player class
class player{
protected:
    //this is the player char
    int sym=1;
    //checking to see if ai
    bool isAi=false;
    //returns true if spot is not taken
    bool isNotTaken(int Array[3][3],int move){
        switch(move){
            //top row
            case 1:    //this will handle getting the content
                 if(Array[0][0]==0){
                     return true;
                 }else{
                     return false;
                 }
                break;
            case 2:
                if(Array[0][1]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            case 3:
                if(Array[0][2]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            //Second row
            case 4:
                if(Array[1][0]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            case 5:
                if(Array[1][1]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            case 6:
                if(Array[1][2]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            //Third row
            case 7:
                if(Array[2][0]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            case 8:
                if(Array[2][1]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            case 9:
                if(Array[2][2]==0){
                    return true;
                }else{
                    return false;
                }
                break;
            default:
                return false;
                break;
        }


        return true;
    }
    //returns true if number is between 1-9
    bool isCorrectIn(int index){
        if(index<10&&index>=1){
            return true;
        } else{
            return false;
        }
    }
    int inputTxtIndex(int board[3][3] ){

        int curMove=0;
        int tmpMove=0;
        string stmpMove;
        bool isWrong= true;
        cout<<"Your move select (1-9):"<<endl;
        do {
                cin>> stmpMove;
                tmpMove=stoi(stmpMove);


            //put try or catch here

            if(isCorrectIn(tmpMove)){
                //checking if taken
                if(isNotTaken(board,tmpMove)){
                    curMove=tmpMove;
                    isWrong= false;
                }
                else if(!isNotTaken(board,tmpMove) || !isCorrectIn(tmpMove)){
                    cout<<"Current spot is taken try again"<<endl;
                    continue;
                }
            else{
                cout << "Not correct input please try again"<<endl;
                continue;
            }
            }
            else{
                cout << "Not correct input please try again"<<endl;
            }
        }
        while(isWrong );
        //this lets us in put values tell its right
        return curMove;


    }
public:
    //get ai flag
    bool getIsAi(){
        return isAi;
    }
    //getters and setters
    int getPlayerSym(){
        return sym;
    }
    void setPlayerSym(int s){
        sym=s;
    }
    player(){

    }
    int yourMove(int board[3][3]){
        int move=inputTxtIndex(board);
        return move;

    }
};

//AI class extends player
 class  AI: public  player{
    int nextMove=-1;

    //this will need to see if our guess is taken
    bool isTaken(int index){
        switch (index){
            case 1:
                if(Array[0][0]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 2:
                if(Array[0][1]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 3:
                if(Array[0][2]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 4:
                if(Array[1][0]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 5:
                if(Array[1][1]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 6:
                if(Array[1][2]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 7:
                if(Array[2][0]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 8:
                if(Array[2][1]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            case 9:
                if(Array[2][2]==0){
                    return false;
                } else{
                    return true;
                }
                break;
            default:
                return true;
                break;

        }
    }

    //this will handle if theres an almost win
    int findCloseWin(int value,int board[3][3]){
        //diagnol
        //right to left
        if(board[0][2]==0 && board[1][1]==value && board[2][0]==value){
            return 3;
        }
        if(board[0][2]==value && board[1][1]==0 && board[2][0]==value){
            return 5;
        }
        if(board[0][2]==value && board[1][1]==value && board[2][0]==0){
            return 7;
        }
        //left to right
        if(board[0][0]==0 && board[1][1]==value && board[2][2]==value){
            return 1;
        }
        if(board[0][0]==value && board[1][1]==0 && board[2][2]==value){
            return 5;
        }
        if(board[0][0]==value && board[1][1]==value && board[2][2]==0){
            return 9;
        }

        else{
            for (int i = 0; i < 3; ++i) {
                //horizontal
                if(board[i][0]==0 && board[i][1]==value && board[i][2]==value){
                    return (1+(3*i));
                }
                else if(board[i][0]==value && board[i][1]==0 && board[i][2]==value){
                    return (2+(3*i));
                }
                else if(board[i][0]==value && board[i][1]==value && board[i][2]==0){
                    return (3+(3*i));
                }
            }
            for (int j = 0; j < 3; ++j) {
                //vertical ****needs work****
                if(board[0][j]==0 && board[1][j]==value && board[2][j]==value){
                    return (1+j);

                }else if(board[0][j]==value && board[1][j]==0 && board[2][j]==value){
                    return (4+j);

                }
                else if(board[0][j]==value && board[1][j]==value && board[2][j]==0){
                    return (7+j);
                }
            }
        }
        return -1;
    }
    //detect potential wins
    int findWins(int value, int board[3][3]){
    //this will loop through to find where things are
        nextMove=findCloseWin(2,board);
        if(nextMove!=-1){
            return nextMove;
        }
        else{
            return -1;
        }

    }
  bool findBlocks(int value,int board[3][3]){
        //This is the same as the win code just not our number
       nextMove= findCloseWin(value,board);
        if(nextMove==-1){
            return -1;
        }
        else{
            return nextMove;
        }
    }
    //this will take in the board and see if it was taken
    bool isTaken(int board[3][3], int row,int line){
        if(board[row][line]==0){
            return true;
        }
        else{
            return false;
        }
    }
    //strategy
    int strat(int value, int board[3][3]){
        //my magic strat
        if(isTaken(board,1,1)&&board[1][1]==1){
            if(board[0][0]){
                return 1;
            }
            else if(board[0][2]==0){
                return 3;
            }
            else if(board[2][2]==0){
                return 9;
            } else if(board[0][2]){
                return 7;
            }
            else{
                return -1;
            }
        } else if (!isTaken(board,1,1)){
             if(board[1][0]==0){
                return 4;
            }
            else if(board[0][1]==0){
                return 2;
            }
            else if(board[1][2]==0){
                return 6;
            } else if(board[1][2]==0){
                return 7;
            } else{
                return -1;
            }
        }
        else{
            return -1;
        }
    }
    //weighted
int useWeighted(int value,int board[3][3]){
        //this is used as the weighted spot options
        if(board[1][1]==0){
            return 5;
        }
        //corners
        else if(board[0][0]==0){
            return 1;
        }
        else if(board[0][2]==0){
            return 3;
        }else if(board[2][2]==0){
            return 9;
        } else if(board[0][2]==0){
            return 7;
        }

        //other slots
        else if(board[1][0]==0){
            return 4;
        }
        else if(board[0][1]==0){
            return 2;
        }
        else if(board[1][2]==0){
            return 6;
        } else if(board[1][2]==0){
            return 7;
        } else{
            return -1;
        }
    }
    //luck-give up
 int feelingLucky(int value,int board[3][3]){
        int iRand = (rand() % 9) + 1;
        switch(iRand){
            case 1:
                    if(!isTaken(1)&&board[0][0]==0){
                        return 1;
                    } else{
                         feelingLucky(value,board);
                    }
                break;
            case 2:
                if(!isTaken(2)&&board[0][1]==0){
                    return 2;
                }else{
                     feelingLucky(value,board);
                }
                break;
            case 3:
                if(!isTaken(3)&&board[0][2]==0){
                    return 3;
                }else{
                     feelingLucky(value,board);
                }
                break;
            case 4:

                if(!isTaken(4)&&board[1][0]==0){
                    return 4;
                }else{
                     feelingLucky(value,board);
                }
                break;
            case 5:
                if(!isTaken(5)&&board[1][1]==0){
                    return 5;

                }else{
                     feelingLucky(value,board);
                }
                break;
            case 6:
                if(!isTaken(6)&&board[1][2]==0){
                    return 6;
                }else{
                   feelingLucky(value,board);
                }
                break;
            case 7:
                if(!isTaken(7)&&board[2][0]==0){
                    return 7;

                }else{
                     feelingLucky(value,board);
                }
                break;
            case 8:
                if(!isTaken(8)&&board[2][1]==0){
                    return 8;

                }else{
                    feelingLucky(value,board);
                }
                break;
            case 9:
                if(!isTaken(9)&&board[2][2]==0){
                    return 9;
                } else{
                    feelingLucky(value,board);
                }

        }
    }

public:
    int getNextMove(player sec){
        //seing any potential moves
        int finalChoice=0;
        int Win=findWins(this->getPlayerSym(),Array);
        int Block=findBlocks(sec.getPlayerSym(),Array);
        int strats=strat(this->getPlayerSym(),Array);
        int weight=useWeighted(this->getPlayerSym(),Array);
        int guess=feelingLucky(this->getPlayerSym(),Array);
        if(nextMove!=-1&&Win!=-1){
            finalChoice=Win;
        }
        else if(nextMove!=-1&&Block!=-1){
            finalChoice=nextMove;
        }
        else if(strats!=-1){
            finalChoice=strats;
        }
        else if(weight!=-1){
            finalChoice=weight;
        }
        else{
         finalChoice=guess;
        }
        return finalChoice;
    }
    //default constructor
    AI(){
        //setting the Ai flag
        this->isAi=true;
    }
};
//set who goes first
bool setFirst(){
    int first;
    cout << "Welcome input 1 to go first or any other key to go second"<<endl;
    cin >>first;
    if(first !=1){
        return false;
    } else{
        return true;
    }
}
//throw win
bool throwWin(int whoWon,bool win,bool tie){
    string Msg;
    if(win==true){
        string who;
        if(whoWon==1){
            who="X ";
        } else if(whoWon==2){
            who="O ";
        }
        //print winner
        cout<<who<<"wins"<<endl;
        return true;
    }
    else if(tie){
        cout<<"Tie"<<endl;
        return true;
    }
    else {
        return false;
    }
}
//checking for ties
bool checktie(int board[3][3]){
    int count=0;
    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(board[i][j]!=0){
                count++;
            }
        }
    }
    if(count==9){
        return true;
    }
    else{
        return false;
    }
}
//game mechanics/ game rounds
void gameRound(player first, AI second){
        ///These are the players and board set up
        board game= board(Array);

        ///These are Varibles
        bool win= false;
        while(!win){
            bool isTie=checktie(Array);
                game.setPlace(first.yourMove(Array),first.getPlayerSym());
                isTie=checktie(Array);
                win=throwWin(first.getPlayerSym(),game.checkWin(Array,first.getPlayerSym()),isTie);

            //check if win
            if(win){
                continue;
            }
            game.setPlace(second.getNextMove(first),second.getPlayerSym());
            isTie=checktie(Array);
            win=throwWin(second.getPlayerSym(),game.checkWin(Array,second.getPlayerSym()),isTie);
        }
        }
void gameRound(AI first, player second){
    ///These are the players and board set up
    board game= board(Array);
    ///These are Varibles
    bool win= false;
    while(!win){
        bool isTie=checktie(Array);
        game.setPlace(first.getNextMove(second),first.getPlayerSym());
        isTie=checktie(Array);
        win=throwWin(first.getPlayerSym(),game.checkWin(Array,first.getPlayerSym()),isTie);

        //check if win
        if(win){
            continue;
        }
        game.setPlace(second.yourMove(Array),second.getPlayerSym());
        isTie=checktie(Array);
        win=throwWin(second.getPlayerSym(),game.checkWin(Array,second.getPlayerSym()),isTie);
    }
}

int main() {
    //Person player
    player usr= player();
    usr.setPlayerSym(1);
    //non person player (to be replaced by AI)
    AI Ai = AI();
    Ai.setPlayerSym(2);


    //to see who goes first
    if(setFirst()){
        //call the first user then secound Ai
        cout<<"You go  first"<<endl;
        gameRound(usr,Ai);
    } else{
       //call Ai first then usr
       cout<<"I Shall go first"<<endl;
       gameRound(Ai,usr);
    }






}
