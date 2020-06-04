//Question Link :(codechef) https://www.codechef.com/problems/AX06
//Code:

#include <iostream>
using namespace std;
int boxNo(int i, int j) {
    if(i>=0 && i<3) {
        if(j>=0 && j<3) {
            return 0;
        } else if(j>=3 && j<6) {
            return 1;
        } else if(j>=6 && j<9) {
            return 2;
        }
    }
    else if(i>=3 && i<6) {
        if(j>=0 && j<3) {
            return 3;
        } else if(j>=3 && j<6) {
            return 4;
        } else if(j>=6 && j<9) {
            return 5;
        }
    }
    else if(i>=6 && i<9) {
        if(j>=0 && j<3) {
            return 6;
        } else if(j>=3 && j<6) {
            return 7;
        } else if(j>=6 && j<9) {
            return 8;
        }
    }
}
bool sudokuSolver(int board[][9], bool row[][10], bool col[][10], bool box[][10], int i, int j) {
    if(i >= 9 ) {
        return true;
    } else if(j>=9) {
        i++;
        j=0;
    }
    
    if(board[i][j] == 0){
        int bn = boxNo(i, j);
        for(int num=1;num<=9;num++) {
            
            if(!row[i][num] && !col[j][num] && !box[bn][num]) {
                row[i][num] = true;
                col[j][num] = true;
                box[bn][num] = true;
                board[i][j] = num;
                if(sudokuSolver(board, row, col, box, i, j+1)) {
                    return true;
                }
                row[i][num] = false;
                col[j][num] = false;
                box[bn][num] = false;
                board[i][j] = 0;
            }
        }
        return false;
    } else {
        return sudokuSolver(board, row, col, box, i, j+1);
    }
    
}
int main() {
	// your code goes here
	int board[9][9];

	for(int i=0;i<9;i++) {
	    string s;
	    cin>>s;
	    for(int j=0;j<9;j++) {
	        board[i][j] = s[j]-'0';
	    }
	}

	bool row[9][10] = {};
    	bool col[9][10] = {};
    	bool box[9][10] = {};
	for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            int num = board[i][j];
            int bn = boxNo(i, j);
            if(!row[i][num] && !col[j][num] && !box[bn][num]) {
                if(num != 0){
                    row[i][num] = true;
                    col[j][num] = true;
                    box[bn][num] = true;
                }
            } 
        }
    }
	if(sudokuSolver(board, row, col, box, 0, 0)) {
	    //print board
	    for(int i=0;i<9;i++) {
	        for(int j=0;j<9;j++) {
	            cout<<board[i][j];
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
