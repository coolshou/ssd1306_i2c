#CC=g++
CC=gcc


all:
	$(CC) demo.c ssd1306_i2c.c -lwiringPi -o demo

clean:
	rm demo
