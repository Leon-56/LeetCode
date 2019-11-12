/*全排序
* 方法一：递归法，先固定一个字符，求剩余字符的全排序
* 
*/
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.empty()) return ans;
        Permutation(str, ans, 0);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    void Permutation(string str, vector<string>& ans, int begin)
    {
        if(begin == str.size() - 1)
        {
            if(find(ans.begin(), ans.end(), str) == ans.end())
                ans.push_back(str);
        }
        else
        {
            for(int i = begin; i < str.size(); i++)
            {
                swap(str[i], str[begin]);
                Permutation(str, ans, begin + 1);
                swap(str[i], str[begin]);
            }
        }
    }
    void swap(char& fir, char& sec)
    {
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};

//方法二：字典序全排序列
class Solution {
public:
    作者：yanyan090123
链接：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?f=discussion
来源：牛客网

vector<string> Permutation(string str) {
        vector<string> res;
        int len = str.length();
        if(len==0){
            return res;
        }else if(len==1){
            res.push_back(str);
            return res;
        }
        vector<char> char_list;
        int i,j;
        for(i=0;i<len;i++){
            char_list.push_back(str[i]);
        }
        sort(char_list.begin(),char_list.end());
        for(i=0;i<len;i++){
            str[i]  = char_list[i];
        }
        res.push_back(str);
        int left,right;
        char min_one;
        while(true){
            left=-1;
            for(j=len-1;j>=1;j--){
                if(str[j-1]<str[j]){
                    left = j-1;
                    break;
                }
            }
            
            if(left==-1){
                break;
            }
            min_one = str[left+1];
            right = left+1;
            for(j = left+2;j<len;j++){
                if(str[j]>str[left]&&str[j]<min_one){
                    min_one = str[j];
                    right = j;
                }
            }
            swap(str[left],str[right]);
            for(i =left+1,j=len-1;i<j;i++,j--){
                swap(str[i],str[j]);
                
            }
            res.push_back(str);
        }
        
        return res;
    }
    
    
};
};