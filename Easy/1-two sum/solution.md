# Two sums
    拖了这么久，终于也开始写leetcode了，每天尽量做吧，保持保持手感（说的之前有一样）。 
### 题目大意
    给一个数组和一个目标数，在数组里面找到两个数使得这两个数的和等于目标数
### 很基础但是不熟悉的操作
    1.vector的sort
        就是平时用的sort(vector.begin(),vector.end(),bool function);
    2.map
    C++中map提供的是一种键值对容器，里面的数据都是成对出现的,如下图：每一对中的第一个值称之为关键字(key)，每个关键字只能在map中出现一次；第二个称之为该关键字的对应值。
    Map中元素取值主要有at和[ ]两种操作，at会作下标检查，而[]不会。
### 完全的新东西
    1.cin的加速
    > 参考: https://blog.csdn.net/qq_32320399/article/details/81518476
    在leetcode的排名前列的代码中常有以下操作：
    > static int lambda_0 = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
    1)首先先说一下这个语法
        static const auto io_sync_off = [](){
            ... ...
        }();
    这个乍一看很像是函数，但是前后又是[]又是()的，还没函数名没返回值的，这个是Lambda捕获。Lambda表达式是C++11引入的特性，是一种描述函数对象的机制，它的主要应用是描述某些具有简单行为的函数。Lambda也可以称为匿名函数。
    2) 函数std :: ios_base :: sync_with_stdio的解释是 Sets whether the standard C++ streams are synchronized to the standard C streams after each input/output operation. 设置在每次输入/输出操作后标准C ++流是否与标准C流同步
    因为C++中的std :: cin和std :: cout为了兼容C，保证在代码中同时出现std :: cin和scanf或std :: cout和printf时输出不发生混乱，所以C++用一个流缓冲区来同步C的标准流。通过std :: ios_base :: sync_with_stdio函数可以解除这种同步，让std :: cin和std :: cout不再经过缓冲区，自然就节省了许多时间。
    3)std :: cin默认是与std :: cout绑定的，所以每次操作的时候（也就是调用”<<”或者”>>”）都要刷新（调用flush），这样增加了IO的负担，通过tie(nullptr)来解除std :: cin和std :: cout之间的绑定，来降低IO的负担使效率提升。
    4)使用std::ios::sync_with_stdio(false)和std::cin.tie(nullptr)之后要避免和scanf和printf混用以避免出现问题。
### 解法    
    1.爆搜（96ms）
    2.利用hash表，map数据结构
        
