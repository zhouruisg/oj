//
// Created by rui zhou on 01/04/18.
//

/*
 * https://leetcode.com/contest/weekly-contest-78/problems/expressive-words/
 * Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy.

Example:
Input:
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation:
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters

 */

/*
 * class Solution {
	vector<pair<char, int>> process(string s) {
		vector<pair<char, int>> ans;
		int i, j;
		for (i = 0; i < s.length(); i++) {
			for (j = i; (j < s.length()) && (s[i] == s[j]); j++);
			ans.push_back({ s[i], j - i });
			i = j - 1;
		}
		return ans;
	}

	bool compatible(vector<pair<char, int>> a, vector<pair<char, int>> b) {
		if (a.size() != b.size()) return false;
		for (int i = 0; i < a.size(); i++) {
			if (a[i].first != b[i].first) return false;
			if ((a[i].second >= 3) && (b[i].second <= a[i].second)) continue;
			if (a[i].second == b[i].second) continue;
			return false;
		}
		return true;
	}
public:
	int expressiveWords(string s, vector<string>& words) {
		vector<pair<char, int>> a, b;
		int i, j, k, ct = 0;

		a = process(s);
		for (auto ss : words) {
			b = process(ss);

			if (compatible(a, b)) ct++;
		}
		return ct;
	}
};
 */
#include <codech/codech_def.h>

using namespace std;

void pvs(vector<string> &vs) {
    for (auto &ss:vs) {
        cout << ss << endl;
    }
}
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if (S.length()==0)
            return 0;
        vector<string> ext;
        char prev = S[0];
        int begin = 0;
        for (int i=1;i<S.length();i++) {
            if (S[i]!=prev) {
                ext.push_back(S.substr(begin, i-begin));
                prev = S[i];
                begin = i;
            }
        }
        ext.push_back(S.substr(begin));
        //pvs(ext);
        int count=0;
        for (auto &w: words) {
            char prev = w[0];
            int begin = 0;
            bool comp = true;
            int idx = 0;
            for (int i=0;i<w.length();i++) {
                if (w[i]!=prev ) {
                    string ck = w.substr(begin, i-begin);
                    prev = w[i];
                    begin = i;

                    if (ck[0] != ext[idx][0]) {
                        comp = false;
                        break;
                    }
                    if (ext[idx].length() != ck.length() && ext[idx].length() - ck.length() <2) {
                        comp = false;
                        break;
                    }
                    idx++;
                }
            }

            if (begin==w.length()-1) {
                string ck = w.substr(begin);
                if (ck[0] != ext[idx][0]) {
                    comp = false;
                }
                if (ext[idx].length() != ck.length() && ext[idx].length() - ck.length() <2) {
                    comp = false;
                }
                idx++;
            }


            if (idx>=ext.size())
                count++;
        }
        return count;
    }
};


DEFINE_CODE_TEST(809_expressive_word)
{
    Solution obj;
    {
        vector<string> words{"zzyy","zy","zyy"};
        cout << obj.expressiveWords("zzzzzyyyyy", words);
    }
    /*
    {
        vector<string> words{"abc"};
        cout <<obj.expressiveWords("abcd",words);
    }
    {
        vector<string> words{"hello", "hi", "helo"};
        cout <<obj.expressiveWords("heeellooo",words);
    }*/

}