/*
	Best:    
	Worst: 
	Average:
*/

#include <iostream>
#include <vector>

using namespace std;

class heap_sort {
public:
    void swap(vector<int> &v, int i1, int i2)
    {
        int tmp = v[i2];
        v[i2] = v[i1];
        v[i1] = tmp;
    }
    void heap_adjust(vector<int> &v, int index, int heap_size);
    void build_heap(vector<int> &v);
    void heapSort(vector<int> &v);
};

//递归调整堆.
//1.先选出三个数的最大数, 然后如果不是父节点, 就和父节点进行交换;
//2.交换过后的值作为父节点有可能不是最大值, 所以需要递归进一步的调整. 重复1
void heap_sort::heap_adjust(vector<int> &v, int index, int heap_size)
{
    int im, l, r;
    im = index;
    l = 2*index + 1;
    r = 2*index + 2;
    if(l < heap_size && v[index]<v[l])
        im = l;
    if(r < heap_size && v[im]<v[r])
        im = r;
    if(im != index) {
        swap(v, im, index);
        heap_adjust(v, im, heap_size);
    }
}

//从最后一个父节点到第一个父节点(根节点).
//使得得到的堆是最大堆
void heap_sort::build_heap(vector<int> &v)
{
    int len = v.size();
    int end = (len+1)/2-1;
    for(int i=end; i>=0; i--)
        heap_adjust(v, i, len);
}

void heap_sort::heapSort(vector<int> &v)
{
    int len = v.size();
    build_heap(v);
    for(int i=len-1; i>=0; i--) {
        swap(v, 0, i);
        heap_adjust(v, 0, i);
    }
}

int main()
{
    heap_sort h;
    vector<int> v;
    v.push_back(0);
    v.push_back(4);
    v.push_back(2);
    v.push_back(7);
    v.push_back(8);
    v.push_back(3);
    v.push_back(1);
    h.heapSort(v);
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    
    return 0;
}
