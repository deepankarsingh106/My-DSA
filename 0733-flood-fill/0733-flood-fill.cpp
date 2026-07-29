class Solution {
private:
    bool isValid(int &x,int &y,int &n,int &m,vector<vector<int>>& image,int need){
        if(x >=0 && y >= 0 && x < n && y < m && image[x][y] == need){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        
        int m = image[0].size();

        queue<pair<int,int>> q;

        q.push({sr,sc});
        int need = image[sr][sc];
        if(need == color){
            return image;
        }
        image[sr][sc] = color;
            while(!q.empty()){
                int rox = q.front().first;
                int roy = q.front().second;
                q.pop();
        
                
                // down
                int x = rox + 1;
                int y = roy;
                if(isValid(x,y,n,m,image,need)){
                    image[x][y] = color;
                    q.push({x,y});
                }
                
                // up
                x = rox - 1;
                y = roy;
                if(isValid(x,y,n,m,image,need)){
                    image[x][y] = color;
                    q.push({x,y});
                }
                
                
                // left
                x = rox;
                y = roy-1;
                if(isValid(x,y,n,m,image,need)){
                    image[x][y] = color;
                    q.push({x,y});
                }


                // right
                x = rox;
                y = roy+1;
                if(isValid(x,y,n,m,image,need)){
                    image[x][y] = color;
                    q.push({x,y});
                }
            }
    return image;
    }
};