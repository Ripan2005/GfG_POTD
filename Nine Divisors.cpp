class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        long long limit = static_cast<long long>(sqrt(n)) + 1;
        std::vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;
        std::vector<long long> primes;
        
        for (long long i = 2; i <= limit; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (long long j = i * i; j <= limit; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        long long count = 0;
        
        // Case 1: p^8
        for (long long p : primes) {
            long long val = p * p * p * p * p * p * p * p; // p^8
            if (val <= n) {
                count++;
            } else {
                break;
            }
        }
        
        // Case 2: p^2 * q^2
        long long plen = primes.size();
        for (long long i = 0; i < plen; i++) {
            for (long long j = i + 1; j < plen; j++) {
                long long val = (primes[i] * primes[i]) * (primes[j] * primes[j]);
                if (val <= n) {
                    count++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};
