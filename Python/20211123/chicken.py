def chicken():
    y_score = float(input("请输入公鸡价格:"))
    x_score = float(input("请输入母鸡价格:"))
    c_score = float(input("请输入小鸡价格:"))

    total_score = float(input("请输入总价格:"))
    y = 0
    lock = True
    while y <= 100:
        x = 0
        while x <= 100:
            c = 100 - y - x
            if c <= 0 or x <= 0 or y <= 0:
                x += 1
                continue
            
            total = y * y_score + x * x_score + c * c_score
            if total == total_score:
                print("母鸡{}只，公鸡{}只，小鸡{}只,总价{}元\n".format(x,y,c,total))
                lock = False
            x += 1
        y += 1

    if lock == True:
        print("\n找不到满意的方案!\n")


while 1:
    print("欢迎进入白鸡系统:")
    print("1.进入系统")
    print("2.退出")
    try:
        option = input("请输入选项:")
        if int(option) == 1:
            chicken()
        elif int(option) == 2:
            exit()
        else:
            print("输入有误，请重新输入\n")
    except ValueError:
        print("输入有误，请重新输入\n")