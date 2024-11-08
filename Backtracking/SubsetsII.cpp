#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<string> words, vector< string> current, int n, int index,  vector<vector<string>> &subsets);
int main(){
    int n, m;
    string word;
    vector<string> words, current;
    vector<vector<string>> subsets;
    cout << "Specify length of subsets, number of words and word list.\n";
    cin >> m;
    cin >> n;
    for(int i=0; i<n ;i++){
        cin >> word;
        words.push_back(word);
    }

    backtracking(words, current, m, 0, subsets);
    for(vector<string> subset: subsets){
        for(int i=0; i<subset.size(); i++){
            cout << subset[i] << " ";
        }
        cout << "\n";
    }

}

void backtracking(vector<string> words, vector< string> current, int m, int index,  vector<vector<string>> &subsets){
    if(current.size()==m){
        subsets.push_back(current);
        return;
    }
    for(int i=index; i<words.size(); i++){
        current.push_back(words[i]);
        backtracking(words, current, m, i+1, subsets);
        current.pop_back();
    }
}