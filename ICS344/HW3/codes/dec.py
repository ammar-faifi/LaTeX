from scapy.all import *

SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?."


def spoof(pkt):
    if (
        pkt[IP].src == "192.168.0.110"  # machine A
        and pkt[IP].dst == "192.168.0.108"  # machine B
        # and pkt[Ether].dst == "3c:a6:f6:6d:1d:41"  # machine M
    ):
        data = pkt[Raw].load
        print(f">>>>>> {data}, length: {len(data)}")
        decrypt(data.decode())
        


def decrypt(message):
    for key in range(len(SYMBOLS)):
        translated = ""
        for symbol in message:
            if symbol in SYMBOLS:
                symbolIndex = SYMBOLS.find(symbol)
                translatedIndex = symbolIndex - key

                # Handle the wrap-around:
                if translatedIndex < 0:
                    translatedIndex = translatedIndex + len(SYMBOLS)

                translated = translated + SYMBOLS[translatedIndex]

            else:
                translated = translated + symbol

        print(f"Key #{key}: {translated}")


pkt = sniff(filter="udp", prn=spoof)
