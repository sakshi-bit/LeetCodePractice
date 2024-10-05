
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

Approach 2 : Monotonic Stack
O(n)
O(n)

    class Solution {
    public int trap(int[] height) {

        int n = height.length;
        int water = 0;

        Stack<Integer> stack = new Stack<>();

        for(int right=0;right<n;right++){
            while(!stack.isEmpty() && height[stack.peek()] < height[right]){

                int mid = stack.pop();

                if(stack.isEmpty()){
                    break;
                }
                int left = stack.peek();
                int minHeight = Math.min((height[right]-height[mid]),height[left]-height[mid]);
                int width = right-left-1;
                water+=minHeight*width;
            }
            stack.push(right);
        }
        return water;   
    }
}
