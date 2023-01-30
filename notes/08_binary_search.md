# 二分查找

二分查找针对的是一个==有序==的数据集合，查找思想有点类似分治思想。每次都通过跟区间的==中间元素==对比，将待查找的区间缩小为之前的一半，直到找到要查找的元素，或者区间被缩小为 0。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20230103221402.png" width=500>
</center>

这是一个等比数列。其中 ==n/2k=1== 时，k 的值就是总共缩小的次数。经过了 ==k 次区间缩小==操作，时间复杂度就是 O(k)。通过 ==n/2k=1==，我们可以求得 ==k=log2n==，所以时间复杂度就是 ==O(logn)==。

