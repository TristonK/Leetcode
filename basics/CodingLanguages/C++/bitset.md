> C++ Primer 17.2

# bitset类型

定义在头文件bitset中
置位：1，复位：0

## 定义与初始化bitset
<!img src="pic/bitset1.png">

利用unsigned值初始化bitset时，如果unsigned值比位数高，则其高位被丢弃，若小则高位被置为0.
使用一个string或者字符数组指针来初始化bitset时，**值得注意的是string的高位在bitset中是低位**


## bitset操作
<!img src="pic/bitset1.png">

使用cin输入流读入时，保存到一个临时的string对象中，当读取到对应的bitset大小，或者遇到不是0或1的字符时，或者遇到文件尾或者输入错误时，读取过程才停止，用临时的string对象来初始化bitset。
使用to_ulong或者to_ullong时，只有**bitset大小等于对应的大小**的时候，才能使用这两个操作，否则抛出overflow_error异常。
