package main

func longestPalindrome(s string) string {
	var dp [1000][1000]bool
	if len(s)==0 {
		return ""
	}
	maxLen := 1
	start :=0
	for i:=0;i<len(s);i++ {
		dp[i][i]=true
		for j:=0;j<i;j++ {
			dp[j][i] = (i-j==1 && s[j]==s[i]) || (s[j]==s[i] && dp[j+1][i-1])
			if dp[j][i] && maxLen<(i-j+1) {
				maxLen = i-j+1
				start = j
			}
		}
	}
	return s[start:start+maxLen]
}



func init() {
	testList = append(testList,TestEntry{"005_longest_palindromic_substr",func (){
		{
			println(longestPalindrome("")=="")
			println(longestPalindrome("a")=="a")
		}
	}})
}
