class Solution {
private:
    int mem[1001];
    //tells whether two strings have a successor-predecessor relationship
    //p->predecessor candidate
    //s->successor candidate
    bool isPred(string &p,string &s){
        //they can only differ by one insertion
        if(s.size()-p.size()!=1){
            return false;
        } else {
            int start=0;
            for(int i=0;i<s.size();i++){
                if(start==p.size()){
                    //if the insertion happens at the end then the start pointer will
                    //end one character before the i pointer
                    return i==s.size()-1;
                } else if(s[i]==p[start]){
                    start++;
                }
            }
            return start==p.size();
        }
    }
    int solve(vector<string>&words,int index){
        if(index==words.size()){
            return 0;
        } else if(mem[index]!=-1){
            return mem[index];
        } else {
            int ans=1;
            for(int next=index+1;next<words.size();next++){
                if(isPred(words[index],words[next])){
                    ans=max(ans,1+solve(words,next));
                }
            }
            return mem[index]=ans;
        }
    }
public:
    int longestStrChain(vector<string>& words) {
        //since the order of the words do not matter(as demonstrated in the second 
        //example given in the question) we will sort the array based on the size
        //of the words.
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        memset(mem,-1,sizeof(mem));
        int ans=0;
        for(int i=0;i<words.size();i++){
            ans=max(ans,solve(words,i));
        }
        return ans;
    }
};