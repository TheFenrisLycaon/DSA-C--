#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
#define rep(i,a,b) for(int i=a; i<b; i++)

int int_size = 32;
class node{
  public:
    node *next[2];
    node(){
      rep(i,0,2){
        next[i] = NULL;
      }
    }
};

node* trie;
void insert(int num){
  node* it = trie;
  for(int i=int_size-1;i>=0;i--){
    int cur_bit = (num>>i) & i;
    if(!it->next[cur_bit])
        it->next[cur_bit] = new node();
    it = it->next[cur_bit];
  }
}

int query(int num){
  node *it = trie;
  int ans = 0;
  for(int i=int_size-1;i>=0;i--){
    int cur_bit = (num>>i) & i;
    int opposite = cur_bit xor 1;
    if(it->next[opposite]){
      it = it->next[opposite];
      ans |= 1<<i;
    }
    else{
      it = it->next[opposite xor 1];
    }
  }
  return ans;
}
 
int main()
{
  int n;
  cin>>n;

  vi a(n);
  for(auto &i : a){
    cin>>i;
  }

  trie = new node();
  insert(0);
  vi rmax(n+1,0);
  int R = 0;
  for(int i=n-1;i>=0;i--){
    R = R xor a[i];
    if(i != n-1){
      rmax[i] = max(rmax[i+1], query(R));
      insert(R);
    }

    else{
      rmax[i] = query(R);
      insert(R);
    }
  }

  free(trie);
  trie = new node();
  insert(0);
  int ans = 0;
  int L = 0;
  rep(i,0,n){
    L = L xor a[i];
    ans = max(ans, rmax[i+1] + query(L));
    insert(L);
  }
  cout<<ans;
  return 0;
}