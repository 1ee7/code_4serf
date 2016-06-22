1. 利用fork建立了两个子任务，但当一个任务非正常退出时，并没有kill掉，后台还在运行。
2. 如何通过c实现管理权限的获取


3. br0up.sh br1up.sh br0down.sh br1down.sh 复制到/usr/bin 下。
4. interface的配置
 eth1 连接图传，eth0连接pc网口
//=========================================
  auto lo
  iface lo inet loopback

  allow-hotplug eth1

  allow-hotplug eth0
  iface eth0 inet static
  address 192.168.137.12
  netmask 255.255.255.0
  gateway 192.168.137.1