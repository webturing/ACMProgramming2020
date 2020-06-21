# 算法学习入门经典：最大子序列五种解法

## O(n^3) 暴力

- 思路最直观
- 效率最低
```cpp
int max_sub_cube(vector<int> &v) {//O(n^3)
    int best = 0, n = int(v.size());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += v[k];
            }
            best = max(best, s);
        }
    return best;
}
```
## O(n^2) 前缀和
- 预处理
- O(1)计算子区间
- 一个思路误区：前缀和中最大减最小不就是能O(n)求解么？
```cpp
int max_sub_square(vector<int> &v) {//O(n^2)
    vector<int> b(v);
    partial_sum(b.begin(), b.end(), b.begin());//O(n)
    int best = 0, n = int(v.size());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int s = i > 0 ? b[j] - b[i - 1] : b[j];
            best = max(best, s);
        }
    return best;
}
```
## O(n) 动态规划
- 动态规划的状态刻画：dp[i]以a[i]结尾的序列
- 第一种a[i]不是开头 序列延伸 dp[i]=dp[i-1]+a[i]
- 第二种另立门户 a[i]也是开头 dp[i]=a[i];
- 初始条件显然是dp[0]=a[0]
- dp的最大值就是答案，非常清晰明了
```cpp
int max_sub_linear_dp(vector<int> &v) {//O(n)
    vector<int> dp(v.size());
    dp[0] = v[0];
    for (auto i = 1; i < v.size(); i++) {
        dp[i] = max(dp[i] + v[i], v[i]);
    }
    return *max_element(dp.begin(), dp.end());
}
```
## O(n) 贪心
- 贪心规则：
- 任何序列不可能开始于一个负数，否则放弃这个负数得到的解最大
- 其他的相当于对dp的空间进行压缩

```cpp
int max_sub_linear_greedy(vector<int> &v) {//O(n)
    int best(0), local(0);
    for (auto i = 0; i < v.size(); i++) {
        local += v[i];
        if (local < 0) {
            local = 0;
        }
        best = max(best, local);
    }
    return best;
}
```



## O(nlogn) 二分
- 递归第一步参数化 f(a,left,right) //闭区间好写程序

- 边界 left=right 显然是a[left]
- 否则二分 中点是mid=(left+right)/2;
- 三种情况：求最大值就可以了
1 左半部分 f(a,left,mid) 递归求解
2 有半部分 f(a,mid+1,right) 递归求解
3 中点属于这个区间（连续），我们从mid向左，向右把贪心思想重做一遍

```cpp
int max_sub_dc(vector<int> &v, int left, int right) {//O(nlog(n))
    if (left == right) return v[left];
    int mid = (left + right) / 2;
    int max_left = max_sub_dc(v, left, mid);
    int max_right = max_sub_dc(v, mid + 1, right);
    int max_cross_left(0), max_cross_right(0), sum_left(0), sum_right(0);
    for (int i = mid; i >= left; i--) {
        sum_left += v[i];
        max_cross_left = max(sum_left, max_cross_left);
    }
    for (int i = mid + 1; i <= right; i++) {
        sum_right += v[i];
        max_cross_right = max(sum_right, max_cross_right);
    }

    return max(max(max_left, max_right), max_cross_left + max_cross_right);
}
```



# 扩展：
- 边界问题：全负返回0还是第一个的绝对值最小的负数 best初始化为INT_MIN即可
- 不仅需要值，还要有区间（多参数传递）
- 二维扩展：最大子矩阵