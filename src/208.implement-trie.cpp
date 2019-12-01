class Node {
public:
    char val;
    bool end;
    Node *children[26];

    Node()
        : val(0)
        , end(false) {
        memset(children, 0, sizeof(Node*) * 26);
    }
};

class Trie {
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *it = root;
        for (char c : word) {
            if (it->children[c - 'a']) {
                it = it->children[c - 'a'];
            } else {
                it->children[c - 'a'] = new Node();
                it = it->children[c - 'a'];
            }
        }
        it->end = true;
    }

    bool search(string word) {
        Node *it = root;
        for (char c : word) {
            if (it->children[c - 'a']) {
                it = it->children[c - 'a'];
            } else {
                return false;
            }
        }
        return it->end;
    }

    bool startsWith(string prefix) {
        Node *it = root;
        for (char c : prefix) {
            if (it->children[c - 'a']) {
                it = it->children[c - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
private:

    Node *root;
};