// two Pointers Approach
class Solution {
    public int trap(int[] height) {
        
        int[] pre = new int[height.length];
        int[] suf = new int[height.length];

        pre[0] = height[0];
        suf[suf.length - 1] = height[height.length - 1];

        for (int i = 1; i < pre.length; i++) {
            pre[i] = Math.max(height[i], pre[i - 1]);
        }

        for (int i = suf.length - 2; i >= 0; i--) {
            suf[i] = Math.max(height[i], suf[i+1]);
        }

        int maxRain = 0;

        for (int i = 0; i < height.length; i++) {
            maxRain += Math.min(pre[i], suf[i]) - height[i];
        }
        return maxRain;
    }
}
