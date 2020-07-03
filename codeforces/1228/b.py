def f():
    changed = 0
    h,w = map(int, input().split())
    grid = [[0]*w for _ in range(h)]
    rs = list(map(int, input().split()))
    cs = list(map(int, input().split()))
    for r in range(h):
        if rs[r] > w:
            print(0)
            return
        for c in range(rs[r]):
            changed += 1
            grid[r][c] = 1
        if rs[r]<w:
            changed += 1
            grid[r][rs[r]] = 2
    for c in range(w):
        if cs[c] > h:
            print(0)
            return
        for r in range(cs[c]):
            if grid[r][c] == 2:
                print(0)
                return
            if grid[r][c] == 0:
                grid[r][c] = 1
                changed += 1
        if cs[c] < h:
            if grid[cs[c]][c] == 1:
                print(0)
                return
            if grid[cs[c]][c] == 0:
                changed += 1
                grid[cs[c]][c] = 2
    result = 1
    for i in range(h*w-changed):
        result *= 2
        result %= 1000000007
    print(result)
f()
