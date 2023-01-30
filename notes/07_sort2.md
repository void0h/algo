
# 归并与快速排序

归并和快速排序时间复杂度均为O(nlogn)，都采用了==分治思想==。

## 归并排序（Merge Sort）

对前后两部分分别排序，再将排好序的两部分合并在一起，这样整个数组就都有序了。


<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221224191515.png" width=500>
</center>

分治思想跟递归思想很像。分治算法一般都是用递归来实现的。分治是一种解决问题的处理思想，递归是一种编程技巧。

```
递推公式：
merge_sort(p…r) = merge(merge_sort(p…q), merge_sort(q+1…r))

终止条件：
p >= r 不用再继续分解
```

```
merge(A[p...r], A[p...q], A[q+1...r]) {
  var i := p，j := q+1，k := 0 // 初始化变量i, j, k
  var tmp := new array[0...r-p] // 申请一个大小跟A[p...r]一样的临时数组
  while i<=q AND j<=r do {
    if A[i] <= A[j] {
      tmp[k++] = A[i++] // i++等于i:=i+1
    } else {
      tmp[k++] = A[j++]
    }
  }
  
  // 判断哪个子数组中有剩余的数据
  var start := i，end := q
  if j<=r then start := j, end:=r
  
  // 将剩余的数据拷贝到临时数组tmp
  while start <= end do {
    tmp[k++] = A[start++]
  }
  
  // 将tmp中的数组拷贝回A[p...r]
  for i:=0 to r-p do {
    A[p+i] = tmp[i]
  }
}
```
利用==哨兵==简化编程=
哨兵方法: 
1. 先将要合并的两个放到tmpLeft和tmpRight数组,其中每个数组都多出一个位置放哨兵 
2. tmpLeft[leftSize] = int.MaxValue; tmpRight[rightSize] = int.MaxValue; 
3. 3.比较两个tmp数组,哪个小就放到原数组,使用哨兵不用再判断是否有剩下的有序数组。


**归并排序是一个稳定的排序算法。**

**归并排序的时间复杂度是多少？**
如果我们定义求解问题 a 的时间是 T(a)，求解问题 b、c 的时间分别是 T(b) 和 T( c)，那我们就可以得到这样的递推关系式：

T(a) = T(b) + T(c) + K

其中 K 等于将两个子问题 b、c 的结果合并成问题 a 的结果所消耗的时间。
**递归代码的时间复杂度也可以写成递推公式。**

*分析一下归并排序的时间复杂度：*
我们假设对 n 个元素进行归并排序需要的时间是 T(n)，那分解成两个子数组排序的时间都是 T(n/2)。我们知道，merge() 函数合并两个有序子数组的时间复杂度是 O(n)。所以，套用前面的公式，归并排序的时间复杂度的计算公式就是：

```
T(1) = C；   n=1时，只需要常量级的执行时间，所以表示为C。
T(n) = 2*T(n/2) + n； n>1


T(n) = 2*T(n/2) + n
     = 2*(2*T(n/4) + n/2) + n = 4*T(n/4) + 2*n
     = 4*(2*T(n/8) + n/4) + 2*n = 8*T(n/8) + 3*n
     = 8*(2*T(n/16) + n/8) + 3*n = 16*T(n/16) + 4*n
     ......
     = 2^k * T(n/2^k) + k * n
     ......
```
通过这样一步一步分解推导，我们可以得到 T(n) = 2^kT(n/2^k)+kn。当 T(n/2^k)=T(1) 时，也就是 n/2^k=1，我们得到 k=log2n 。我们将 k 值代入上面的公式，得到 T(n)=Cn+nlog2n 。如果我们用大 O 标记法来表示的话，T(n) 就等于 O(nlogn)。所以归并排序的时间复杂度是 O(nlogn)。
==不管是最好情况、最坏情况，还是平均情况，时间复杂度都是 **O(nlogn)**。==

**归并排序的空间复杂度**
归并排序的==时间复杂度==任何情况下都是 O(nlogn)，看起来非常优秀。（待会儿你会发现，即便是快速排序，最坏情况下，时间复杂度也是 O(n2)。）但是，归并排序并没有像快排那样，应用广泛，这是为什么呢？因为它有一个致命的“弱点”，那就是归并排序==不是原地排序算法==。

尽管每次合并操作都需要申请额外的内存空间，但在合并完成之后，临时开辟的内存空间就被释放掉了。在任意时刻，CPU 只会有一个函数在执行，也就只会有一个临时的内存空间在使用。临时内存空间最大也不会超过 n 个数据的大小，所以==空间复杂度是 O(n)。==

# 快速排序（Quicksort）

快排的思想是这样的：如果要排序数组中下标从 p 到 r 之间的一组数据，我们选择 p 到 r 之间的任意一个数据作为 pivot（分区点）。

我们遍历 p 到 r 之间的数据，将小于 pivot 的放到左边，将大于 pivot 的放到右边，将 pivot 放到中间。

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221226204946.png" width=500>
</center>

根据分治、递归的处理思想，我们可以用递归排序下标从 p 到 q-1 之间的数据和下标从 q+1 到 r 之间的数据，直到==区间缩小为 1==，就说明所有的数据都==有序==了。
```
递推公式：
quick_sort(p…r) = quick_sort(p…q-1) + quick_sort(q+1… r)

终止条件：
p >= r
```
<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221226205204.png" width=500>
</center>

如果按照==这种思路==实现的话，需要很多==额外的内存空间==，所以快排就==不是原地==排序算法了。

如果我们希望快排是==原地排序==算法，那它的空间复杂度得是 ==O(1)==。原地分区函数的实现思路非常巧妙：
```
int partition(int *arr, int p, int r)
{
	//int pivot = arr[r];
	int i, j;

	i = j = p;

	for (; j < r; j++) {
		if (arr[j] < arr[r]) {
			if(i != j)
			{
			swap(arr + i, arr + j);

			}
			i++;
		}
	}
	
	swap(arr + i, arr + r);
	return i;
}

```
数组的插入操作还记得吗？在数组某个位置插入元素，需要搬移数据，非常耗时。当时我们也讲了一种处理技巧，就是==交换==，在 O(1) 的时间复杂度内完成插入操作。这里我们也借助这个思想，只需要将 A[i]与 A[j]交换，就可以在 O(1) 时间复杂度内将 A[j]放到下标为 i 的位置。
<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221226210455.png" width=500>
</center>

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221226210334.png" width=500>
</center>

## 快速排序的性能分析

==快排是一种原地、不稳定的排序算法==。

==如果每次分区==操作，都能正好把数组分成大小接近==相等==的两个小区间，那快排的时间复杂度递推求解公式跟归并是相同的。所以，快排的时间复杂度也==是 O(nlogn)。==

==**实际上这种情况是很难实现的。**==
如果数组中的数据原来已经是有序了，如果我们每次选择最后一个元素作为 pivot，我们需要进行大约 n 次分区操作，每次分区我们平均要扫描大约 n/2 个元素，快排的时间复杂度就从 O(nlogn) ==退化成了 O(n2)==。

可以找==中位数==来作为pivot解决这个问题。

