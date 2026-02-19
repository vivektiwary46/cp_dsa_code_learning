//This is for Longest Common Subsequence
//SEE THE CODE HERE : https://www.naukri.com/code360/problems/longest-common-subsequence_1063255?leftPanelTabValue=SUBMISSION
//OR HERE https://leetcode.com/problems/longest-common-subsequence/submissions/1688456644/
//Can watch from DP 25 and 26 from striver.

//below code should be used to print the lcs, with tc : O(s + t) in worst case.
////Use this code to print the lcs by backtracking
    //int i = s, j = t;
    //int len = dp[s][t];
    //string ans = "";
    //for (int i = 0; i < len; i++)
    //{
    //    ans += '$';
    //}
    //int index = len - 1;
    //while(i > 0 && j > 0)
    //{
    //    if (str1[i-1] == str2[j-1]) 
    //    {
    //        ans[index] = str1[i-1];
    //        index--;
    //        i --; j--;
    //    }
    //    else if (dp[i-1][j] > dp[i][j-1]) {i--;}
    //    else {j--;}
    //}
    //}