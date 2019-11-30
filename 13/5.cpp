#pragma once
#include<iostream>
#include<assert.h>
#include <cstring>
using  namespace std;

typedef int DataType;
class Myvector
{
public:
    //析构空Myvector
    Myvector()
        :_array(new DataType[3])
        , _capacity(3)
        , _size(3)
    {}

    //Myvector中有n个值为data的元素
    Myvector(size_t n, const DataType& data)
        :_array(new DataType[n])
        , _capacity(n)
        , _size(n)
    {
        for (size_t i = 0; i < n; i++)
        {
            _array[i] = data;
        }
    }
    //用【first，last)区间构造Myvector
    Myvector(DataType* first, DataType* last)
    {
        size_t size = last - first;
        _array = new DataType[size];
        _capacity = size;
        _size = size;

        for (size_t i = 0; i < size; i++)
        {
            _array[i] = first[i];
        }
    }

    //拷贝构造函数
    Myvector(const Myvector& v)
        :_array(new DataType[v._capacity])
    {
        memcpy(_array, v._array, v._size*sizeof(DataType));
        _capacity = v._capacity;
        _size = v._size;
    }
    //赋值运算符重载

    Myvector& operator=(const Myvector& v)
    {
        if (this != &v)
        {
            Myvector tmp(v);
            Swap(tmp);
        }
    }

    //析构函数
    ~Myvector()
    {
        if (_array)
        {
            delete[] _array;
            _array= NULL;
            _capacity = 0;
            _size = 0;
        }
    }

    /*******************************************/
    /*******************************************/
    //随机访问
    DataType& operator[](size_t index)
    {
        assert(index < _size);
        return _array[index];
    }
    const DataType& operator[](size_t index) const
    {
        assert(index < _size);
        return _array[index];
    }
    //获取Myvector的第一个元素
    DataType& Front()
    {
        return _array[0];
    }
    const DataType& Front() const
    {
        return _array[0];
    }
    //获取Myvector中最后一个元素
    DataType& Back()
    {
        return _array[_size - 1];
    }
    const DataType& Back() const
    {
        return _array[_size - 1];
    }

    /*********************************/
    /*********************************/
    size_t Size() const
    {
        return _size;
    }
    size_t Capacity() const
    {
        return _capacity;
    }
    // 将顺序表中元素个数改变到n,多余元素放data
    void Resize(size_t n, const DataType& data)
    {
        size_t oldsize = Size();
        if (n<= oldsize)
            _size = n;
        else//n>oldsize
        {
            if (n <= _capacity)
            {
                for (size_t i = oldsize; i < n; i++)
                    _array[i] = data;
            }
            else //n>capacity需要扩容
            {
                //1. 开辟新空间
                DataType* pTmp = new DataType[n];

                //2. 拷贝旧空间中的元素
                for (size_t i = 0; i < oldsize; i++)
                {
                    pTmp[i] = _array[i];
                }
                //3.新增加的元素用data来填充
                for (size_t i = oldsize; i < n; i++)
                {
                    pTmp[i] = data;
                }
                //4. 释放旧空间
                delete[] _array;
                _array = pTmp;
                _capacity = n;
                _size = n;

            }
        }
    }
    // 为当前顺序表来预留空间，不能改变顺序表中有效元素的个数
    void Reserve(size_t newCapacity)
    {
        size_t oldcapacity = Capacity();
        if (newCapacity > oldcapacity)
        {
            DataType *tmp = new DataType[newCapacity];
            for (size_t i = 0; i < Size(); ++i)
            {
                tmp[i] = _array[i];
            }
            delete[] _array;
            _array = tmp;
            _capacity = newCapacity;
        }

    }


    /****************************************/
    /***************************************/
    //尾插
    void PushBack(const DataType& data)
    {
        CheckCapacity();
        _array[_size++] = data;
    }
    //尾删
    void PopBack()
    {
        --_size;
    }
    //任意位置插入
    void Insert(size_t pos, const DataType& data)
    {
        assert(pos <= _size);
        size_t tmp = _size;
        if (_size == pos)
        {
            PushBack(data);
        }
        else
        {
            CheckCapacity();
            while (tmp > pos)
            {
                _array[tmp] = _array[tmp - 1];
                --tmp;
            }
            _array[pos] = data;
            _size++;
        }

    }
     //清空
    void Clear()
    {
        _size = 0;
    }
    //任意位置删除
    void Erase(size_t pos)
    {
        assert(pos <= _size);
        if (pos == _size - 1)
        {
            PopBack();
        }
        else
        {
            while (_size > pos)
            {
                _array[pos] = _array[pos + 1];
                pos++;
            }
            _size--;
        }
    }
   //查找
    int Find(const DataType& data)
    {
        assert(_size > 0);
        size_t i = 0;

        while (i < _size)
        {
            if (_array[i] == data)
            {
                return i;
            }
            i++;
        }
        return -1;
    }
private:
    void Swap(Myvector& tmp)
    {
        swap(_array, tmp._array);
        swap(_capacity, tmp._capacity);
        swap(_size, tmp._size);
    }

    void CheckCapacity()
    {
        if (_size == _capacity)
        {
            Reserve(_capacity * 2);
        }
    }
    friend ostream& operator<<(ostream& _cout, const Myvector& v)
    {
        for (size_t i = 0; i < v._size; i++)
        {
            _cout << v._array[i] << " ";
        }
        return _cout;
    }

private:
    DataType* _array;
    size_t _capacity;
    size_t _size;


};

int main()
{
    Myvector v1;
    Myvector v2(10, 1);
    cout << v2 << endl;

    Myvector v3(v2);
    cout << v3 << endl;

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    Myvector v4(array, array + sizeof(array) / sizeof(array[0]));
    cout << v4 << endl;

    v4.PushBack(7);
    v4.PushBack(8);
    v4.PushBack(9);
    cout << v4 << endl;
    cout << v4.Front() << endl;
    cout << v4.Back() << endl;
    cout << v4.Size() << endl;
    cout << v4.Capacity() << endl;

    v4.PopBack();
    cout << v4 << endl;
    cout << v4.Size() << endl;
    cout << v4.Capacity() << endl;

    v4.Resize(30,5);
    cout << v4 << endl;
    cout << v4.Size() << endl;
    cout << v4.Capacity() << endl;

    size_t pos = v4.Find(6);
    v4.Insert(pos, 0);
    cout << v4 << endl;

    v4.Erase(pos);
    cout << v4 << endl;

    v4.Clear();
    cout << v4.Size() << endl;
    return 0;
}
