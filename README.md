# A list of utilities

## 1. capture luckfox 

capture nv12 format and convert it to rgb bmp file!

gcc cap_nv12.c  -o capluck

Usage: ./capluck [options]

Options:
-d | --device name   Video device name [/dev/video11]
-h | --help          Print this message
-c | --count         Number of frames to grab [1]
-w | --width         Frame width
-v | --height        Frame height


## 2. nv12 to rgb conversion for 'NV12' (Y/CbCr 4:2:0) format (as it comes from luckfox cameras)

compilation (I use an alpine armv7 docker container with these packages: openssh git gcc musl-dev gd-dev make linux-headers)

gcc nv12_to_rgb.c -o nv12convert

execute on container or on target with:
- ./nv12convert  nv12.img output.bmp 800 600

The nv12.img was captured with:
- v4l2-ctl --device=/dev/video11  --set-fmt-video=width=800,height=600,pixelformat=NV12 --stream-mmap --stream-to=nv12.img --stream-count=1
camera settings was set with:
- v4l2-ctl -d /dev/v4l-subdev2 --set-ctrl=exposure=200,analogue_gain=800,vertical_flip=1

Result 
 ![image](https://github.com/vjoco/utilities/assets/16479426/1ca85ea1-c476-4b54-9834-e0830f288da7)
