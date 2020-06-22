def input_():
    n = int(input("请输入你要输入的学生的人数:"))
    total_score = list()
    for i in range(n):
        score = int(input("请输入第%d个学生的成绩："%(i+1)))
        total_score.append(score)
    return total_score

def display(score):
    for i in range(len(score)):    
        print("第{}个学生的成绩是:{}".format(i+1,score[i]))

def tongji(score):
    score_deng = [0 for i in range(5)]
    mmax = 0
    mmin = 100
    mavg = 0
    n = len(score)
    # 进行成绩统计
    for i in range(n):
        if(mmax < score[i]):
            mmax = score[i]
        if(mmin > score[i]):
            mmin = score[i]
        mavg += score[i]
        if(score[i] >= 90):
            score_deng[0]+=1
        elif(score[i] >= 80):
            score_deng[1]+=1
        elif(score[i] >= 70):
            score_deng[2]+=1
        elif(score[i] >= 60):
            score_deng[3]+=1
        else:
            score_deng[4]+=1
    for i in range(n):
        score[i] /= len(score)
    print("学生的最高分是:",mmax)
    print("学生的最低分是:",mmin)
    print("学生的平均分是:",mavg/len(score))
    print("------------------")
    print("成绩在90-100之间的学生百分比为:",score_deng[0]/n *100,"%")
    print("成绩在80-89之间的学生百分比为:",score_deng[1]/n *100,"%")
    print("成绩在70-79之间的学生百分比为:",score_deng[2]/n *100,"%")
    print("成绩在60-69之间的学生百分比为:",score_deng[3]/n  *100,"%")
    print("成绩在0-59之间的学生百分比为:",score_deng[4]/n *100 ,"%")


while(True):
    print("----My 学生成绩管理系统----")
    print("菜单如下:")
    print("1. 输入学生信息")
    print("2. 展示学生信息")
    print("3. 统计学生信息")
    print("4. 退出")
    cho = eval(input("请输入你的选择:"))
    if(cho == 1):
        score = input_()
    elif(cho == 2):
        display(score)
    elif(cho == 3):
        tongji(score)
    else:
        print("系统成功退出！")
        break
    
        

