import random

info = [0,[0,0],[0,0]]
cheat = 0
#[计算机赢的次数分布]
log = [0,0,0]
cheat = 0

def logic(com,player):
    equal = [[],[0,0],[1,1],[2,2]]
    fail = [[],[0,1],[1,2],[2,0]]
    result = [com,player]
    
    if equal.count(result) > 0:
        return 0
    elif fail.count(result) > 0:
        return -1
    else:
        return 1

def play():
    while 1:
        try:
            player = int(input("请出拳(0为石头，1为剪刀，2为布，-1退出游戏):"))
            com = random.randint(0,2)
            type = ["石头","剪刀","布"]
            if player == -1:
                break

            result = logic(com,player)
            print("计算机出的是"+type[com]+",你出的是"+type[player])
            info[0] += 1
            if result > 0:
                print("祝贺你，你赢了！")
                info[2][0] += 1
                info[1][1] += 1
            elif result == 0:
                print("不分上下的对局！")
            else:
                info[1][0] += 1
                info[2][1] += 1
                print("你输了，下次走运！")

        except:
            print("输入错误，请重新选择！")

def print_info():
    if info[0] == 0:
        print("你还没完呢！先开一把吧！\n")
    else:
        print("胜率统计（共%d场）:" % info[0])
        print("计算机胜"+str(info[1][0])+"场，输"+str(info[1][1])+"场，胜率"+str(info[1][0]/info[0]*100)+"%")
        print("你胜"+str(info[2][0])+"场，输"+str(info[2][1])+"场，胜率"+str(info[2][0]/info[0]*100)+"%")
        
def cheatA(cheat):
    cheat_list = ["布","石头","剪刀"]
    type = ["石头","剪刀","布"]
    total = info[1][0]
    #k = []
    try:
        if total > 0:
            rare = [(log[0]/total),(log[1]/total),(log[2]/total)]
            #print(rare)
            m = max(rare)
            index = rare.index(m)
            res = type[index]
            print("cheaterA:出"+res)

        if info[0] > 0:
            print("cheaterB:出"+cheat_list[cheat])

    except:
        print("cheatA err")

def play_cheat():
    while 1:
        #try:
            
            type = ["石头","剪刀","布"]
            if info[0] > 0:
                cheatA(cheat)
                

            player = int(input("请出拳(0为石头，1为剪刀，2为布，-1退出游戏):"))
            com = random.randint(0,2)
            #记录这一次的出拳
            cheat = player

            if player == -1:
                break

            result = logic(com,player)
            print("计算机出的是"+type[com]+",你出的是"+type[player])
            info[0] += 1
            if result > 0:
                print("祝贺你，你赢了！")
                info[2][0] += 1
                info[1][1] += 1
            elif result == 0:
                print("不分上下的对局！")
            else:
                info[1][0] += 1
                info[2][1] += 1
                #记录当前计算机胜利的所出拳的次数
                log[com] += 1
                print("你输了，下次走运！")
        #except:
        #    print("输入错误，请重新选择！")

while 1:
    print("欢迎加入猜拳游戏:")
    print("1.开始游戏")
    print("2.胜率统计")
    print("3.退出")
    try:
        option = input("请输入选项:")
        if option == "cheat":
            i = input("是否开启作弊器(Y/n):")
            if i == "Y":
                cheat = 1
            else:
                continue
        if int(option) == 1:
            print("\n")
            if cheat == 1:
                play_cheat()
            else:
                play()
        elif int(option) == 2:
            print_info()
        elif int(option) == 3:
            exit()
        else:
            print("输入有误，请重新输入\n")
    except ValueError:
        print("输入有误，请重新输入\n")