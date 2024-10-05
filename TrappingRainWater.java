
Approach 1
O(n)
O(n)

class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int water = 0;

        int[] l_max = new int[n];
        int[] r_max = new int[n];

        l_max[0] = height[0];

        for(int i=1;i<n;i++){
            l_max[i] = Math.max(height[i],l_max[i-1]);
        }

        r_max[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            r_max[i] = Math.max(height[i],r_max[i+1]);
        }

        for(int i=1;i<n-1;i++){
            water+= Math.min(r_max[i],l_max[i])-height[i];
        }

        return water;
    }
}
