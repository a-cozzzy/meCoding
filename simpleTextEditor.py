# Enter your code here. Read input from STDIN. Print output to STDOUT
Q = int(input().rstrip())
history = []
s = ""
for q in range(Q):
    args = input().rstrip().split()
    cmd = args[0]
    if cmd == "1":
        history.append(s)
        s += args[1]
    if cmd == "2":
        history.append(s)
        k = int(args[1])
        s = s[:-(k)]
    if cmd == "3":
        k = int(args[1])
        print(s[k-1])
    if cmd == "4":
        s = history.pop()
