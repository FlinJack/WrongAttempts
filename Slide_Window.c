// 贝茜参加某编程比赛。

// 比赛一共有 n道题，编号 1∼n，其中第 i题需要她花费 ai时间方可完成。

// 贝茜可以自由选择从某一道题开始（前面的题相当于全部放弃），按编号顺序依次答题，每完成一题才会作答下一题，直到完成最后一题或比赛时间结束为止。

// 本次比赛的持续时间为 t，请你计算贝茜最多可以完成多少题。

// 输入格式第一行包含整数 n,t。

// 第二行包含 n 个整数 a1,a2,…,an。

// 输出格式 一个整数，表示最多可以完成的题目数量。

// 数据范围前 6个测试点满足 1≤n≤6。
// 所有测试点满足 1≤n≤105，1≤t≤109，1≤ai≤10。
#include <stdio.h>

int main(void) {
    int n, t;
    scanf("%d %d", &n, &t);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = 0, sum = 0, maxLength = 0;

    while (right < n) {
        sum += arr[right];  // 扩展窗口，加入 arr[right]
        
        // 当窗口和超过 t 时，收缩窗口
        while (sum > t && left <= right) {
            sum -= arr[left];
            left++;
        }

        // 计算当前窗口的长度
        maxLength = (right - left + 1 > maxLength) ? (right - left + 1) : maxLength;

        right++;  // 继续扩展窗口
    }

    printf("%d", maxLength);  // 输出结果
    return 0;
}
