class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList)
        : idx(0)
        , it(nullptr)
        , nestedList(nestedList) {

    }

    int next() {
        if (it && it->hasNext()) {
            return it->next();
        }

        // if not in nest or the nest list is consumed then skip the empty list
        if (it) {
            delete it;
            it = nullptr;
        }

        while (!nestedList[idx].isInteger()) {
            it = new NestedIterator(nestedList[idx++].getList());
            if (it->hasNext()) {
                return it->next();
            }
            delete it;
            it = nullptr;
        }

        return nestedList[idx++].getInteger();
    }

    bool hasNext() {
        if (it && it->hasNext()) {
            return true;
        }

        int copy = idx;
        NestedIterator *temp = nullptr;
        while (copy != nestedList.size() && !nestedList[copy].isInteger()) {
            temp = new NestedIterator(nestedList[copy++].getList());
            if (temp->hasNext()) {
                delete temp;
                return true;
            }
            delete temp;
        }
        return copy != nestedList.size();
    }
private:

    int idx;
    NestedIterator *it;
    vector<NestedInteger> &nestedList;
};