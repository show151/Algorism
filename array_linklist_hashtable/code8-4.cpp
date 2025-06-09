#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node * next;      // 次のノードへのポインタ
    string name;      // ノードが保持する名前

    Node(string name_ = "") : next(NULL), name(name_) { } // コンストラクタ
};

Node* nil; // 番兵ノード（リストの終端を示す）

// 番兵ノードを初期化する関数
void init() {
    nil = new Node();
    nil->next = nil; // 番兵の次は自分自身を指す
}

// リストの内容を先頭から順に出力する関数
void printList() {
    Node * cur = nil->next; // 先頭ノードから開始
    for (; cur != nil; cur = cur->next) { // nilに到達するまでループ
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// ノードvをノードpの直後に挿入する関数（p未指定時は先頭に挿入）
void insert(Node* v, Node* p = nil) {
    v->next = p->next; // vの次をpの次に
    p->next = v;       // pの次をvに
}

int main() {
    init(); // 番兵ノードを初期化

    vector<string> names = {"yamamoto", "watanabe", "ito", "takahashi", "suzuki", "sato"}; // 挿入する名前リスト

    // namesの各要素をノードとしてリストに挿入し、都度リストを出力
    for (int i = 0; i < (int)names.size(); ++i) {
        Node* node = new Node(names[i]); // 新しいノードを作成
        insert(node);                    // 先頭に挿入
        cout << "step " << i << ": ";
        printList();                     // 現在のリストを出力
    }

    return 0; // プログラム終了
}