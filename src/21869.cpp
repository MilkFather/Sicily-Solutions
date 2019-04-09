#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

#define MAX 0xFFFFFF

using namespace std;

struct node {
    int outorder;
    int inorder;
    int stackno;
};

bool success = true;
int connectmatrix[1001][1001];
vector<node> nodes;

void color(int n, int index, int stackno) {
    nodes[index].stackno = stackno;
    for (int i = 0; i < n; i++) {
        if (connectmatrix[i][index] == 1) {
            if (nodes[i].stackno == nodes[index].stackno) {
                success = false;
                return;
            }
            if (nodes[i].stackno == 0) {
                color(n, i, (nodes[index].stackno == 1 ? 2 : 1));
            }
        }
    }
}

void work(int n) {
    // a hardcore problem
    success = true;
    nodes.clear();
    // read data
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        node newnode;
        newnode.outorder = p;
        newnode.inorder = i;
        newnode.stackno = 0;
        nodes.push_back(newnode);
    }
    // step 1, divide the nodes into a bipartite graph...or can we?
    //int connectmatrix[n][n];
    // also get ready to dp
    int dp[n]; // what is the smallest number after index i?
    int currentmin = MAX;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = currentmin;
        if (nodes[i].outorder < currentmin)
            currentmin = nodes[i].outorder;
    }
    // we do the real work..
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // ith number and jth number cannot be in the same stack (ever, at any moment) iff
            // there exists a k s.t. i < j < k and nodes[k].outorder < nodes[i].outorder < nodes[j].outorder
            if (nodes[i].outorder < nodes[j].outorder && dp[j] < nodes[i].outorder) {
                connectmatrix[i][j] = connectmatrix[j][i] = 1;
            } else {
                connectmatrix[i][j] = connectmatrix[j][i] = 0;
            }
        }
    }
    
    // step 2, dye the bipartite graph...or maybe we can't?
    for (int i = 0; i < n; i++) {
        if (nodes[i].stackno == 0)
            color(n, i, 1);
    }
    
    if (!success) {
        cout << "0" << endl;
        return;
    }
    
    // step 3, mock
    stack<int> stack1, stack2;
    vector<char> moves;
    int currenttarget = 1, queueindex = 0;
    while (currenttarget <= n) {
        // when to push?
        if (queueindex < n) {
            if (nodes[queueindex].stackno == 1) {
                stack1.push(nodes[queueindex].outorder);
                queueindex++;
                moves.push_back('a');
            } else {
                stack2.push(nodes[queueindex].outorder);
                queueindex++;
                moves.push_back('c');
            }
        }
        
        // when to pop?
        while ((!stack1.empty() && stack1.top() == currenttarget) || (!stack2.empty() && stack2.top() == currenttarget)) {
            if (!stack1.empty() && stack1.top() == currenttarget) {
                stack1.pop();
                currenttarget++;
                moves.push_back('b');
            }
            if (!stack2.empty() && stack2.top() == currenttarget) {
                stack2.pop();
                currenttarget++;
                moves.push_back('d');
            }
        }
    }
    
    // before we output, we can actually do some adjustment
    for (int i = 0; i < moves.size() - 1; i++) {
        if (moves[i] == 'd' && moves[i + 1] == 'a') {
            swap(moves[i], moves[i + 1]);
        }
    }
    
    // finally we print them
    cout << moves[0];
    for (int i = 1; i < moves.size(); i++)
        cout << " " << moves[i];
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while (~scanf("%d", &n)) {
        work(n);
    }
    return 0;
}