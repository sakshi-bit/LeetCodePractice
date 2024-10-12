class Solution {
    public int kthGrammar(int n, int k) {

        // base condition
        if (k == 1 && n == 1) {
            return 0;
        }

        int mid = (int) Math.pow(2, n - 1) / 2;

        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {

            // When kthGrammar(n-1, k-mid) returns 0, doing 1 - 0 gives 1, which flips it to
            // 1.
            // When kthGrammar(n-1, k-mid) returns 1, doing 1 - 1 gives 0, which flips it to
            // 0.
            return (kthGrammar(n - 1, k - mid)) == 0 ? 1 : 0;
        }

    }
}
