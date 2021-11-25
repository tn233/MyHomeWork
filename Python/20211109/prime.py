def prime(num):
    if num >= 2:
        for i in range(2,num):
            if (num%i) == 0:
                return 0
        return 1
    else:
        return 0

def default():
    for x in range(0,101):
        if prime(x) > 0:
            print("%d为质数" % x)
    print("\n")

while 1:
    print("欢迎使用:")
    print("1.输出1到100的质数")
    print("2.判断任意数是否为质数")
    print("3.退出")
    try:
        option = int(input("请输入选项:"))
        if option == 1:
            print("\n")
            default()
        elif option == 2:
            while 1:
                try:
                    number = int(input("请输入数字:"))
                    if prime(number) > 0:
                        print("%d为质数\n" % number)
                    else:
                        print("%d不为质数\n" % number)
                    break
                except ValueError:
                    print("输入错误，请输入正确的数字！\n")

        elif option == 3:
            exit()
        else:
            print("输入有误，请重新输入\n")
    except ValueError:
        print("输入有误，请重新输入\n")
