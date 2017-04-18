//
// Created by kubas1129 on 30.03.17.
//

#include "MemoryChunk.h"


namespace memorychunk{


    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        if(ptr_ != nullptr)
        {
            return ptr_+offset;
        }
        else
        {
            return nullptr;
        }
    }

    MemoryChunk::MemoryChunk(size_t sz) {
        size_ = sz;
        ptr_ = new int8_t[size_];
    }

    size_t MemoryChunk::ChunkSize() const {
        return size_;
    }

    MemoryChunk::~MemoryChunk() {
        delete[] ptr_;
    }




    MemoryChunk::MemoryChunk(const MemoryChunk &memorychunk) {
        Copy(memorychunk);
    }

    void MemoryChunk::Copy(const MemoryChunk &memorychunk) {
        ptr_ = new int8_t[memorychunk.size_];
        std::copy(memorychunk.ptr_,memorychunk.ptr_+memorychunk.size_, ptr_);
        size_ = memorychunk.size_;
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&memorychunk) {
        Move(std::move(memorychunk));

    }

    void MemoryChunk::Move(MemoryChunk &&memorychunk) { size_t sz = size_;
        size_ = memorychunk.size_;
        memorychunk.size_ = 0;
        ptr_ = nullptr;
        std::swap(ptr_, memorychunk.ptr_);
    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &memorychunk) {
        if(this == &memorychunk)
        {
            return *this;
        }
        delete[] ptr_;
        Copy(memorychunk);

    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&memorychunk) {
        if(this == &memorychunk)
        {
            return *this;
        }
        size_ = memorychunk.size_;
        memorychunk.size_ = 0;
        delete[] ptr_;
        ptr_ = nullptr;
        std::swap(ptr_, memorychunk.ptr_);

    }


}