#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int path_length(int m, vector<vector<int>> mx, vector<int> path){
    // firstly we calculate lengths between
    // 0 and mx[0] vertexes
    // 1 and mx[m-1] vertexes
    // because mx[0] and mx[m-1] are connected with 0.
    int length = mx[0][path[0]] + mx[0][path[m-1]];

    // when after path[i] comes path[i + 1],
    // we should calculate distance between them
    for (int i = 1; i < m; i++){
        length += mx[path[i]][path[i - 1]];
    }
    return length;
}

int main(){
    // just read input 
    int n;
    cin >> n;
    vector<vector<int>> mx (n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mx[i][j];
        }
    } 

    // in which order we will visit cities
    vector<int> cities;
    for (int i = 1; i < n; i++){
        cities.push_back(i);
    }

    // check all permutations
    bool t = true;
    int shortest_length = INT_MAX;
    vector<int> answer(n - 1, 0);
    while (t){
        // calculate length of current path
        int length = path_length(n - 1, mx, cities);
        if (length < shortest_length){
            // copies vector, if this path better
            shortest_length = length;
            for (int i = 0; i < n - 1; i++)
                answer[i] = cities[i];
        }
        t = next_permutation(cities.begin(), cities.end());
    }


    // output
    cout << "Best path is: 0->";
    for (int i = 0; i < n - 1; i++){
        cout << answer[i] << "->";
    }
    cout << "0" << endl;
    cout << "length: " << shortest_length << endl;
}