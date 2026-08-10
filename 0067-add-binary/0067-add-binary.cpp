class Solution {
public:
    string addBinary(string a, string b) {
        char ans='0';
        string result = "";
        int n = a.length()-1;
        int m = b.length()-1;
        int i = n;
        int j = m;
        while(i>=0 && j>=0){
            if(a[i]=='0' && b[j]=='0'){
                if(ans=='1') {
                    result += '1';
                    ans='0';
                }
                else result += '0';
            }
            else if(a[i]=='1' && b[j]=='0' || a[i]=='0' && b[j]=='1') {
                if(ans=='1'){
                    result+='0';
                    ans='1';
                }
                else result+='1';
            }
            else{
                if(ans=='1') result += '1';
                else result += '0';
                ans = '1';
            }
            i--;
            j--;
        }
        if(i>=0){
            while(i>=0) {
                if(ans=='1' && a[i]=='1') {
                    result += '0';
                    ans = '1';
                }
                else{
                    if(ans=='1'&& a[i]=='0') result += '1';
                    else result += a[i];
                    ans='0';
                }
                i--;
            }
        }
        if(j>=0){
            while(j>=0){
                if(ans=='1' && b[j]=='1') {
                    result += '0';
                    ans = '1';
                }
                else{
                    if(ans=='1'&&b[j]=='0')result += '1';
                    else result += b[j];
                    ans='0';
                }
                j--;
            }
        }
        if(ans == '1')  result += '1';
        reverse(result.begin(),result.end());
        return result;
    }
};