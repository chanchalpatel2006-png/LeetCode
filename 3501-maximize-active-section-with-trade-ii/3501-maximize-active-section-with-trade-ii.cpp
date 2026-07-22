class Solution {
public:
    vector<int> seg;

    void build(int node, int l, int r, vector<int>& gain) {
        if (l == r) {
            seg[node] = gain[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, gain);
        build(node * 2 + 1, mid + 1, r, gain);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int n = s.size();

        // Total active sections in the ORIGINAL string
        int active = 0;

        for (char c : s)
            active += (c == '1');

        /*
            Compress string into runs.

            Example:
            s = 001110011

            runs:
            00 | 111 | 00 | 11
             0     1     2    3
        */

        vector<char> type;
        vector<int> len;
        vector<int> start;
        vector<int> ending;

        // runId[position] = which run contains this position
        vector<int> runId(n);

        for (int i = 0; i < n; ) {

            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            int id = type.size();

            type.push_back(s[i]);
            len.push_back(j - i);
            start.push_back(i);
            ending.push_back(j - 1);

            for (int k = i; k < j; k++)
                runId[k] = id;

            i = j;
        }

        int m = type.size();

        /*
            gain[i] is useful only when run i is a 1-run:

                zero-run | one-run | zero-run

            gain = leftZeros + rightZeros
        */

        vector<int> gain(m, 0);

        for (int i = 1; i + 1 < m; i++) {

            if (type[i] == '1' &&
                type[i - 1] == '0' &&
                type[i + 1] == '0') {

                gain[i] = len[i - 1] + len[i + 1];
            }
        }

        seg.assign(4 * m, 0);
        build(1, 0, m - 1, gain);

        vector<int> ans;

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            int L = runId[l];
            int R = runId[r];

            int mx = 0;

            /*
                Completely internal runs.

                For a 1-run i, we need:

                    i-1, i, i+1

                completely inside [l,r].

                Runs L and R can be partially covered,
                so exclude candidates touching them here.
            */

            int ql = L + 2;
            int qr = R - 2;

            if (ql <= qr)
                mx = query(1, 0, m - 1, ql, qr);

            /*
                LEFT boundary candidate:

                    L | L+1 | L+2

                Candidate 1-run = L+1.

                Its left zero-run may be cut by l.
            */

            int i = L + 1;

            if (i > 0 && i + 1 < m &&
                i <= R &&
                type[i] == '1' &&
                type[i - 1] == '0' &&
                type[i + 1] == '0' &&
                ending[i] < r) {

                int leftZeros =
                    ending[i - 1] - l + 1;

                int rightZeros =
                    min(r, ending[i + 1]) - start[i + 1] + 1;

                if (leftZeros > 0 && rightZeros > 0)
                    mx = max(mx, leftZeros + rightZeros);
            }

            /*
                RIGHT boundary candidate:

                    R-2 | R-1 | R

                Candidate 1-run = R-1.

                Its right zero-run may be cut by r.
            */

            i = R - 1;

            if (i > 0 && i + 1 < m &&
                i >= L &&
                type[i] == '1' &&
                type[i - 1] == '0' &&
                type[i + 1] == '0' &&
                start[i] > l) {

                int leftZeros =
                    ending[i - 1] - max(l, start[i - 1]) + 1;

                int rightZeros =
                    r - start[i + 1] + 1;

                if (leftZeros > 0 && rightZeros > 0)
                    mx = max(mx, leftZeros + rightZeros);
            }

            ans.push_back(active + mx);
        }

        return ans;
    }
};