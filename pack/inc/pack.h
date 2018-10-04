#ifndef PACK_H
#define PACK_H

#include <stdint.h>
/*
 * pack
 * ****
 * This is a library to store data into char arrays. It is pretty straight
 * forward. The "h" before a function stands for host, as in host byte order.
 * These functions store the bytes in the endianness of the host machine.
 * The "n" before a function stands for network order. These functions store the
 * bytes in a big endian order.
 */

/*
 * hpacki16()
 * **********
 * Pack a 16 bit integer into the char array in host byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @param i           - The integer to be packed.
 *
 * @return            - void
 */
void hpacki16(unsigned char *buf, uint16_t i);

/*
 * npacki16()
 * **********
 * Pack a 16 bit integer into the char array in network byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @param i           - The integer to be packed.
 *
 * @return            - void
 */
void npacki16(unsigned char *buf, uint16_t i);

/*
 * hpacki32()
 * **********
 * Pack a 32 bit integer into the char array in host byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @param i           - The integer to be packed.
 *
 * @return            - void
 */
void hpacki32(unsigned char *buf, uint32_t i);

/*
 * npacki32()
 * **********
 * Pack a 32 bit integer into the char array in network byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @param i           - The integer to be packed.
 *
 * @return            - void
 */
void npacki32(unsigned char *buf, uint32_t i);

/*
 * hpacki64()
 * **********
 * Pack a 64 bit integer into the char array in host byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @param i           - The integer to be packed.
 *
 * @return            - void
 */
void hpacki64(unsigned char *buf, uint64_t i);

/*
 * npacki64()
 * **********
 * Pack a 64 bit integer into the char array in network byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @param i           - The integer to be packed.
 *
 * @return            - void
 */
void npacki64(unsigned char *buf, uint64_t i);

/*
 * hunpacki16()
 * **********
 * Unpack a 16 bit integer from the char array in host byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @return            - 16 bit integer packed in the char array.
 */
int16_t hunpacki16(unsigned char *buf);

/*
 * nunpacki16()
 * **********
 * Unpack a 16 bit integer from the char array in network byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @return            - 16 bit integer packed in the char array.
 */
int16_t nunpacki16(unsigned char *buf);

/*
 * hunpacki32()
 * **********
 * Unpack a 32 bit integer from the char array in host byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @return            - 32 bit integer packed in the char array.
 */
int32_t hunpacki32(unsigned char *buf);

/*
 * nunpacki32()
 * **********
 * Unpack a 32 bit integer from the char array in network byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @return            - 32 bit integer packed in the char array.
 */
int32_t nunpacki32(unsigned char *buf);

/*
 * hunpacki64()
 * **********
 * Unpack a 64 bit integer from the char array in host byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @return            - 64 bit integer packed in the char array.
 */
int64_t hunpacki64(unsigned char *buf);

/*
 * nunpacki64()
 * **********
 * Unpack a 64 bit integer from the char array in network byte order.
 *
 * @param buf         - A pointer to a char array.
 *
 * @return            - 64 bit integer packed in the char array.
 */
int64_t nunpacki64(unsigned char *buf);

#endif
