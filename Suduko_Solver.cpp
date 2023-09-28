#include<bits/stdc++.h>
using namespace std;


void helper(int r, int c, vector<vector<char>> &Suduko, map<pair<int,int>,map<int,int>> &mp,vector<map<int,int>> &row,vector<map<int,int>> &col) {
    if(r==9) {
        for(auto it: Suduko) {
            for(auto i: it) {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return ;
    }
    if(c==9) {
        helper(r+1,0,Suduko,mp,row,col);
        return ;
    }

    if(Suduko[r][c]!='.') {
        helper(r,c+1,Suduko,mp,row,col);
        return ;
    }

    for(int i=1; i<=9; i++) {
        int rw=r/3, cl=c/3;
        if(!mp[{rw,cl}][i] && !row[r][i] && !col[c][i]) {
            mp[{rw,cl}][i]=1;
            row[r][i] = 1;
            col[c][i] = 1;
            Suduko[r][c] = i+'0';
            helper(r,c+1,Suduko,mp,row,col);
            mp[{rw,cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            Suduko[r][c] ='.';

        }
    }
}
void Solve_suduko(vector<vector<char>> &Suduko) {
    map<pair<int,int>,map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            // . indicates a empty cell in a suduko
            if(Suduko[i][j]!='.'){
                mp[{i/3,j/3}][Suduko[i][j]-'0']=1;
                row[i][Suduko[i][j]-'0']=1;
                col[j][Suduko[i][j]-'0']=1;

            }
        }
    }
    helper(0,0,Suduko,mp,row,col);
}
int main() {
    // define a 2d matrix of n size


    // Sample input for test cases 
    vector<vector<char>> Suduko={
        {'5' , '3' , '.' , '.' , '7' , '.' , '.' , '.' , '.'},
        {'6' , '.' , '.' , '1' , '9' , '5' , '.' , '.' , '.'},
        {'.' , '9' , '8' , '.' , '.' , '.' , '.' , '6' , '.'},
        {'8' , '.' , '.' , '.' , '6' , '.' , '.' , '.' , '3'},
        {'4' , '.' , '.' , '8' , '.' , '3' , '.' , '.' , '1'},
        {'7' , '.' , '.' , '.' , '2' , '.' , '.' , '.' , '6'},
        {'.' , '6' , '.' , '.' , '.' , '.' , '2' , '8' , '.'},
        {'.' , '.' , '.' , '.' , '1' , '9' , '.' , '.' , '5'},
        {'.' , '.' , '.' , '.' , '8' , '.' , '.' , '7' , '9'},

    };

    // For multiple Test cases  user input a 9*9 Matrix
    
     for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>Suduko[i][j];
        }
     }
    Solve_suduko(Suduko);
    return 0;
}