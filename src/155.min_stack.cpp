class MinStack {
public:
    MinStack() {
    }

    void push(int x) {
        if (content.empty()) {
            min.push(x);
            min2count[x] = 1;
        } else {
            if (x < min.top()) {
                min.push(x);
                min2count[x] = 1;
            } else {
                if (min2count.find(x) != min2count.end()) {
                    ++min2count[x];
                }
            }
        }
        content.push(x);
    }

    void pop() {
        if (content.empty()) {
            return;
        }
        if (content.top() == min.top()) {
            min2count[min.top()]--;
            if (min2count[min.top()] == 0) {
                min2count.erase(min.top());
                min.pop();
            }
        }
        content.pop();
    }

    int top() {
        return content.top();
    }

    int getMin() {
        return min.top();
    }


private:

    unordered_map<int/* min */, int/* count */> min2count;
    stack<int> content;
    stack<int> min;
};