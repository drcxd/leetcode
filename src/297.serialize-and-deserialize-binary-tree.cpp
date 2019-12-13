class Codec {
public:
    string serialize(TreeNode *root) {
        string s;
        queue<TreeNode *> q1, q2;
        queue<TreeNode *> *p1 = &q1, *p2 = &q2;

        if (!root) {
            return s;
        }

        p1->push(root);
        while (!p1->empty()) {
            while (!p1->empty()) {
                TreeNode *n = p1->front();
                p1->pop();
                if (n) {
                    unsigned int x = (unsigned int)n->val;
                    s.push_back(1); // non-empty node
                    s.push_back((x & 0xff000000) >> 24);
                    s.push_back((x & 0x00ff0000) >> 16);
                    s.push_back((x & 0x0000ff00) >> 8);
                    s.push_back((x & 0x000000ff));
                    p2->push(n->left);
                    p2->push(n->right);
                } else {
                    s.push_back(0); // empty node
                    // s.push_back(0);
                    // s.push_back(0);
                    // s.push_back(0);
                    // s.push_back(0);
                }
            }
            swap(p1, p2);
        }

        return s;
    }

    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        TreeNode *root = nullptr;
        queue<TreeNode **> q;
        q.push(&root);
        for (int i = 0; i < data.size(); ) {
            if (!q.empty()) {
                TreeNode **pp = q.front();
                q.pop();
                if (data[i] == 1) { // non empty node
                    unsigned int v = 0;
                    ++i;
                    v |= (unsigned char)data[i] << 24;
                    ++i;
                    v |= (unsigned char)data[i] << 16;
                    ++i;
                    v |= (unsigned char)data[i] << 8;
                    ++i;
                    v |= (unsigned char)data[i];
                    *pp = new TreeNode((int)v);
                    q.push(&((*pp)->left));
                    q.push(&((*pp)->right));
                } else {
                    *pp = nullptr;
                }
                ++i;
            }
        }
        return root;
    }
private:
};