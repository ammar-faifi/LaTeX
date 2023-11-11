from scapy.all import *

packet = (
    IP(src="192.168.0.110", dst="192.168.0.108")
    / UDP(sport=1234, dport=5678)
    / "Ammar Alfaifi"
)
send(packet)
