//praveen's 
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>

int getStreetCount(vector<vector<int>> &g, vector<int> &visited, int index, vector<int> &inDegree, unordered_set<int> &set)
{
    visited[index] = 1;
    int sCount = 0;
    bool counted = false;
    //cout << "Index: " << index << endl;
    for (int i = 0; i < g[index].size(); i++)
    {
        if (visited[g[index][i]] == 0)
        {
            visited[g[index][i]] = true;
            int temp = getStreetCount(g, visited, g[index][i], inDegree, set);
            cout << "Index: " << index << " temp : " << temp << endl;
            sCount += temp;
        }
        else if (visited[g[index][i]] == 1 && !counted)
        {
            counted = true;
            cout << "g[index][i]: " << g[index][i] << endl;
            sCount += inDegree[index];
            cout << "In cycle, Index: " << index << " sCount: " << sCount << endl;
        }
        else if (visited[g[index][i]] == 2 && set.find(g[index][i]) != set.end() && !counted)
        {
            counted = true;
            cout << "g[index][i]: " << g[index][i] << endl;
            sCount += inDegree[index];
            cout << "existing cycle, Index: " << index << " sCount: " << sCount << endl;
        }
    }
    if (!counted && sCount > 0)
    {
        sCount += inDegree[index];
    }
    if (sCount > 0)
    {
    cout << "Inserting index: " << index << " into set" << endl;
        set.insert(index);
    }
    visited[index] = 2;
    cout << "for index: " << index << " returning: " << sCount << endl;
    return sCount;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
   /* cin >> t;
    while (t--)
    {*/
        int n=7, m=7;
       // cin >> n >> m;
        vector<int> inDegree(n + 10, 0);
        vector<int> visited(n + 10, 0);
        vector<vector<int>> graph(n + 10);
        unordered_set<int> set;
      /*  for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;*/
            graph[7].push_back(2);
            inDegree[2]++;
            graph[7].push_back(5);
            inDegree[5]++;
            graph[7].push_back(2);
            inDegree[2]++;
            graph[2].push_back(4);
            inDegree[4]++;
            graph[4].push_back(2);
            inDegree[2]++;
            graph[6].push_back(7);
            inDegree[7]++;
            graph[4].push_back(6);
            inDegree[6]++;
      //  }
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << "visiting" << endl;
            if (!visited[i])
                count += getStreetCount(graph, visited, i, inDegree, set);
        }
        cout << count << endl;
   // }
    return 0;
}