# 原神琴谱播放器
**作者初二，空闲时间很少，只能在周末更新代码。C++语法比较烂，学的也比较浅。代码部分由ChatGPT编写（我会加标记）**
## 瞎扯
### 用法
可以把原神琴谱txt文件导入，自动播放谱子（在本软件内播放），在网上搜到的铺子不会出现“兴致勃勃打开原神发现是RickRoll”的情况（当然听个乐子也行）
### 起源
源于写物理作业时兴起的一个想法：如果音叉音调不同的话是不是可以用它组装一架琴？起名叫“音叉钢琴“
这简直是太酷了好吗！

然后就打算用C++写个控制代码，驱动一个舵机带锤子敲音叉发声，可以直接读谱演奏！更酷了好
吗！

但是觉得自己C++水平有限，而且没那么多时间，先从读谱演奏开始吧。这个东西的作用就是读谱然后播放音乐，写完了再继续写驱动硬件的程序。
## 原理
参考BV1tv4y1D7iW
