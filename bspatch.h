#pragma once
#include <cstdint>
#include <string>

namespace bs
{
struct bspatch_stream
{
    void* opaque;
    int (*read)(const struct bspatch_stream* stream, void* buffer, int length);
};

class BSPatch
{
public:
    static int Patch(const uint8_t* old, int64_t oldsize, uint8_t* _new, int64_t newsize, struct bspatch_stream* stream);
    static int Patch(const std::string oldFile,const std::string newFile,const std::string patchFile ,std::string &errMsg);
};
}
