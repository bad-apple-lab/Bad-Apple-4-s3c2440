# Bad-Apple-4-s3c2440

![](./led/out.gif)

#### Shell

```sh
arm-linux-gcc replay.c -o replay
```

#### LED

```sh
ffmpeg -v quiet -i "1080p.mp4" -vf scale=8:8 -c:v rawvideo -pix_fmt gray -f rawvideo - > 1.bin
gcc 1.c -o 1.out && ./1.out
arm-linux-gcc 2.c -o 2.out
```

```sh
insmod driver/s3c2440-led.ko
./2.out
```
