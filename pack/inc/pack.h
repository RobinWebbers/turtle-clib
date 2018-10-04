#ifndef PACK_H
#define PACK_H

#include <stdint.h>

void hpacki16(unsigned char *buf, uint16_t i);

void npacki16(unsigned char *buf, uint16_t i);

void hpacki32(unsigned char *buf, uint32_t i);

void npacki32(unsigned char *buf, uint32_t i);

void hpacki64(unsigned char *buf, uint64_t i);

void npacki64(unsigned char *buf, uint64_t i);

int16_t hunpacki16(unsigned char *buf);

int16_t nunpacki16(unsigned char *buf);

int32_t hunpacki32(unsigned char *buf);

int32_t nunpacki32(unsigned char *buf);

int64_t hunpacki64(unsigned char *buf);

int64_t nunpacki64(unsigned char *buf);

#endif
