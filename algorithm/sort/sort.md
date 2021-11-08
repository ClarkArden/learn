# 排序算法

##  冒泡排序

### 说明
从上到下比较相邻的两个元素，若上面的一个元素比下面的一个元素大，就交换两个元素的位置，每排一次，就能确定一个极值，所以第一次比较N-1次，第二次比较N-2次，第三次比较N-3次，...

###  代码

```
void Bubble_Sort(ElementType A[],int N)
{
    for(int  P=N-1; P>0; P--)
    {
        int flag = 0
        for (int i=0; i<P;i++)  //一趟冒泡
        {
            if (A[i]>A[i+1])
                swap(A[i],A[i+1])
                flag = 1
        }
        if(flag==0)
            break

    }
}
```


## 插入排序

### 说明
先选两张牌进行比较，然后摸第三张牌与前面的两张牌进行依次比较，若比第一张牌大比第二张牌小就先移动后插入到前面两张牌中间，然后第四张牌，第五张牌;(类比打牌摸牌的过程)

### 代码
```
void Insertion_Sort(ElementType A[],int N)
{
    for(int P=1;p<N;P++)
    {
        int temp = A[P];        //摸下一张牌
        for(int i=P;i>0 && temp<A[i-1];i--) //从后往前比较
        {
            A[i] = A[i-1]; //移出空位
        }
        A[i] = temp;   //新牌落位
        
    }
} 
```
## 希尔排序

### 说明
首先确定增量序列根据每个增量间隔进行插入排序，需要注意增量间隔需要互质，Hibbard增量序列$D_k=2^k-1$;Sedgewick增量序列，$4^i-3*2^i+1$

### 代码
```
void Shell_Sort(ElementType A[],int N)
{
    for(int D=N/2;D>0;D/=2)
    {
        for(int P=D;P<N;P++)
        {
            int temp = A[P];
            for(int i=P;i>=D && temp<A[i-D];i-=D)       // i必须可以等于D
            {
                A[i]=A[i-D];
            }
            A[i]=temp;
        }
    }
}
```

## 选择排序

### 说明

每次寻找序列中最小或者最大的元素放在前面有序序列的后面。

### 代码

```
void Selection_Sort(ElementType A[],int N)
{
    int min;
    for(int i=0 ; i<N ; i++)
    {
        min = i;
        for(int j=i+1;j<N;j++)
        {
            if(A[min]>A[j])
                min = j;
        }

        if(i!=min)
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}
```

## 堆排序

### 说明
* 首先构建最大堆或者最小堆
* 将根结点与最后一个结点进行交换
* 砍掉最后一个结点，重新调整为最大堆；然后继续交换+调整

### $注^*$
1. 首次进行构建最大堆的时候，从第一个非叶子结点开始调整
2. 第一个非叶子节点坐标为：$N/2-1$
3. 交换后调整堆，从根节点调整

## 代码

```
void Heap_Sort(ElementType A[], int N)
{
    // 1. 构建最大堆
    for(int i = N/2-1; i >= 0 ; i--)
    {
        adjustHeap(A , i , N);      // 从第一个非叶子节点从右到左，从下到上调整
    }

    // 2. 交换第一个节点和最后一个节点 + 调整最大堆
    for(int j = N-1 ; j > 0 ; j--)
    {
        swap(A , 0 , j);        // 将堆顶元素与末尾元素进行交换
        adjustHeap(A , 0 , N);  //重新对堆进行调整
    }
}

void adjustHeap(Elementtype A[], int i , int N)
{
    int temp = A[i];
    for(int k = 2*i + 1 ; k < N ; k = 2*k +1) //
    从i结点的左子结点开始，也就是2i+1处开始
    {
        if(k++ < N && A[k] < A[k+1])  // 如果左子结点小于右子结点，k指向右子结点
        {
            k++;
        }

        if(A[k]>temp)  //  如果子节点大于父节点，将子节点值赋值给父节点
        {
            A[i] = A[k];      //将子结点的值给顶点形成顶点为最大的
            i = k;            // 交换最大的与小的坐标，方便下面给小的赋值
        }else{
            break;
        }
    }
    A[i] = temp;
    
}

void Swap(ElementType A[] , int i , int j)
{
    int temp  = A[i];
    A[i] = A[j];
    A[j] = temp;
}
```


## 归并排序
### 说明

两个有序的子序列比较，如果某个子序列的最前面的子序列小，就把次元素放入到临时数值中，就形成了有序序列

