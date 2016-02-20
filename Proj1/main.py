# Chris Seasholtz
# Miniproject 1
# 11 Feb 2015
# Python 2.7.5


def getAsciiLst(lcStr):
	return [(ord(c) - ord("a") + 1) for c in lcStr]
def getStr(asciiLst):
	return ''.join(chr(i + ord("a") - 1) for i in asciiLst)

def encrypt(mLst, kLst): # accepts int list inputs
	return [((val + kLst[idx % len(kLst)] - 1) % 26 + 1) for idx, val in enumerate(mLst)]
def decrypt(mLst, kLst): # accepts int list inputs
	return [((val - kLst[idx % len(kLst)] - 1) % 26 + 1) for idx, val in enumerate(mLst)]


print ' * Text Encryptor/Decryptor * '
text = raw_input('Input: ').lower().replace(" ", "")
key = raw_input('Key: ').lower()

# convert strings to list of ints
txtList = getAsciiLst(text)
print txtList
keyList = getAsciiLst(key)
print keyList

print 'Would you like to encrypt (1) or decrypt (2)?'
choice = raw_input('Choice: ')

if choice == '1':
	print 'Encrypted: ' + getStr(encrypt(txtList, keyList))
elif choice == '2':
	print 'Decrypted: ' + getStr(decrypt(txtList, keyList))
else:
	print 'Invalid choice, exiting...'