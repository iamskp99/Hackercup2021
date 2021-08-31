for case in range(int(input())):
    s = input()
    d = {}
    n = len(s)
    for i in s:
        if i in d:
            d[i] += 1

        else:
            d[i] = 1

    e = {"A", "E", "I", "O", "U"}
    ans = 10 ** 18
    flag = 0
    for i in d:
        cnt = 0
        for j in d:
            if i == j:
                continue

            if i in e:
                if j in e:
                    cnt += (d[j] * 2)

                else:
                    flag = 1
                    cnt += d[j]

            else:
                if j not in e:
                    cnt += (d[j] * 2)

                else:
                    flag = 1
                    cnt += d[j]

        ans = min(ans, cnt)

    if flag == 0:
        e = 10 ** 18
        for i in d:
            e = min(d[i], e)

        n = n - e
        cnt = e + n
        ans = min(ans, cnt)

    print("Case #" + str(case + 1) + ": " + str(ans))