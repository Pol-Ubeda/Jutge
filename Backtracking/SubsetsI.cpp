#include<iostream>
#include<vector>
#include<map>
using namespace std;

void backtracking(int n, vector<string> &words, vector<vector<string>> &subsets);
void backtrackingII(vector<string> words, vector<string> current, vector<vector<string>> &subsets);
vector<string> EliminateIndex(vector<string> &words, int index);

int main(){
    int n;
    string word;
    vector<string> words;
    vector<vector<string>> subsets;
    cout << "Please give me a list of words after specifying how many you'll give.\n";
    cin >> n;
    for(int i=0; i<n ;i++){
        cin >> word;
        words.push_back(word);
    }

    vector<string> current;
    map<vector<string>,int> reducer;
    backtracking(n, words, subsets);
    for(int i=0; i<subsets.size(); i++){
        if(reducer.find(subsets[i])==reducer.end()){
            reducer[subsets[i]]=1;
        }
    }
    for(const auto& pair : reducer){
        cout << "{";
        for(string element: pair.first) cout << element << " ";
        cout << "}";
    }

    return 0;
}

void backtracking(int n, vector<string> &words, vector<vector<string>> &subsets){
    if(words.empty()) return;
    int len=words.size();
    vector<string> reduced_words;
    subsets.push_back(words);
    for(int i=0; i<n; i++){
        reduced_words=EliminateIndex(words,i);
        backtracking(n-1,reduced_words,subsets);
    }
}




vector<string> EliminateIndex(vector<string> &words, int index){
    vector<string> new_words;
    for(int i=0; i<words.size(); i++){
        if(i==index) continue;
        new_words.push_back(words[i]);
    }
    return new_words;
}
