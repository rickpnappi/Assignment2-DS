/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int X=1,O=-1,EMPTY=0;
int board[3][3];
int displayboard[3][3];
int currentPlayer;
void clearBoard() {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
        board[i][j]=EMPTY;
        currentPlayer = X;
}
void putMark(int i,int j){
    if(board[i][j]==EMPTY){
    board[i][j]=currentPlayer;
    currentPlayer=-currentPlayer;
}

    else{
        cout<<"ERROR! Space Already Taken! Choose Another Space."<<endl;
    }
}
bool isWin(int mark){
    int win = 3*mark;
    return ((board[0][0] + board[0][1] + board[0][2] == win)// row 0
 || (board[1][0] + board[1][1] + board[1][2] == win) // row 1
 || (board[2][0] + board[2][1] + board[2][2] == win) // row 2
 || (board[0][0] + board[1][0] + board[2][0] == win) // column 0
 || (board[0][1] + board[1][1] + board[2][1] == win) // column 1
 || (board[0][2] + board[1][2] + board[2][2] == win) // column 2
 || (board[0][0] + board[1][1] + board[2][2] == win) // diagonal
 || (board[2][0] + board[1][1] + board[0][2] == win)); 
}
int getWinner(){
    if (isWin(X)) return X;
    else if (isWin(O)) return O;
    else return EMPTY;
}
void printBoard(){
    
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            switch (board[i][j]){
                
                case X:     cout<<"X";break;
                case O:     cout<<"O";break;
                case EMPTY: cout<<" ";break;
            }
            
            if (j<2) cout<<"|";
        }
        if(i<2)cout<<"\n-+-+-\n";
    }
}
void printdisplay(){
      int k=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            switch (displayboard[i][j]){
                
                case X:     cout<<"X";break;
                case O:     cout<<"O";break;
                case EMPTY: cout<<k;break;
            }
            k++;
            if (j<2) cout<<"|";
        }
        if(i<2)cout<<"\n-+-+-\n";
        
    }
}

int main()
{
    bool gameOver;
  
    
  
    
   
   
     int choice;
    clearBoard();
    
    while(!gameOver)
    {
     
          int winner = getWinner();
                if (winner == X || winner == O) {
                    cout << "Player " << (winner == X ? 'X' : 'O') << " wins!" << endl;
                    gameOver=true;
        
            break;
        }
        else {
        
       cout<<" "<<endl;
       cout<<endl;
       printdisplay();
       cout<<endl;
       cout<<endl;
       printBoard();
       cout<<"  It is Currently ";
        if (currentPlayer==1){
            cout<<"X's";
        }
        else{
            cout<<"O's";
        }
        cout<<" Turn"<<endl;
        cout<<"               "<< endl;
        cout<<"     Enter Your Move Based on the numbers 0-8. Enter 9 to Exit. In the event of a tie, Enter 10 to clear the board. "<<endl;
        
        
        cin>>choice;
        switch(choice)
        {
            case 0 :
            {
                cout<<" "<<endl;
                putMark(0,0);
                
              
                 
            
                break;
            
            }
            case 1 :
            {
                
            putMark(0,1);
            printBoard();
              
            break;
            }
            case 2 :{
                
                  
                putMark(0,2);
                printBoard();
                 
            
                break;
            }
            case 3 :{
               
                putMark(1,0);
                printBoard();
               
                break;
            }
            case 4 :{
               
                putMark(1,1);
                printBoard();
                
                  
            
                break;
            }
            case 5 :{
                
                putMark(1,2);
                printBoard();
                 
            
                break;
            }
            case 6 :{
                
                putMark(2,0);
                printBoard();
               
                  
            
                break;
            }
            case 7 :{
                
                putMark(2,1);
                printBoard();
                  
            
                break;
            }
            case 8 :{
               
                putMark(2,2);
                printBoard();
                  
            
                break;
            }
            case 9 :{
                gameOver=true;
                break;
            }
            
            case 10:{
                clearBoard();
                printBoard();
                break;
            }
        }
        }                           
    }    


}




    








