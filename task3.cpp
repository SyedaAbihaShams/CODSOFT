#include <iostream>
using namespace std;
const int rows = 3;
const int cols = 3;
char grid[rows][cols];
bool firstPrint = true;

void printGrid(){
    cout << "Current representation of the Game Board:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << " ---- ";
        }
        cout << endl;
        cout << "| ";
        for (int j = 0; j < cols; j++) {
            if(firstPrint) grid[i][j] = ' ';
            cout << grid[i][j] << "  |  ";
        }
        cout << endl;
    }
    for (int j = 0; j < cols; j++) {
        cout << " ---- ";
    }
    cout << endl;
    firstPrint = false;
}

void takeInput(int id, int& r , int& c){
    cout<<"Player "<<id<<", it's your turn."<<endl
        <<"Choose a vild position from (0,0) to (2,2)."<<endl;
        
    bool valid = false;
    
    while(!valid){
        cout<<"Enter the position (first row then seperated by a space column: ";
        cin>>r>>c;
        if(r<0 || r>3 || c<0 || c>3){
            cout<<"Invalid input, try again."<<endl;
        }
        else if(grid[r][c] == 'X' && grid[r][c] == 'O'){
            cout<<"This place is already filled, try again."<<endl;
        }
        valid = true;
        grid[r][c] = (id == 1)? 'X' : 'O';
    }
}

int winner(){
    char ch = '#';
    bool found = true;
    for(int i=0 ; i<rows ; i++){
        found = true;
        ch = grid[i][0];
        for(int j=1 ; j<cols ; j++){
            if(ch != grid[i][j]){
                found = false;
                break;
            }
            
            
        }
        if(found){
            if(ch == 'X'){
                return 1;
            }
            else if(ch == 'O'){
                return 2;
            }
        }
    }
    ch = '#';
    for(int j=0 ; j<cols ; j++){
        ch = grid[0][j];
        found = true;
        for(int i=0 ; i<rows ; i++){
            if(ch != grid[i][j]){
                found = false;
                break;
            }
        }
        if(found){
            if(ch == 'X'){
                return 1;
            }
            else if(ch == 'O'){
                return 2;
            }
        }
    }
    ch = grid[0][0];
    found = true;
    for(int i=1 ; i<rows ; i++){
        if(ch != grid[i][i]){
            found = false;
            break;
        }
    }
    if(found){
        if(ch == 'X'){
            return 1;
        }
        else if(ch == 'O'){
            return 2;
        }
    }
    
    ch = grid[0][cols-1];
    found = true;
    for(int i=cols-2 ; i>=0 ; i--){
        if(ch != grid[i][i]){
            found = false;
            break;
        }
    }
    if(found){
        if(ch == 'X'){
            return 1;
        }
        else if(ch == 'O'){
            return 2;
        }
    }
    
    return -1;
}

bool isFilled(){
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if(grid[i][j]!='X' && grid[i][j]!='O') return false;
        }
    }
    
    return true;
}

int main() {
    
    cout << "Player 1 is assigned: X." << endl;
    cout << "Player 2 is assigned: O." << endl;
    
    int r , c;
    int w = -1;
    while(1){
        printGrid();
        takeInput(1,r,c);
        printGrid();
        w = winner();
        if(w == 1 || w == 2){
            cout<<"The winner is player "<<w<<"."<<endl;
            return 0;
        }
        if(isFilled()){
            cout<<"Game over."<<endl;
            return 0;
        }
        
        takeInput(2,r,c);
        w = winner();
        if(w == 1 || w == 2){
            cout<<"The winner is player "<<w<<"."<<endl;
            return 0;
        }
        if(isFilled()){
            cout<<"Game over."<<endl;
            return 0;
        }
    }
    
    return 0;
}
