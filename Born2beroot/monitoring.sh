#!/bin/bash

ARC=$(uname --all)
CPU=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vCPU=$(grep "processor" /proc/cpuinfo | wc -l)
MMUS=$(free --mega | grep Mem | awk '{printf("%i/%iMB (%.2f%%)\n", $3, $2, $3/$2*100)}')
DISK=$(df --total --human-readable | grep "total" | awk '{printf("%s/%s (%.1f%%)\n", $3, $2, $3/$2*100)}')
LOAD=$(top -bn1 | grep "%Cpu" | awk '{printf("%.1f%%\n", (100.0-$8)%100)}')
BOOT=$(who --boot | awl '{printf("%s %s", $3, $4)}')
LVM=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo "no"; else echo "yes"; fi)
CON=$(ss -s | grep "TCP:" | tr ',' ' ' | awk '{printf("%s ESTABLISHED\n", $4)}')
USERS=$(who --count | grep "users" | tr '=' ' ' | awk '{printf("%s\n", $3)}')
NET=$(ip link | grep "ether" | awk '{print($2)}')
SUDO=$(sudo ls /../var/log/sudo/00/00 | wc -l)

wall "
        #Architecture: $ARC
        #CPU physical: $CPU
        #vCPU: $vCPU
        #Memory Usage: $MMUS
        #Disk Usage: $Disk
        #CPU load: $LOAD
        #Last boot: $BOOT
        #LVM use: $LVM
        #Connections TCP $CON
        #User log: $USERS
        #Network: $NET
        #Sudo: $SUDO cmd
        "
