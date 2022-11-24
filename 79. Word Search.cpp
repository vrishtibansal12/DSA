class Solution {
public:
    bool help(int i,int j,int n, int m,vector<vector<char>>& board, string word,int index){
        if(index==word.size())
            return true;
        if(i<0 || j<0 || i==n || j==m )
            return false;
        if(board[i][j]=='0')
            return false;
        
        if(board[i][j]==word[index]){
            char temp=board[i][j];
            board[i][j]='0';
            return help(i+1,j,n,m,board,word,index+1) || help(i,j+1,n,m,board,word,index+1) || help(i-1,j,n,m,board,word,index+1) || help(i,j-1,n,m,board,word,index+1);
            if(help(i+1,j,n,m,board,word,index+1))
                return true;
            if(help(i,j+1,n,m,board,word,index+1))
                return true;
            if(help(i-1,j,n,m,board,word,index+1))
                return true;
            if(help(i,j-1,n,m,board,word,index+1))
                return true;
            board[i][j]=temp;
        }
        return false;
    
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool result= false;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]==word[0])
                    if(help(i,j,n,m,board,word,0))
                        return true;

        return false;
    }
};