#include<bits/stdc++.h>
using namespace std;

class sgt{
private:
    int inf = INT_MAX;
    vector<int> defaultValue = {inf, inf};

public:
    sgt(int n, vector<int> a){
        vector<vector<int>> min(4*n, vector<int>(2));
    }

    int leftNode(int index){
        return 2*index;
    }

    int rightNode(int index){
        return 2*index + 1;
    }

    vector<int> combIneChildren(vector<int> l, vector<int> r){

        vector<int> temp = {l[1], l[0], r[0], r[1]};
        sort(temp.begin(), temp.end());
        vector<int> res = {temp[0], temp[1]};
        return res;
    }

    void updateCurrentNode(int index){
        vector<int> l = min[leftNode(index)];
        vector<int> r = min[rightNode(index)];

        min[index] = combIneChildren(l, r);
    }

    void build(int index, int start, int end){

        if(start == end){
            min[index][0] = a[start];
            min[index][1] = inf;
            return;
        }

        int mid = (start + end) / 2;

        build(leftNode(index), start, mid);
        build(rightNode(index), mid + 1, end);

        updateCurrentNode(index);
    }

    void update(int index, int start, int end, int pos, int x){
        // leaf node
        if(start == end){
            a[start] = x;
            min[index][0] = x;
            return;
        }

        int mid = (start + end) / 2;

        if(mid >= pos){
            update(leftNode(index), start, mid, pos, x);
        }else{
            update(rightNode(index), mid+1, end, pos, x);
        }

        updateCurrentNode(index);
    }

    vector<int> query(int index, int start, int end, int qL, int qR){

        //no overlap
        if(start > qR || end < qL){
            return dv;
        }

        // complete overlap
        if(start >= qL && end <= qR){
            return min[index];
        }

        int mid =  (start + end) / 2;
        vector<int> ansL = query(leftNode(index), start, mid, qL, qR);
        vector<int> ansR = query(rightNode(index), mid + 1, end, qL, qR);

        return combIneChildren(ansL, ansR);
    }

};


void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);


}

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);

    solve();

    return 0;
}