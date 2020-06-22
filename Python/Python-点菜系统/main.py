menu = {"麻辣小龙虾":30,"麻婆豆腐":20,"焖大虾":36,"五花肉":40,"青岛啤酒":5}
ordef_list = {"麻辣小龙虾":0,"麻婆豆腐":0,"焖大虾":0,"五花肉":0,"青岛啤酒":0}

def show():
    # 展示菜单
    print("本饭店的菜单如下:")
    for item in menu.items():
        print("菜名:",item[0],"价格:",item[1])

def order_dishes():
    # 点菜
    name = input("请输入你要点菜的名称:")
    num = input("请输入你要点的数量:")
    ordef_list[name] += eval(num)
    print("小二，我要{}{}份！".format(name,num))

def back_dishes():
    name = input("请输入你要退菜的名称:")
    num = input("请输入你要退菜的数量:")
    ordef_list[name] -= eval(num)
    print("小二，我不要{}{}份了！".format(name,num))

def sum_dishes():
    print("客官，你的购买清单如下:")
    sum_cost = 0
    for item in ordef_list.items():
        if(item[1] == 0):
            continue
        sum_cost += menu[item[0]] * item[1]
        print("菜名:",item[0],"单价:",menu[item[0]],"份数:",item[1],"总价:",menu[item[0]] * item[1])
    print("总共消费:",sum_cost)
    discost = eval(input("看客官正气凛然,客官想享受的折扣率是多少呢?"))
    print("你最终实际支付:{}元".format(discost * sum_cost))

def main():
    print("-----欢迎来到武松饭店-----")
    while(True):
        print("本饭店的功能如下:")
        print("1. 查看菜单")
        print("2. 进行点菜")
        print("3. 进行退菜")
        print("4. 进行结帐")
        choose = int(input("客官的选择是:"))
        if(choose == 1):
            show()
        elif(choose == 2):
            order_dishes()
        elif(choose == 3):
            back_dishes()
        elif(choose == 4):
            sum_dishes()
            break
        else:
            print("输入错误!")
        print("-------------------\n\n\n")
    print("-----客官下次再来!-----")

if __name__ == "__main__":
    main()
    pass
