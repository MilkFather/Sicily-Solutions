#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct TREENODE {
    int coeffi;
    int power;
    TREENODE * lchild;
    TREENODE * rchild;
    
    TREENODE(int coef, int p): coeffi(coef), power(p), lchild(NULL), rchild(NULL) {};
} TreeNode;

void buildTree(TREENODE *&root) {
    int pc, pcoef, pp;
    cin >> pc;
    for (int i = 0; i < pc; i++) {
        cin >> pcoef >> pp;
        TREENODE *item = new TREENODE(pcoef, pp);
        if (root == NULL)
            root = item;
        else {
            TREENODE *walk = root;
            while (true) {
                if (walk->power == pp) {
                    walk->coeffi += pcoef;
                    break;
                } else if (pp > walk->power) {
                    if (walk->lchild == NULL) {
                        walk->lchild = item;
                        break;
                    } else
                        walk = walk->lchild;
                } else {
                    if (walk->rchild == NULL) {
                        walk->rchild = item;
                        break;
                    } else
                        walk = walk->rchild;
                }
            }
        }
    }
}

void in_order(TREENODE *r, vector<pair<int, int> > &poly) {
    if (r == NULL)
        return;
    else {
        in_order(r->lchild, poly);
        if (r->coeffi != 0)
            poly.push_back(make_pair(r->coeffi, r->power));
        in_order(r->rchild, poly);
        delete r;
    }
}

void work() {
    TREENODE *poly = NULL;
    buildTree(poly);
    buildTree(poly);
    
    vector<pair<int, int> > finalp;
    // in-order visit
    in_order(poly, finalp);
    cout << finalp.size() << endl;
    for (int i = 0; i < finalp.size(); i++) {
        cout << finalp[i].first << " " << finalp[i].second << endl;
    }
}

int main(int argc, const char * argv[]) {
    int kase;
    cin >> kase;
    for (int i = 0; i < kase; i++) {
        work();
    }
    return 0;
}