# esp32
## Prototyping with microPython
### Getting started
I connected esp32 board to raspberryPi USB
I follow instructions of [microPython](http://docs.micropython.org/en/latest/esp32/tutorial/intro.html#esp32-intro)

```
pip install esptool
```
Erase ESP32
```
/home/pi# esptool.py --port /dev/ttyUSB0 erase_flash
esptool.py v2.6
Serial port /dev/ttyUSB0
Connecting....
Detecting chip type... ESP32
Chip is ESP32D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, Coding Scheme None
MAC: 30:ae:a4:47:a3:10
Uploading stub...
Running stub...
Stub running...
Erasing flash (this may take a while)...
Chip erase completed successfully in 3.1s
Hard resetting via RTS pin...

```
Download newest firmware for ESP32

```
Example
 wget http://micropython.org/resources/firmware/esp32-20190125-v1.10.bin
```
Flash firmware to ESP32
```
esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash -z 0x1000 esp32-20190125-v1.10.bin 
esptool.py v2.6
Serial port /dev/ttyUSB0
Connecting.....
Chip is ESP32D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, Coding Scheme None
MAC: 30:ae:a4:47:a3:10
Uploading stub...
Running stub...
Stub running...
Configuring flash size...
Auto-detected Flash size: 4MB
Compressed 1087456 bytes to 687409...
Wrote 1087456 bytes (687409 compressed) at 0x00001000 in 62.3 seconds (effective 139.5 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...

```
Installing rshell for connect to ESP32 following [tutorial](https://www.youtube.com/watch?v=w15-EQASP_Y)
```
pip3 install rshell
```
Connect to ESP32
```
rshell --buffer-size=30 -p /dev/ttyUSB0
```
```
boards
```
REPL for direct programming
```
repl
```

