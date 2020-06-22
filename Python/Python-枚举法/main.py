import math
def car():
    print("罪犯的车牌号为:",end="")
    for a1 in range(0,10):
        for a2 in range(0,10):
            if(a1==a2):
                for a3 in range(0,10):
                    for a4 in range(0,10):
                        if(a3==a4 and a1!=a3):
                            a = a1*1000+a2*100+a3*10+a4
                            for i in range(100):
                                if(a == i * i):
                                    print(a1,a2,a3,a4)
def Tricolore():
    s = 0
    for i in range(4):  # 红球
        for j in range(4):  #黄球
            k = 8 - i - j  #绿球
            if k <= 6:
                s += 1
    print("三色球问题共有",s,"种不同的颜色搭配.")


if __name__ == "__main__":
    while(True):
        print("\n\n------------------------")
        print("1.帮助警察破案")
        print("2.三色球问题")
        print("3.退出系统")
        choose = int(input("请选择你要求解的问题："))
        if(choose ==1 ):
            car()
        elif(choose == 2):
            Tricolore()
        elif(choose == 3):
            break
        else:
            print("输入错误!")
