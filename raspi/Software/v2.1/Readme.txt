1. ����fork���������������񣬵���һ������������˳�ʱ����û��kill������̨�������С�
2. ���ͨ��cʵ�ֹ���Ȩ�޵Ļ�ȡ


3. br0up.sh br1up.sh br0down.sh br1down.sh ���Ƶ�/usr/bin �¡�
4. interface������
 eth1 ����ͼ����eth0����pc����
//=========================================
  auto lo
  iface lo inet loopback

  allow-hotplug eth1

  allow-hotplug eth0
  iface eth0 inet static
  address 192.168.137.12
  netmask 255.255.255.0
  gateway 192.168.137.1