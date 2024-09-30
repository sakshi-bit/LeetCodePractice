class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        int n = nums2.length;
        int nge2[] = new int[n];

        Stack<Integer> s = new Stack<Integer>();

        for(int i=n-1;i>=0;i--){
            while(!s.isEmpty() && s.peek()<=nums2[i]){
                s.pop();
            }
            if(s.isEmpty()){
                nge2[i] = -1;
            }else{
                nge2[i] = s.peek();
            }
            s.push(nums2[i]);
        }

        Map<Integer,Integer> mpp = new HashMap<>();

        for(int i=0;i<n;i++){
            mpp.put(nums2[i],i);
        }
        int m = nums1.length;
        int nge1[] = new int[m];
        
        for(int i=0;i<m;i++){
            int idx = nums1[i];
            int idxToFind = mpp.get(idx);
            nge1[i] = nge2[idxToFind];
        }

        return nge1;
        
    }
}
