score = list()
max_score = 0
min_score = 100
avg_score = 0
n = None

def input_student():
    global score,n
    print("------------------")
    n = int(input("请输入学生的数量:"))
    for i in range(n):
        t = eval(input("请输入第%d个学生的成绩:"%(i+1)))
        score.append(t)

def show():
    print("------------------")
    for i,s in enumerate(score):
        print("第%d个学生的成绩是:%s"%(i+1,s))

def calc():
    global max_score,min_score,avg_score
    a = {"100-90":0,"89-80":0,"79-70":0,"69-60":0,"59-0":0}
    for i in score:
        if(i > max_score):
            max_score = i
        if(i < min_score):
            min_score = i
        avg_score += i

        if(i <= 100 and i >= 90):
            a["100-90"]  += 1
        if(i <= 89 and i >= 80):
            a["89-80"]  += 1
        if(i <= 79 and i >= 70):
            a["79-70"]  += 1
        if(i <= 69 and i >= 60):
            a["69-60"]  += 1
        if(i <= 59 and i >= 0):
            a["59-0"]  += 1

    print("------------------")
    print("统计结果为:")
    for item in a.items():
        print("分数段为:",item[0],"人的个数的百分比为:%.2f%%"%(item[1]/n * 100))
    print("------------------")
    print("最高分为:",max_score)
    print("最低分为:",min_score)
    print("平均分为:",avg_score/n)

def main():
    """
    功能:主函数-控制所有功能
    """
    input_student()
    show()
    calc()

if __name__ == "__main__":
    main()
