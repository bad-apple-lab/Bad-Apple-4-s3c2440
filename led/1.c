#include <stdio.h>

typedef unsigned char B;

const int FRAME_SIZE = 64;
const B LEDCODE[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

int main() {
    FILE *f = fopen("1.bin", "rb");
    FILE *f2 = fopen("2.bin", "wb");
    B *buf = (B *)malloc(FRAME_SIZE);
    B *buf2 = (B *)malloc(10);
    int count = 0;
    while (FRAME_SIZE == fread(buf, 1, FRAME_SIZE, f)) {
        memset(buf2, 0, 10);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (buf[i << 3 | j] & 128) {
                    buf2[j] |= 1 << i;
                }
            }
        }
        fwrite(buf2, 1, 10, f2);
        printf("%d\n", count);
        count++;
    }
    fclose(f);
    fclose(f2);
    return 0;
}
