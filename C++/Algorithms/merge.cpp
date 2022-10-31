#include<bits/stdc++.h>
using namespace std;
class Sort{
    public:
        int size;
        vector<int> arr;
        Sort(int n){
            size = n;
            arr.resize(n);
        }
        void intake();
        void mergeSort(int st, int end);
        void merge(int st, int mid, int end);
        void swamp(int i, int j);
        void display();
};

void Sort::intake(){
    // cout<<"here "<<size<<endl;
    for(int i =0;i<size;i++) cin>>arr[i];
}
void Sort::swamp(int i ,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Sort::mergeSort(int st, int end){
    if(st<(end-1)){
        int mid = (st+end)/2;
        // cout<<st<<" a "<<end<<" "<<mid<<endl;
        mergeSort(st,mid-1);
        mergeSort(mid,end);
        merge(st,mid, end);
    }

}

void Sort::merge(int st, int mid, int end){
    // cout<<size<<endl;
    int res = mid+1;
    vector<int>lft;
    vector<int>rgt;

    for(int i = st;i<mid;i++)  lft.push_back(arr[st]);
    for(int i = mid;i<=end;i++)  rgt.push_back(arr[st]);
    int a =0,b =0, i = st;
    while(a<lft.size() && b<rgt.size()){
        if(lft[a]>rgt[b]){
             arr[i++] = rgt[b];
             b++;
             }
        else{
            arr[i++] = lft[a];
            a++;
        }
    }
    while(a<lft.size()){
        arr[i++] = lft[a];
        a++;
        
    }
    while(b<rgt.size()){
        arr[i++] = rgt[b];
        b++;
    }
}

void Sort::display(){
    // cout<<size<<endl;
    for(int i = 0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    Sort srt = Sort(n);
    srt.intake();
    srt.mergeSort(0,n-1);
    srt.display();
    return 0;
}