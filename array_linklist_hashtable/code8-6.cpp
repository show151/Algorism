#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node *prev, *next; // 前後のノードへのポインタ
    string name;       // ノードが保持する名前

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { } // コンストラクタ
};

Node* nil; // 番兵ノード（リストの終端を示す）

// 番兵ノードを初期化する関数
void init() {
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

// リストの内容を先頭から順に出力する関数
void printList() {
    Node *cur = nil->next; // 先頭ノードから開始
    for (; cur != nil; cur = cur->next) { // nilに到達するまでループ
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// ノードvをノードpの直後に挿入する関数（p未指定時は先頭に挿入）
void insert(Node* v, Node* p = nil) {
    v->next = p->next;     // vの次をpの次に
    p->next->prev = v;     // pの次の前をvに
    p->next = v;           // pの次をvに
    v->prev = p;           // vの前をpに
}

// ノードvをリストから削除し、メモリを解放する関数
void erase(Node* v) {
    if (v == nil) { 
        return; // 番兵ノードは削除しない
    }
    v->prev->next = v->next; // vの前のノードの次をvの次に
    v->next->prev = v->prev; // vの次のノードの前をvの前に
    delete v;                // vのメモリを解放
}

int main() {
    init(); // 番兵ノードを初期化

    vector<string> names = {"yamamoto", "watanabe", "ito", "takahashi", "suzuki", "sato"}; // 挿入する名前リスト

    Node *watanabe; // "watanabe"ノードへのポインタ
    // namesの各要素をノードとしてリストに挿入し、"watanabe"ノードを記録
    for (int i = 0; i < (int)names.size(); ++i) {
        Node* node = new Node(names[i]);
        insert(node);
        if (names[i] == "watanabe") {
            watanabe = node;
        }
    }

    cout << "Before deletion: ";
    printList(); // 削除前のリストを出力
    erase(watanabe); // "watanabe"ノードを削除
    cout << "After deletion: ";
    printList(); // 削除後のリストを出力

    return 0; // プログラム終了
}