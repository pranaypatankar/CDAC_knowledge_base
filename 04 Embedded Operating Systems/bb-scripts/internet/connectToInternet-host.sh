#!/bin/sh
sudo iptables --table nat --append POSTROUTING --out-interface enp0s3 -j MASQUERADE
sudo iptables --append FORWARD --in-interface enxe415f6f399c2 -j ACCEPT
echo 1 | sudo tee /proc/sys/net/ipv4/ip_forward
