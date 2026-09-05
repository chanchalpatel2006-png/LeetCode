class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        int i = 0;

        while (i < n) {
            // Find how many words fit in this line
            int j = i;
            int wordsLen = 0;

            while (j < n &&
                   wordsLen + words[j].size() + (j - i) <= maxWidth) {
                wordsLen += words[j].size();
                j++;
            }

            int gaps = j - i - 1;

            // Last line OR line containing only one word
            if (j == n || gaps == 0) {
                string line;

                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += ' ';

                    line += words[k];
                }

                // Left justify
                line += string(maxWidth - line.size(), ' ');

                ans.push_back(line);
            }
            else {
                // Fully justify
                int totalSpaces = maxWidth - wordsLen;
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                string line;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int spaces = baseSpaces;

                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }

                ans.push_back(line);
            }

            i = j;
        }

        return ans;
    }
};