### 递归代码
```
/* L= 左边起始位置  R= 右边起始位置 ， RightEnd= 右边终点位置*/
void Merge(vector<int> &A, int tempA[], int L, int R, int RightEnd )
{
    int LeftEnd = R - 1;
    int tmp = L;
    int NumsEle = RightEnd - L + 1;
    while(L<= LeftEnd && R <= RightEnd)
    {
        if(A[L] <= A[R])   //左边第一个元素更小
        {
            tempA[tmp++] = A[L++];
        }else{              //右边第一个元素最小
            tempA[tmp++] = A[R++];
        }
    }

    while(L<= LeftEnd)  //直接复制左边剩余的元素
    {
        tempA[tmp++] = A[L++];
    }

    while(R <= RightEnd)  //直接复制左边剩余的元素
    {
        tempA[tmp++] = A[R++];
    }

    for(int i = 0; i<NumsEle; i++ , RightEnd--)
        A[RightEnd] = tempA[RightEnd];
}

void MSort(vector<int> &A, int tempA[], int L, int RightEnd)
{
    //如果只有一个元素就不需要划分
    int Center;
    if(L < RightEnd)
    {
        Center = (L + RightEnd) / 2;  //找中间点
        MSort(A ,tempA, L, Center);          //递归划分左半区
        MSort(A ,tempA, Center+1, RightEnd);  //递归划分右半区
        Merge(A ,tempA, L, Center+1, RightEnd);  //合并已经排序的序列
    }
}

void Merge_Sort(vector<int> A) // 在这里创建临时数组，节省内存开销，因为以后的temp都是在递归李使用的。
{
    int N = A.size();
    int *tempA = new int[N-1];

    MSort(A, 0, N-1);
    delete tempA[];
}
```

## 快速排序
### 说明
选取最后一个元素为枢纽元素(pivot),第一个元素的指针为i,倒数第二个元素的指针设为j,指针i往后移动，指针
j往前移动，当指针i指向的元素大于枢纽元素时指针i停止移动，当指针j指向的元素小于枢纽元素时j指正停止移动，然后判断i和j的大小，若$i<j$,就交换i指针指向的元素和j指针指向的元素；若i>j,跳出本次遍历，然后就交换i指向的元素和枢纽元素(pivot)。

```
int partition(vector<int> &A, int low, int high){
    int i = low - 1;
    int j = high;
    int pivot = A[high];
    while(1){
        while(A[++i]<pivot);
        while(A[--j]>pivot);
        if(i < j){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }else{
            break;
        }
    }
    swap(A[i],A[high]);

    return i;

}

void QSort(vector<int> &A, int low，int high){
    if(low<high){
        int mid = partition(A,low, high);
        QSort(A, low, mid - 1); //因为mid已经排好序了，所以此处的high= mid-1
        QSort(A, mid + 1, high); //mid+1 同上
    }
}

void Quick_Sort(vector &A){
    int N = A.size();
    QSort(A,0,N-1);
}
```
## 计算排序
### 说明
1. 找出最大值和最小值，min和max
2. 创建max-min+1大小的数组Count[]
3. 遍历待排数组，对count[num-min]计数
4. 创建结果数组，将计数数组的索引值添加到结果数组中去
### 注
只能对整数数组进行排序

```
void Count_Sort(vector<int> &A){
    auto  min_ = std::min_element(std::begin(A),std::end(A));
    auto  max_ = std::max_element(std::begin(A),std::end(A));
    
    int *count = new int[max-min+1];
    int N = A.size();
    for(auto num : A){
        count[num-min]++;
    }

    index = 0;
    int *result = new *int[N]
    for(int i = 0; i<N; i++){
        while(count[i]>0){
            result[index++] = i+min;
            count[i]--;
        }
    }

    for(int i =0 ; i<N;i++){
        A[i] = result[i];
    }
    delete count[];
    delete result[];

}
```

## 桶排序
#### 说明
把桶的容量考虑为1就是计数排序

```
void Bucket_Sort(vector<int> &A){
    auto min = *std::min_element(std::begin(A),std::end(A));
    auto max = *std::max_element(std::begin(A),std::end(A));
    int N = A.size();

    int bucketLen = max-min + 1;

    int *bucket = new int[bucketLen];

    for(int i = 0; i<N ; i++){
        bucket[A[i]-min]++;
    }

    int start = 0;
    for(int i = 0; i< bucketLen; i++){
        for(int j = start; j < start + bucket[i];j++){
            A[j] = min+ i;
        }
        start += bucket[i];
    }

    delete bucket[];
    
}
```