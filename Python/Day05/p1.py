from hashlib import md5

password = ""
seed = "ojvtpuvg"
index = 0

while len(password) != 8:
    hash = md5((seed + str(index)).encode()).hexdigest()
    # if (index % 100000 == 0): print(seed + str(index), index)
    if hash[0:5] == "00000":
        password += hash[5]
        print(seed + str(index))
        print(hash)
        print(password)
        print()
    index += 1
    

