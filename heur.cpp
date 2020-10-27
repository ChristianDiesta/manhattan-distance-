#include <iostream>
#include <cmath>

using namespace std;

struct Puzzle{
    int state[3][3];
    int path_cost;
    Puzzle * parent;
};

void display(int print[3][3]){
    int i = 0;
    int temp[3][3] = {{0}};
    cout << "\n";
    cout << " -------------" << endl;
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            i++;
            cout << " | " << print[row][col];
        }
        cout << " |" << endl;
        cout << " -------------" << endl;
    }
    cout << "\n";
}

void heuristic(Puzzle initial_node, Puzzle goal_node){
    int heur = 0;
    int temp1,temp2,temp3,temp4;
    int i,j,x,y = 0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(initial_node.state[i][j] != goal_node.state[i][j]){
                temp1 = initial_node.state[i][j];
                temp2 = i + j;
                if(temp1 != 0){
                    for(x=0;x<3;x++){
                        for(y=0;y<3;y++){
                            if(temp1 == goal_node.state[x][y]){
                                temp4 = x + y;
                                heur = heur + abs(x - i) + abs(y - j);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Heuristic value:" << heur << endl;
}

int main(){
    Puzzle initial;
    Puzzle goal;
    int pos;

    cout<<"Enter the initial state of the game!"<<endl;

    for(int i=0; i<3; ++i){
        for(int j=0;j<3;j++){
            cin >> pos;
            initial.state[i][j] = pos;
        }
    }
    display(initial.state);

    cout<<"Enter the goal state of the game!"<<endl;
    for(int i=0; i<3; ++i){
        for(int j=0;j<3;j++){
        cin>>pos;
        goal.state[i][j] = pos;
        }
    }
    display(goal.state);

    heuristic(initial,goal);
    return 0;
}
