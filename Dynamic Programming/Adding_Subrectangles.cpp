#include <iostream>
#include <vector>
using namespace std;
int CharToInt(char pivot);
vector<vector<int>> AddSubrectangles(vector<vector<char>> rectangle);

int main(){
    int rows, columns;
    char character;
    vector<char> row;
    vector<vector<char>> rectangle;
    vector<vector<int>> subrectangles;
    cout << "Give me the number of rows and columns in this order.\n";
    cin >> rows;
    cin >> columns;
    cout << "Now give the characters in the rectangle, reading in the usual order.\n";

    for(int i=0; i<rows; i++){
        row.clear();
        for(int j=0; j<columns; j++){
            cin >> character;
            row.push_back(character);
        }
        rectangle.push_back(row);
    }

    subrectangles = AddSubrectangles(rectangle);

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << subrectangles[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

vector<vector<int>> AddSubrectangles(vector<vector<char>> rectangle){
    vector<vector<int>> subrectangles(rectangle.size(), vector<int>(rectangle[0].size(), 0));
    for(int i=0; i<rectangle.size(); i++){
        for(int j=0; j<rectangle[0].size(); j++){
            int pivot=CharToInt(rectangle[i][j]);
            if(j>0) pivot+=subrectangles[i][j-1];
            if(i>0) pivot+=subrectangles[i-1][j];
            if(i>0 && j>0) pivot-=subrectangles[i-1][j-1];
            subrectangles[i][j]=pivot;
        }
    }
    return subrectangles;
}

int CharToInt(char pivot){
    int n = pivot-64;
    return n*(n+1)/2;
}

