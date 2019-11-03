```c++
//区间最小值
vector<int>::iterator min_it = min_element(L.begin(), L.end());
//第一个大于等于 20的index 二分 要判断是不是等于
lower_bound(arr1.begin(), arr1.end(), 20)  - arr1.begin(); 
//true 如果有这个元素
binary_search(arr.begin(), arr.end(), 23)
//全排列 从小到大

    int a[3]={1,2,3};//123，132，213.....
    do
    {
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }while(next_permutation(a,a+3));
//char 全排列
    char ch[205];
    sort(ch,ch+strlen(ch));
    char *first =ch;
    char *last=ch+strlen(ch);
    do{
        cout<<ch<<endl;
    }while(next_permutation(first,last));

```