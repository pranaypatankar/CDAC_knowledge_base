#!/bin/bash

mkdir dev etc lib usr/lib proc sys root
mknod dev/console c 5 1
mknod dev/null c 1 3
mknod dev/zero c 1 5
rsync -a /usr/arm-linux-gnueabihf/lib/ ./lib/
rsync -a /usr/arm-linux-gnueabihf/lib/ ./usr/lib/

echo "cdac-eos" > etc/hostname
echo "root::0:0:root:/root:/bin/sh" > etc/passwd

cat <<EOF1 >> etc/inittab
null::sysinit:/bin/mount -a
null::sysinit:/bin/hostname -F /etc/hostname
null::respawn:/bin/cttyhack /bin/login root
null::restart:/sbin/reboot
EOF1

cat <<EOF2 >> etc/fstab
proc  /proc proc  defaults  0 0
sysfs /sys  sysfs defaults  0 0
EOF2
