//
// Created by Administrator on 2018/8/14/014.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

namespace SortAlgorithm
{
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // 选择排序
    template <typename T>
    void selectionSort(T arr[], int n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            int minIndex = i;
            for(int j = i + 1; j < n; j++)
                if(arr[minIndex] > arr[j])
                    minIndex = j;
            swap<T>(arr[minIndex],arr[i]);
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
    // 插入排序
    // 优势在于，提前结束循环
    // 基础插入排序
    template <typename T>
    void insertionSort(T arr[],int n)
    {
        // 第0个位置默认有序，即从第一个位置开始考虑
        for(int i = 1; i < n ; ++i)
            // 考察arr[j]，放在(0,j]区间合适位置
            for(int j = i; j > 0 && arr[j] < arr[j - 1] ; --j)
                swap(arr[j],arr[j - 1]);
    }
    // 优化的插入排序，减少了交换
    template <typename T>
    void insertionSort2(T arr[],int n)
    {
        for(int i = 1; i < n ; ++i)
        {
            T e = arr[i];       // 保存当前考察元素
            int j;         // j的语意：考察元素应该插入的位置
            for( j = i; j > 0 && arr[j - 1] > e; j-- ) // 每次考察的是arr[j - 1]
                arr[j] = arr[j - 1];    // 只要比e大，就往后的位置挪一位
            // 循环结束表示找到正确的j的位置 <==> arr[j - 1] < e
            arr[j] = e;
        }
    }
    // 输入左右边界的插入排序
    template <typename T>
    void insertionSort3(T arr[],int l,int r)
    {
        for(int i = l + 1 ; i <= r ; i ++)
        {
            T e = arr[i];
            int j;
            for( j = i ; j > l && arr[j - 1] > e ; j--)
                arr[j] = arr[j - 1];
            arr[j] = e;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////
    // 归并排序

    // 将arr[l...mid]和arr[mid+1...r]两部分进行合并
    template <typename T>
    void __merge(T arr[],int l ,int mid, int r)
    {
        auto aux = new T[r - l + 1];      // 开辟空间
        for(int i = l; i <= r; i ++)
            aux[i - l] = arr[i];

        // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
        int i = l;
        int j = mid + 1;
        // k指向下一个放入元素的位置
        // 注意计算偏移
        for(int k = l ; k <= r ; k++)
        {
            if( i > mid )   // 如果左半部分元素已经全部处理完毕
                arr[k] = aux[j++ - l];
            else if( j > r )   // 如果右半部分元素已经全部处理完毕
                arr[k] = aux[i++ - l];
            else if( aux[i - l] < aux[j - l] )
                arr[k] = aux[i++ - l];
            else // 左半部分所指元素 >= 右半部分所指元素
                arr[k] = aux[j++ - l];
        }
        delete[] aux;
    }
    // 递归使用归并排序，对arr[l...r]的范围进行排序
    template <typename T>
    void __mergeSort(T arr[], int l, int r)
    {
//        if( l >= r )
//            return;
        // 对于小规模数组, 使用插入排序
        if ( r - l <= 15)
        {
            insertionSort3(arr,l,r);
            return;
        }

        int mid = l + (r - l) / 2;
        __mergeSort(arr,l,mid);
        __mergeSort(arr,mid+1,r);
        //优化部分  arr近乎有序
        // arr[mid] <- 左侧最大值
        // arr[mid + 1] <- 右侧最大值
        // arr[mid] < arr[mid + 1] <- 实际整个arr已经有序
        if( arr[mid] > arr[mid + 1])
            __merge(arr,l,mid,r);
    }
    template <typename T>
    void mergeSort(T arr[], int n)
    {
        __mergeSort(arr,0,n-1);
    }
////////////////////////////////////////////////////////////////////////////////////////////////
    // 自底向上的归并排序，思路可用于链表
    template <typename T>
    void mergeSortBU(T arr[], int n)
    {
        // 对于小数组, 使用插入排序优化
        for( int i = 0 ; i < n ; i += 16 )
            insertionSort3(arr,i,min(i+15,n-1));
        for( int sz = 16; sz < n ; sz += sz )
            for( int i = 0 ; i < n - sz ; i += sz+sz )
                // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
                if( arr[i+sz-1] > arr[i+sz] )
                    __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );
    }
/////////////////////////////////////////////////////////////////////////////////////////////
    // 快速排序1
    // 对arr[l...r]部分进行partition操作
    // 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
    template <typename T>
    int _partition(T arr[], int l, int r )
    {
        // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
        swap<T>( arr[l] , arr[ rand() % ( r - l + 1) + l]);
        // 记录标定点数值
        T v = arr[l];
        // 初始化指针
        // arr[l+1...j) --> 小于v部分
        // arr[j...i) --> 大于v部分
        // 初始两个区间应都为空
        int i = l + 1;  // 指向考察元素，最开始考察 l + 1的位置
        int j = l + 1;
        for( i; i <= r; ++i )
        {
            if( arr[i] < v )
                swap<T>( arr[i], arr[j++] );
        }
        // 循环结束，j指向大于v的第一个元素
        swap<T>( arr[l], arr[--j] );
        return j;
    }
    // 对arr[l...r]部分进行快速排序
    template <typename T>
    void __quickSort( T arr[], int l, int r )
    {
        // 小数组使用插入排序法优化
        if( r - l <= 15)
        {
            insertionSort3(arr,l,r);
            return;
        }
        int p = _partition(arr,l,r);
        __quickSort(arr,l,p - 1);
        __quickSort(arr,p + 1,r);
    }
    // 基础版本（优化了近乎有序的情况）
    template<typename T>
    void quickSort(T arr[] , int n)
    {
        srand(time(NULL));  // 随机化算法，避免退化为链表
        __quickSort( arr,0,n - 1 );
    }
/////////////////////////////////////////////////////////////////////////////////////////////
    // 快速排序2
    // 解决多重复元素问题
    // 双路快速排序的partition
    // 返回p, 使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
    template <typename T>
    int _partition2( T arr[], int l, int r)
    {
       swap<T>( arr[l], arr[ rand() % (r - l + 1) + l ] );
       int v = arr[l];
        // 初始化指针
        // arr[l + 1...i) 小于v的区间
        // arr(j...r] 大于v的区间
        int i = l + 1;
        int j = r;
       while(true)
       {
            while( i <= r && arr[i] < v ) i++;
            // 循环结束，i指向 >= v的元素
            while( j >= l + 1 && arr[j] > v ) j--;
            // 循环结束，j指向 <= v的元素
            if( i > j ) break;
            swap( arr[i], arr[j] );
            // 考虑==v的情况，交换结束保持，需手动更新i,j
            i++;
            j--;
       }
       // 循环结束，j指向小于v部分的最后一个元素，i指向大于v部分的第一个元素
        swap<T>( arr[l], arr[j] );
       return j;
    }
    // 对arr[l...r]部分进行快速排序
    template <typename T>
    void __quickSort2( T arr[], int l, int r )
    {
        if( r - l <= 15 )
        {
            insertionSort3( arr, l, r );
            return;
        }
        int p = _partition2( arr, l, r );
        __quickSort2( arr, l, p - 1 );
        __quickSort2( arr, p + 1, r );
    }

    template <typename T>
    void quickSort2(T arr[] , int n)
    {
        srand(time(NULL));  // 随机化算法，避免退化为链表
        __quickSort2( arr, 0, n - 1 );
    }
/////////////////////////////////////////////////////////////////////////////////////////////
    // 对arr[l...r]部分进行快速排序
    template <typename T>
    void __quickSort3( T arr[], int l, int r )
    {
        if( r - l <= 15)
        {
            insertionSort3( arr, l, r );
            return;
        }
        // partition
        swap( arr[l], arr[ rand() % ( r - l + 1) + l ]);
        T v = arr[l];
        // arr[l+1...lt) <v 的部分
        // arr[lt...i) ==v 的部分
        // arr[gt...r] >v 的部分
        // 初始以上空间都为空
        // 初始化各指针
        int i = l + 1;      // 指向考察元素
        int lt = l + 1;
        int gt = r + 1;
        while( i < gt )
        {
            if( arr[i] < v )
                swap( arr[i++], arr[lt++]);
            else if( arr[i] > v )
                swap( arr[i], arr[--gt] );
            else i++;
        }
        // 循环结束，lt指向==v部分的第一个元素
        swap( arr[l],arr[--lt]);
        // 此时，lt指向<v部分的最后一个元素
        __quickSort3( arr, l, lt );
        __quickSort3( arr, gt, r );
    }
    // 三路快排
    template<typename T>
    void quickSort3( T arr[], int n )
    {
        srand(time(NULL));
        __quickSort3( arr, 0, n - 1 );
    }
/////////////////////////////////////////////////////////////////////////////////////////////
    // 原地堆排序
    // 优化的shiftDown过程, 使用赋值的方式取代不断的swap,
    // 该优化思想和之前对插入排序进行优化的思路是一致的
    template <typename T>
    void __shiftDown( T arr[], int n, int k)    // k为下沉元素
    {
        T e = arr[k];           // 记录当前元素
        while( 2 * k + 1 < n )  // 左孩子在数组内
        {
            int j = 2 * k + 1;  // arr[j] 为此轮中需要交换的位置
            if(j + 1 < n && arr[j + 1] > arr[j])    // 右孩子在数组内，且比左孩子大
                j++;
            if( e >= arr[j] )   break;
            arr[k] = arr[j];
            k = j;
        }
        // 循环结束，k指向了元素e应在的位置
        arr[k] = e;
    }
    template <typename T>
    void heapSort( T arr[], int n )
    {
        // 最后一个非叶子节点 (n - 2) / 2
        for(int i = (n - 2) / 2; i >= 0; i--)
        {
            __shiftDown( arr, n, i );
        }
        for(int i = n - 1; i > 0; i--)
        {
            swap( arr[0], arr[i] );
            __shiftDown( arr, i, 0 );
        }
    }

/////////////////////////////////////////////////////////////////////////////////////////////

    // 生成随机数组
    int* generateRandomArray(int n, int rangeL, int rangeR)
    {
        assert(rangeL <= rangeR);
        int* arr = new int[n];
        srand(time(NULL));
        for(int i = 0 ; i < n; i ++)
        {
            arr[i] = rand() % ( rangeR - rangeL - 1 );
        }
        return arr;
    }
    // 生成一个近乎有序的数组
    // 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
    // swapTimes定义了数组的无序程度:
    // swapTimes == 0 时, 数组完全有序
    // swapTimes 越大, 数组越趋向于无序
    int* generateNearlyOrderedArray(int n, int swapTimes)
    {
        int* arr = new int[n];
        for(int i = 0 ; i < n ; ++i)
        {
            arr[i] = i;
        }
        for(int i = 0; i < swapTimes; ++i)
        {
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx],arr[posy]);
        }
        return  arr;
    }
    // 打印数组
    template <typename T>
    void printArray(T* arr,int n)
    {
        for(int i = 0 ; i < n ; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    // 判断是否有序
    template <typename T>
    bool isSort(T arr[],int n)
    {
        for(int i = 1 ; i < n; i++)
        {
            if( arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }
    // 性能测试
    template <typename T>
    void testSort(string stringName, void (*sort)(T[],int), T arr[], int n)
    {
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        assert(isSort(arr,n));
        cout << stringName << " time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
    // 深拷贝数组
    int* copyIntArray(int a[], int n)
    {
        auto arr = new int[n];
        copy(a,a+n,arr);
        return arr;
    }

}
#endif //SORT_SORT_H
