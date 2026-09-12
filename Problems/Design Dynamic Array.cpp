/*
 * Design Dynamic Array
 */


// @lc code=start

#include <new>
#include <stdexcept>
#include <utility>

template <typename T>
class MyDynamicArray 
{

private:
    T* Data = nullptr;
    size_t MSize = 0;
    size_t MCapacity = 0;

    void Reallocate(size_t NewCapacity)
    {
        T* NewData = nullptr;
        if(NewCapacity > 0)
        {
            NewData = static_cast<T*>(::operator new(NewCapacity * sizeof(T)));
        }

        size_t CopySize = (MSize < NewCapacity) ? MSize : NewCapacity;
        for(size_t Index = 0; Index < CopySize; Index++)
        {
            new (NewData + Index) T(std::move(Data[Index]));
        }
        for(size_t Index = 0; Index < MSize; Index++)
        {
            Data[Index].~T();
        }

        ::operator delete(Data);
        Data = NewData;
        MCapacity = NewCapacity;
    }

public:
    MyDynamicArray() = default;
    MyDynamicArray(const MyDynamicArray&) = delete;
    MyDynamicArray& operator=(const MyDynamicArray&) = delete;
    MyDynamicArray(MyDynamicArray&&) = delete;
    MyDynamicArray& operator=(MyDynamicArray&&) = delete;

    ~MyDynamicArray()
    {
        Clear();
        ::operator delete(Data);
    }

    void Clear()
    {
        for(size_t Index = 0; Index < MSize; ++Index) 
        {
            Data[Index].~T();
        }
        MSize = 0;
    }

    size_t Size() const { return MSize; }
    size_t Capacity() const { return MCapacity; }
    bool IsEmpty() const { return MSize == 0; }
    bool IsValidIndex(size_t Index) const { return Index < MSize; }

    T& operator[](size_t Index)
    {
        return Data[Index];
    }

    const T& operator[](size_t Index) const
    {
        return Data[Index];
    }

    T& At(size_t Index)
    {
        if(!IsValidIndex(Index))
        {
            throw std::out_of_range("Index out of range");
        }
        return Data[Index];
    }

    const T& At(size_t Index) const
    {
        if(!IsValidIndex(Index))
        {
            throw std::out_of_range("Index out of range");
        }
        return Data[Index];
    }

    void Resize(size_t NewSize)
    {
        if(NewSize > MCapacity)
        {
            Reallocate(NewSize);
        }

        if(NewSize > MSize)
        {
            for(size_t Index = MSize; Index < NewSize; Index++)
            {
                new (Data + Index) T();
            }
        }
        else if(NewSize < MSize)
        {
            for(size_t Index = NewSize; Index < MSize; Index++)
            {
                Data[Index].~T();
            }
        }

        MSize = NewSize;
    }

    void ShrinkToFit() 
    {
        if(MSize < MCapacity) 
        {
            Reallocate(MSize);
        }
    }

    void PushBack(const T& InElement) 
    {
        if(MSize >= MCapacity) 
        {
            Reallocate(MCapacity == 0 ? 2 : MCapacity * 2);
        }
        new (Data + MSize) T(InElement);
        ++MSize;
    }

    void PushBack(T&& InElement) 
    {
        if(MSize >= MCapacity) 
        {
            Reallocate(MCapacity == 0 ? 2 : MCapacity * 2);
        }
        new (Data + MSize) T(std::move(InElement));
        ++MSize;
    }

    void PopBack() 
    {
        if(MSize > 0) 
        {
            --MSize;
            Data[MSize].~T();
        }
    }
};
