struct WordNode {
    string word;
    WordNode *next = nullptr;
};

class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        bool inWord = false;
        string word;
        WordNode *head = nullptr;
        WordNode **it = &head;
        WordNode *prev = nullptr;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == ' ' && !inWord) {
                continue;
            }
            if (c == ' ' && inWord) {
                *it = new WordNode();
                (*it)->word = word;
                if (prev) {
                    prev->next = (*it);
                }
                prev = (*it);
                it = &((*it)->next);
                word.clear();
                inWord = false;
                continue;
            }
            word.push_back(c);
            if (!inWord) {
                inWord = true;
            }
        }

        WordNode *new_head = reverse(head);
        WordNode *p = new_head;
        string res;
        while (p) {
            res.append(p->word);
            res.push_back(' ');
            p = p->next;
        }
        res.pop_back();
        return res;
    }
private:
    WordNode *reverse(WordNode *head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }
        WordNode *n = head->next;
        head->next = nullptr;
        WordNode *new_head = reverse(n);
        n->next = head;
        return new_head;
    }
};