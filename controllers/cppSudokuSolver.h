#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Mass {
    private:
        int num;
    public:
        Mass(int num){
            this->num = num;
        }
        int get_num(){
            return this->num;
        }
        void set_num(int num){
            this->num = num;
        }
};

class SudokuSolver {
    private:
        vector<vector<Mass>> field;
    public:
        SudokuSolver(vector<vector<int>> f){
            vector<vector<Mass>> field;
            for(auto v: f){
                vector<Mass> row;
                for(auto e: v){
                    Mass mass(e);
                    row.push_back(e);
                }
                field.push_back(row);
            }
            this->field = field;

        }

        bool solve(int x, int y){
            if( y > 8 ){
                return true;
            }else if( x > 8 ){
                if(solve(0, y+1) == 1){
                    return true;
                }
            }else if(this->field[y][x].get_num() != 0){
                if(solve(x+1, y) == 1){
                    return true;
                }
            }else{
                for(int i=1; i<=9; i++){
                    int tmp = this->change_num(x, y, i);
                    if(tmp != 0){
                        if(solve(x+1, y) == 1){
                            return true;
                        }
                    }
                }
                this->field[y][x].set_num(0);
            }
            return false;
        }

        bool has_room_for_n(char c, int x, int y, int n){
            int col = ( x / 3) * 3;
            int row = ( y / 3) * 3;
            switch(c){
                case 'v':
                    for(int i=0; i<9; i++){
                        if(this->field[i][x].get_num() == n){
                            return false;
                        }
                    }
                    break;
                case 'h':
                    for(int i=0; i<9; i++){
                        if(this->field[y][i].get_num() == n){
                            return false;
                        }
                    }
                    break;
                case 'b':
                    for(int i=col; i<col+3; i++){
                        for(int j=row; j<row+3; j++){
                            if(this->field[j][i].get_num() == n){
                                return false;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
            return true;
        }

        int change_num(int x, int y, int n){
            if(!(this->has_room_for_n('b', x, y, n))) return 0;
            else if(!(this->has_room_for_n('v', x, y, n))) return 0;
            else if(!(this->has_room_for_n('h', x, y, n))) return 0;
            else this->field[y][x].set_num(n);
            return 1;
        }

        void print(){
            for(size_t i = 0; i < this->field.size(); i++){
                for(size_t j = 0; j < this->field[i].size(); j++){
                    cout << this->field[i][j].get_num() << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        vector<vector<int>> get_field(){
            vector<vector<int>> returnField(9, vector<int>(9, 0));
            for(size_t i = 0; i < this->field.size(); i++){
                for(size_t j = 0; j < this->field[i].size(); j++){
                    returnField[i][j] = this->field[i][j].get_num();
                }
            }
            return returnField;
        }
};