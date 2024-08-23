#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;


void displayMoves(vector<vector<int>> x){
    int n = x.size();
    int y;
    for(int i=0;i<n;i++){
        cout << x[i][0] << " " << x[i][1] << " " << x[i][2] << " " << x[i][3] << "\n";
    }
}


class Chess{
    private:
        string board[8][8];
    
    public:
        Chess(){
            for (int i=0;i<8;i++){
                for (int j=0;j<8;j++){
                    board[i][j] = " ";
                }
            }
            for(int i=0;i<8;i++){
                board[1][i] = "black_pawn";
                board[6][i] = "white_pawn";
            }
            board[0][0] = "black_rook";
            board[0][7] = "black_rook";
            board[7][0] = "white_rook";
            board[7][7] = "white_rook";
            board[0][1] = "black_knight";
            board[0][6] = "black_knight";
            board[7][1] = "white_knight";
            board[7][6] = "white_knight";
            board[0][2] = "black_bishop";
            board[0][5] = "black_bishop";
            board[7][2] = "white_bishop";
            board[7][5] = "white_bishop";
            board[0][3] = "black_queen";
            board[7][3] = "white_queen";
            board[0][4] = "black_king";
            board[7][4] = "white_king";

        }

        void piece(int x, int y){
            cout << board[x][y] << "\n";
        }

        void display(){

            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(board[i][j] == "black_rook"){
                        cout << " ro ";
                    }
                    else if(board[i][j] == "white_rook"){
                        cout << " RO ";
                    }
                    else if(board[i][j] == "black_knight"){
                        cout << " kn ";
                    }
                    else if(board[i][j] == "white_knight"){
                        cout << " KN ";
                    }
                    else if(board[i][j] == "white_bishop"){
                        cout << " BI ";
                    }
                    else if(board[i][j] == "black_bishop"){
                        cout << " bi ";
                    }
                    else if(board[i][j] == "black_king"){
                        cout << " ki ";
                    }
                    else if(board[i][j] == "white_king"){
                        cout << " KI ";
                    }
                    else if(board[i][j] == "white_queen"){
                        cout << " QU ";
                    }
                    else if(board[i][j] == "black_queen"){
                        cout << " qu ";
                    }
                    else if(board[i][j] == " "){
                        cout << "1  1";
                    }
                    else if(board[i][j] == "black_pawn"){
                        cout << " pa ";
                    }
                    else if(board[i][j] == "white_pawn"){
                        cout << " PA ";
                    }
                }
                //make look more pretty
                cout << "\n";
            }
            cout << "\n\n";
        }

        unordered_set<string> white_peices = {"white_pawn", "white_queen", "white_king", "white_bishop", "white_knight","white_king","white_rook"};
        unordered_set<string> black_peices = {"black_pawn", "black_queen", "black_king", "black_bishop", "black_knight","black_king","black_rook"};

        vector<vector<int>> legalmoves1(int x,int y){
            vector<vector<int>> legalmoves1;
            //add moves, add turns
            if(board[x][y] == "white_pawn"){
                if (board[x-1][y] == " "){
                    vector<int> vec = {x,y,x-1,y};
                    legalmoves1.push_back(vec);
                }
                if (black_peices.find(board[x-1][y-1]) != black_peices.end()){
                    vector<int> vec = {x,y,x-1,y-1};
                    legalmoves1.push_back(vec);
                }
                if (black_peices.find(board[x-1][y+1]) != black_peices.end()){
                    vector<int> vec = {x,y,x-1,y+1};
                    legalmoves1.push_back(vec);
                }
                //missing en passant and 2 squares
                //missing queening
            }
            if(board[x][y] == "black_pawn"){
                if (board[x+1][y] == " "){
                    vector<int> vec = {x,y,x+1,y};
                    legalmoves1.push_back(vec);
                }
                if (white_peices.find(board[x+1][y-1]) != white_peices.end()){
                    vector<int> vec = {x,y,x+1,y-1};
                    legalmoves1.push_back(vec);
                }
                if (white_peices.find(board[x+1][y+1]) != white_peices.end()){
                    vector<int> vec = {x,y,x+1,y+1};
                    legalmoves1.push_back(vec);
                }
                //missing en passant and 2 squares
                //missing queening
            }
            if(board[x][y] == "white_bishop"){
                for(int i=1;i<8;i++){
                    if(x+i<8 && y+i<8 && (white_peices.find(board[x+i][y+i]) == white_peices.end())){
                        //cout << "greetings";
                        vector<int> vec = {x,y,x+i,y+i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
                for(int i=1;i<8;i++){
                    if(x+i<8 && y-i>-1 && (white_peices.find(board[x+i][y-i]) == white_peices.end())){
                        vector<int> vec = {x,y,x+i,y-i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
                for(int i=1;i<8;i++){
                    if(x-i>-1 && y-i>-1 && (white_peices.find(board[x-i][y-i]) == white_peices.end())){
                        vector<int> vec = {x,y,x-i,y-i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
                for(int i=1;i<8;i++){
                    if(x-i>-1 && y+i<8 && (white_peices.find(board[x-i][y+i]) == white_peices.end())){
                        vector<int> vec = {x,y,x-i,y+i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
            }
            if(board[x][y] == "black_bishop"){
                for(int i=1;i<8;i++){
                    if(x+i<8 && y+i<8 && (black_peices.find(board[x+i][y+i]) == black_peices.end())){
                        //cout << "greetings";
                        vector<int> vec = {x,y,x+i,y+i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
                for(int i=1;i<8;i++){
                    if(x+i<8 && y-i>-1 && (black_peices.find(board[x+i][y-i]) == black_peices.end())){
                        vector<int> vec = {x,y,x+i,y-i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
                for(int i=1;i<8;i++){
                    if(x-i>-1 && y-i>-1 && (black_peices.find(board[x-i][y-i]) == black_peices.end())){
                        vector<int> vec = {x,y,x-i,y-i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
                for(int i=1;i<8;i++){
                    if(x-i>-1 && y+i<8 && (black_peices.find(board[x-i][y+i]) == black_peices.end())){
                        vector<int> vec = {x,y,x-i,y+i};
                        legalmoves1.push_back(vec);
                    } else {
                        break;
                    }
                }
            }
            return legalmoves1;
        }

        vector<vector<int>> legalmoves3(){
            vector<vector<int>> legalmoves3;
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    vector<vector<int>> x = legalmoves1(i,j);
                    legalmoves3.insert(legalmoves3.end(),x.begin(),x.end());
                }
            }
            return legalmoves3;
        }

        void move(char a, int b, char c, int d){
            int  A = 8-b;
            int B = a-'A';
            int  C = 8-d;
            int D = c-'A';
            
            vector<int> vec = {A,B,C,D};
            //cout << A << " " << B << " " << " " << C << " " << D;
            vector<vector<int>> LM = legalmoves3();
            if(find(LM.begin(),LM.end(),vec) != LM.end()){
                cout << D << C << "\n";
                cout << B << A << "\n";
                board[C-1][D] = board[A-1][B];
                board[A-1][B] = " ";
                display();
            } else {
                cout << "Please input a legal move.";
            }
        }



};

int main(){
    Chess x = Chess();
    x.display();
    //displayMoves(x.legalmoves3());
    while(0 == 0){
        char a;
        int b;
        char c;
        int d;
        cin >> a >> b >> c >> d;
        x.move(a,b,c,d);
        //displayMoves(x.legalmoves3());
    }
    //x.move(6,0,5,0);
    return 0;
}