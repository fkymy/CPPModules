/* #include <stdint.h> */
/* #include <stdio.h> */
/*  */
/* int main(int argc, char **argv) */
/* { */
/*     union */
/*     { */
/*         uint32_t b4;    #<{(| 4 bytes |)}># */
/*         uint16_t b2[2]; #<{(| 2 bytes x 2 |)}># */
/*         uint8_t  b1[4]; #<{(| 1 byte  x 4 |)}># */
/*     } bytes; */
/*  */
/*     bytes.b4 = 0x12345678; */
/*     printf("bytes.b4: %08X\n", bytes.b4); */
/*     printf("bytes.b2: %04X, %04X\n", bytes.b2[0], bytes.b2[1]); */
/*     printf("bytes.b1: %02X, %02X, %02X, %02X\n", bytes.b1[0], bytes.b1[1], bytes.b1[2], bytes.b1[3]); */
/*     return 0; */
/* } */
/*  */
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    union
    {
        uint64_t b8;    /* 8 bytes */
        uint32_t b4[2]; /* 4 bytes x 2 */
        uint16_t b2[4]; /* 2 bytes x 4 */
        uint8_t  b1[8]; /* 1 byte  x 8 */
    } bytes;

    bytes.b8 = UINT64_C(0x123456789ABCDEF0);
    printf("bytes.b8: %16" PRIX64 "\n", bytes.b8);
    printf("bytes.b4: %08" PRIX32 ", %08" PRIX32 " \n", bytes.b4[0], bytes.b4[1]);
    printf("bytes.b2: %04" PRIX16 ", %04" PRIX16 ", %04" PRIX16 ", %04" PRIX16 " \n", bytes.b2[0], bytes.b2[1], bytes.b2[2], bytes.b2[3]);
    printf("bytes.b1: %02" PRIX8 ", %02" PRIX8 ", %02" PRIX8 ", %02" PRIX8 ", %02" PRIX8 ", %02" PRIX8 ", %02" PRIX8 ", %02" PRIX8 " \n",
        bytes.b1[0], bytes.b1[1], bytes.b1[2], bytes.b1[3], bytes.b1[4], bytes.b1[5], bytes.b1[6], bytes.b1[7]);
    return 0;
}
