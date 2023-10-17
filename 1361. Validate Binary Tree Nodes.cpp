class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false; 
                }
            }

            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false; 
                }
            }
        }

        int rootCount = 0;
        int rootCandidate = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                rootCount++;
                if (rootCount > 1) {
                    return false; 
                }
                rootCandidate = i;
            }
        }

        if (rootCount == 0) {
            return false; 
        }

        if (rootCount == 1) {
            return isConnected(n, leftChild, rightChild, rootCandidate);
        }

        return false;
    }

    bool isConnected(int n, vector<int>& leftChild, vector<int>& rightChild, int root) {
        vector<bool> visited(n, false);
        stack<int> dfs;
        dfs.push(root);

        while (!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();

            if (visited[node]) {
                return false; 
            }

            visited[node] = true;

            if (leftChild[node] != -1) {
                dfs.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                dfs.push(rightChild[node]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false; 
            }
        }

        return true;
    }
};
