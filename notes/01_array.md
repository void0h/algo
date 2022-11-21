[toc]

# 数组

**数组（Array）是一种==线性表==数据结构。它用一组==连续的内存空间==，来存储一组具有==相同类型==的数据。**

<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221127002000.png" width=300> &ensp;&ensp;<img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="https://raw.githubusercontent.com/hongguangli/Figures/main/20221127002110.png" width=300 align="top">
</center>

<br>

**​寻址公式 :​**
> a[k]_address = base_address + k * type_size

&emsp;&emsp;如果数组从 1 开始计数，那我们计算数组元素 a[k]的内存地址就会变为：
> a[k]_address = base_address + ==(k-1)==*type_size

&emsp;&emsp;从 1 开始编号，每次随机访问数组元素都多了一次减法运算，对于 CPU 来说，就是多了一次减法指令。
&emsp;&emsp;所以为了减少一次减法操作，数组选择了从 0 开始编号，而不是从 1 开始。
不过我认为，上面解释得再多其实都算不上压倒性的证明，说数组起始编号非 0 开始不可。所以我觉得最主要的原因可能是历史原因。