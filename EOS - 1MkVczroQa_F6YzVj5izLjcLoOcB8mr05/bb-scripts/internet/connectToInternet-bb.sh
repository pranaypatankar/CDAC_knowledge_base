#!/bin/sh
sudo route add default gw 192.168.7.1
echo nameserver 8.8.8.8 | sudo tee -a /etc/resolv.conf

