from hashlib import md5

password = ["z"] * 8
seed = "ojvtpuvg"
done = 0
index = 0

def isdigit(ch):
    return len(ch) == 1 and ch >= '0' and ch <= '9'

while done != 8:
    hash = md5((seed + str(index)).encode()).hexdigest()
    # if (index % 100000 == 0): print(seed + str(index), index)
    if hash[0:5] == "00000" and hash[5] >= "0" and hash[5] <= "7" and password[int(hash[5])] == 'z':
        pos = int(hash[5])
        password[pos] = hash[6]
        done += 1

        print(seed + str(index))
        print(hash)
        print(''.join(password))
        print()
    index += 1
    

