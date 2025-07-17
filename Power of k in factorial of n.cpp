class Solution {
  public:
    int maxKPower(int n, int k) {
        // code here
        map<int, int> primeFactors;
        for (int i = 2; i * i <= k; i++) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            primeFactors[k]++;
        }

        // Step 2: For each prime, use Legendre's formula
        int res = INT_MAX;
        for (map<int, int>::iterator it = primeFactors.begin(); it != primeFactors.end(); ++it) {
            int p = it->first;
            int expInK = it->second;

            int powerInNFact = 0;
            int temp = n;
            while (temp) {
                powerInNFact += temp / p;
                temp /= p;
            }
            res = min(res, powerInNFact / expInK);
        }
        return res;
    }
};
