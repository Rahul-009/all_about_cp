// Leetcode 
// Problem => Merge Strings Alternately
// Link => https://leetcode.com/problems/merge-strings-alternately/description/


//solution 1
string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        string temp = "";

        if (len1 > len2){
            int i = 0;
            for(i=0; i<len2; i++){
                temp += word1[i];
                temp += word2[i];
            }
            
            for(int j = i; j<len1; j++){
                temp += word1[j];
            }
        }else if(len1 == len2){
            int i = 0;
            for(i=0; i<len2; i++){
                temp += word1[i];
                temp += word2[i];
            }
        }else{
            int i = 0;
            for(i=0; i<len1; i++){
                temp += word1[i];
                temp += word2[i];
            }

            for(int j = i; j<len2; j++){
                temp += word2[j];
            }
        }

        return temp;
    }

// solution 2