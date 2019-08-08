#pragma once
#include <cstddef>
#include <cstdint>
#include <string>

namespace bs
{
struct bsdiff_stream
{
    void* opaque;
    void* (*malloc)(size_t size);
    void (*free)(void* ptr);
    int (*write)(struct bsdiff_stream* stream, const void* buffer, int size);
};
class BSDiff
{
public:
    static int Diff(const uint8_t* old, int64_t oldsize, const uint8_t* _new, int64_t newsize, struct bsdiff_stream* stream);
    static int Diff(const std::string oldFile, const std::string newFile, const std::string patchFile , std::string &errMsg);
};
}
