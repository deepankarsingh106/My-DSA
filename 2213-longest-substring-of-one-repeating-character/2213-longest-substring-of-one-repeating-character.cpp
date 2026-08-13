class Solution {
    struct Node {
        int pref, suff, best, len;
        char leftChar, rightChar;

        Node() : pref(0), suff(0), best(0), len(0),
                 leftChar('#'), rightChar('#') {}

        Node(char ch) {
            pref = suff = best = len = 1;
            leftChar = rightChar = ch;
        }
    };

    vector<Node> seg;

    Node merge(Node &L, Node &R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;
        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.pref = L.pref;
        if (L.pref == L.len && L.rightChar == R.leftChar) {
            res.pref += R.pref;
        }

        res.suff = R.suff;
        if (R.suff == R.len && L.rightChar == R.leftChar) {
            res.suff += L.suff;
        }

        res.best = max(L.best, R.best);

        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suff + R.pref);
        }

        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            seg[idx] = Node(s[l]);
            return;
        }

        int mid = (l + r) >> 1;

        build(2 * idx + 1, l, mid, s);
        build(2 * idx + 2, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            seg[idx] = Node(ch);
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, ch);
        else
            update(2 * idx + 2, mid + 1, r, pos, ch);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

public:
    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();
        seg.resize(4 * n);

        build(0, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(seg[0].best);
        }

        return ans;
    }
};