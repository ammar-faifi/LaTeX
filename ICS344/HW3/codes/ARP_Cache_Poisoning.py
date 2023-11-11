from scapy.all import sendp
from scapy.layers.l2 import ARP, Ether


target_IP = "192.168.0.110"
target_MAC = "16:7c:df:f1:fc:de"

src_IP = "192.168.0.108"
src_MAC = "3c:a6:f6:6d:1d:41"

arp = ARP()
arp.hwsrc = src_MAC
arp.psrc = src_IP
arp.hwdst = target_MAC
arp.pdst = target_IP

arp.op = 2

ether = Ether()
ether.dst = target_MAC
ether.src = src_MAC


frame = ether / arp
res = sendp(frame)
print(res)
