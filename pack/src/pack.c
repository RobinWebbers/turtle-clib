#include "pack.h"
#include <stdint.h>

void hpacki16(unsigned char *buf, uint16_t i)
{
    uint16_t *mem = (uint16_t *) buf;
    *mem = i;
}

void npacki16(unsigned char *buf, uint16_t i)
{
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        hpacki16(buf, i);
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        buf[0] = i >> 8;
        buf[1] = i;
    #else
        #error "What kind of system is this?\n"
    #endif
}

void hpacki32(unsigned char *buf, uint32_t i)
{
    uint32_t *mem = (uint32_t *) buf;
    *mem = i;
}

void npacki32(unsigned char *buf, uint32_t i)
{
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        hpacki32(buf, i);
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        buf[0] = i >> 24;
        buf[1] = i >> 16;
        buf[2] = i >> 8;
        buf[3] = i;
    #else
        #error "What kind of system is this?\n"
    #endif
}

void hpacki64(unsigned char *buf, uint64_t i)
{
    uint64_t *mem = (uint64_t *) buf;
    *mem = i;
}

void npacki64(unsigned char *buf, uint64_t i)
{
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        hpacki64(buf, i);
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        buf[0] = i >> 56;
        buf[1] = i >> 48;
        buf[2] = i >> 40;
        buf[3] = i >> 32;
        buf[4] = i >> 24;
        buf[5] = i >> 16;
        buf[6] = i >> 8;
        buf[7] = i;
    #else
        #error "What kind of system is this?\n"
    #endif
}

int16_t hunpacki16(unsigned char *buf)
{
    int16_t *i = (int16_t *) buf;
    return *i;
}

int16_t nunpacki16(unsigned char *buf)
{
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        return hunpacki16(buf);
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return  (buf[0] << 8)  |
                (buf[1]);
    #else
        #error "What kind of system is this?\n"
    #endif
}

int32_t hunpacki32(unsigned char *buf)
{
    int32_t *i = (int32_t *) buf;
    return *i;
}

int32_t nunpacki32(unsigned char *buf)
{
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        return hunpacki32(buf);
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return  (buf[0] << 24) |
                (buf[1] << 16) |
                (buf[2] << 8)  |
                (buf[3]);
    #else
        #error "What kind of system is this?\n"
    #endif
}

int64_t hunpacki64(unsigned char *buf)
{
    int64_t *i = (int64_t *) buf;
    return *i;
}

int64_t nunpacki64(unsigned char *buf)
{
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        return hunpacki64(buf);
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return  ((int64_t) buf[0] << 56) |
                ((int64_t) buf[1] << 48) |
                ((int64_t) buf[2] << 40) |
                ((int64_t) buf[3] << 32) |
                ((int64_t) buf[4] << 24) |
                ((int64_t) buf[5] << 16) |
                ((int64_t) buf[6] << 8)  |
                ((int64_t) buf[7]);
    #else
        #error "What kind of system is this?\n"
    #endif
}
