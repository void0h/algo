# 排序

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221213221740.png" width=500>
</center>

为什么插入排序要比冒泡排序更受欢迎呢？

冒泡排序不管怎么优化，元素交换的次数是一个固定值，是原始数据的逆序度。==插入排序==是同样的，不管怎么优化，元素==移动的次数==也等于原始数据的==逆序度==。从代码实现上来看，冒泡排序的数据交换要比插入排序的数据移动要复杂。

## 如何分析一个“排序算法”？

### <font color = orange>排序算法的执行效率 </font>

一般会从这几个方面来衡量：

**1. 最好情况、最坏情况、平均情况时间复杂度**

因为有序度不同的数据，对于排序的执行时间肯定是有影响的。

**2. 时间复杂度的系数、常数 、低阶**

==小规模==数据需要考虑系数、常数、低阶。

**3. 比较次数和交换（或移动）次数**

### <font color = orange>排序算法的内存消耗</font>

算法的内存消耗可以通过空间复杂度来衡量。==原地排序==算法，就是特指空间复杂度是 ==O(1)== 的排序算法。

### <font color = orange>排序算法的稳定性</font>
==稳定性==。这个概念是说，如果待排序的序列中存在值相等的元素，经过排序之后，==相等元素==之间原有的先后==顺序不变==。

## 冒泡排序（Bubble Sort）

冒泡排序只会操作相邻的两个数据。每次冒泡操作都会对相邻的两个元素进行比较，看是否满足大小关系要求。如果不满足就让它俩互换。一次冒泡会让至少一个元素移动到它应该在的位置，重复 n 次，就完成了 n 个数据的排序工作。
<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221213184525.png" width=500>
</center>

==空间复杂度为 O(1)==，是一个==原地==排序算法，是稳定的排序算法。最好情况时间复杂度是 O(n)，所以最坏情况==时间复杂度为 O(n2)==。
<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221213184922.png" width=500>
</center>

## 插入排序（Insertion Sort）

插入算法的核心思想是取未排序区间中的元素，在已排序区间中找到合适的插入位置将其插入，并保证已排序区间数据一直有序。重复这个过程，直到未排序区间中元素为空，算法结束。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221213211848.png" width=500>
</center>

对于一个给定的初始序列，**移动**操作的**次数**总是固定的，就**等于逆序度**。为什么说移动次数就等于逆序度呢？我拿刚才的例子画了一个图表，你一看就明白了。**满有序度**是 ==n*(n-1)/2===15，**初始序列的有序度**是 5，所以**逆序度**是 10。插入排序中，数据移动的个数总和也等于 10=3+3+4。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221213214815.png" width=500>
</center>


插入排序是==原地==和==稳定==的排序算法，最好（有序）是时间复杂度为 O(n)，最坏情况时间复杂度为 O(n2)。

## 选择排序（Selection Sort）

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221213221849.png" width=500>
</center>
