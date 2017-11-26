Setting up the Raspberry Pi
____________________________________________________________________________________________________________________________________________
Connecting the IMU

The easiest way to connect the IMU to the Raspberry Pi is to use something like the Adafruit Pi Plate (http://www.adafruit.com/products/801)
as it makes it obvious where the I2C bus 1 pins are and where to pick up 3.3V. Basically, you need to connect the I2C SDA, I2C SCL, 3.3V and
GND to the IMU breakout board you are using. Take care with these connections or else disaster may follow!
____________________________________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________________________________
Enabling and Configuring the I2C Bus

Add the following two lines to /etc/modules:

i2c-bcm2708
i2c-dev

Then, comment out the following line in /etc/modprobe.d/raspi-blacklist.conf:

# blacklist i2c-bcm2708

Restart the Raspberry Pi and /dev/i2c-0 and /dev/i2c-1 should appear. It’s also useful to install the I2C tools:

sudo apt-get install i2c-tools

Then:

sudo i2cdetect -y 1
____________________________________________________________________________________________________________________________________________