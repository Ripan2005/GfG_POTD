Count the number of possible triangles


// Java Code : 

class Solution {
    public int countTriangles(int arr[]) {
        // code here
        int n = arr.length;
        if (n < 3) return 0;
        
        Arrays.sort(arr);
        int res = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            
            while (i < j) {
                
                if (arr[i] + arr[j] > arr[k]) {
                    res += (j - i);
                    j--;
                } else i++;
                
            }
        }
        
        return res;
    }
}




// C++ Code : 

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        sort(arr.begin(), arr.end());
        int res = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    res += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return res;
    }
};
