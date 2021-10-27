#include<bits/stdc++.h>
using namespace std;

const int maxlen = 205;

void generateSubStrings(string s, unordered_map<string,int>& mpp) {
    int l = s.length();
    for (int i = 0; i < l; i++) {
        string temp = "";
        for (int j = i; j < l; j++) {
            temp += s[j];
            mpp[temp] += 1;
        }
    }
}

void binomialCoeff(int C[maxlen][maxlen])
{
    int i, j;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

int answerQuery(unordered_map<string, int>& mpp, int C[maxlen][maxlen], int k) {
    int ans = 0;
    for (auto it : mpp) {
      if (it.second >= k)
            ans += C[it.second][k];
    }
    return ans;
}

int calculateCost(int i, int j, string &s) {
  string sz = "";
  for(int k = i; k <= j; k++) sz += s[k];
  unordered_map<string, int> mpp;
  generateSubStrings(sz, mpp);
  int C[maxlen][maxlen];
  memset(C, 0, sizeof C);
  binomialCoeff(C);

  return answerQuery(mpp, C, 2);
}

int f(int i, int k, string &s) {
  if(i == 0) {
    return 0;
  } else if(k == 1) {
    return calculateCost(0, i, s);
  } else {
    int res = INT_MAX;
    for(int j = i-1; j >= 0; j--) {
      int cost = calculateCost(j+1, i, s);
      res = min(res, cost + f(j, k-1, s));
    }
    return res;
  }
}

int solve(int n, int k, string s) {
  return f(n-1, k, s);
}

int main() {
  int n, k;
  string s;
  cin>>n>>k;
  cin>>s;
  cout<<solve(n, k, s)<<"\n";
  return 0;
}