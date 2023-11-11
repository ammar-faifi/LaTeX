from scapy.all import *

key = 3
message = "Ammar"
mode = "encrypt"
SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?."
translated = ""

for symbol in message:
    # Note: Only symbols in the `SYMBOLS` string can be encrypted/decrypted.
    if symbol in SYMBOLS:
        symbolIndex = SYMBOLS.find(symbol)

        # Perform encryption/decryption:
        if mode == "encrypt":
            translatedIndex = symbolIndex + key
        elif mode == "decrypt":
            translatedIndex = symbolIndex - key

        # Handle wrap-around, if needed:
        if translatedIndex >= len(SYMBOLS):
            translatedIndex = translatedIndex - len(SYMBOLS)
        elif translatedIndex < 0:
            translatedIndex = translatedIndex + len(SYMBOLS)

        translated = translated + SYMBOLS[translatedIndex]
    else:
        # Append the symbol without encrypting/decrypting:
        translated = translated + symbol

##### sending packet ######
print(f"Encrypted message to be sent: {translated}")
packet = (
    IP(src="192.168.0.110", dst="192.168.0.108")
    / UDP(sport=1234, dport=5678)
    / translated
)
send(packet)
