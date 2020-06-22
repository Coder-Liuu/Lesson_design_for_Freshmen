import random

def pureNumber():
    print("Ohhhhhhhhhh!")
    plateNumber = str(random.randint(100000,999999))[1:]
    print("这是你随机产生的车牌号!")
    print("------>",plateNumber)
    return plateNumber

def HanziNumber():
    print("Ohhhhhhhhhh!")
    plateNumber = str(random.randint(1000,9999))[1:]

    char1='ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890'
    ans =""
    for i in range(5):
        ans2 = random.randint(0,len(char1)-1)
        ans += random.choice(char1[ans2]) 
    

    print("这是你随机产生的车牌号!")
    print("------>",ans)
    return ans

def main():
    print("------欢迎来到车牌号挑选公司-----")
    print("接下来你有三次挑选的机会!")
    print("三次不选，你将没有车牌号.")
    for i in range(3):
        print("---------------%d-----------------"%(i+1))
        print("1.纯数字")
        print("2.数字字母相结合")
        choose = int(input("你要想的车牌的类型:"))
        if(choose == 1):
            car_number = pureNumber()
        elif(choose == 2):
            car_number = HanziNumber()
        else:
            print("输入错误，你浪费了一次机会")
        ans = input("你是否想要这个车牌号?(回答Yes 或者 No)")

        if(ans == "Yes"):
            print("你最终的车牌号是:",car_number)
            print("-----------欢迎下次在来----------")
            return
        print("---------------------------------\n\n\n")

    print("太贪心，三次车牌号你都没有选，你没有车牌号了")
    print("-----------欢迎下次在来----------")



if __name__ == "__main__":
    main()
