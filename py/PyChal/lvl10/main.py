U = list()
#set Uo :
U.append(11)
Ulist = list()

a = list()

for n in range(30):
    Ustr = str(U[n])
    for i in range(len(Ustr)):
        Ulist[i] = int(Ustr[i])

    count = 1
    for j in range(len(Ulist)):
        temp = Ulist[j+1]
        if Ulist[j] == temp:
            count += 1
        else:
            a.append(count+Ulist[j])
