people_list = list()

class People:
    def __init__(self,name,sex,education,major,interest,hobby):
        self.name = name  # 姓名
        self.sex = sex    # 性别
        self.education = education # 学业
        self.major = major  # 专业
        self.interest = interest    # 兴趣
        self.hobby = hobby  # 爱好

def add():
    name = input("请输入学生的姓名:")
    sex = input("请输入学生的性别:")
    education = input("请输入学生的学历:")
    major = input("请输入学生的专业:")
    interest = input("请输入学生的兴趣:")
    hobby = input("请输入学生的爱好:")
    p = People(name,sex,education,major,interest,hobby)
    people_list.append(p)
    print("成功添加")

def show():
    for i,p in enumerate(people_list):
        print("第%d个学生的信息如下:"%(i+1))
        print("学生姓名:",p.name)
        print("学生性别:",p.sex)
        print("学生学历:",p.education)
        print("学生专业:",p.major)
        print("学生兴趣:",p.interest)
        print("学生爱好:",p.hobby)
        print("-------------------")

def save():
    with open("student.txt","w") as f:
        for i,p in enumerate(people_list):
            f.write("第%d个学生的信息如下:\n"%(i+1))
            f.write("学生姓名:%s\n"%p.name)
            f.write("学生性别:%s\n"%p.sex)
            f.write("学生学历:%s\n"%p.education)
            f.write("学生专业:%s\n"%p.major)
            f.write("学生兴趣:%s\n"%p.interest)
            f.write("学生爱好:%s\n"%p.hobby)
            f.write("-------------------\n")

while(True):
    print("------个人信息录制系统--------")
    print("1. 添加信息")
    print("2. 展示信息")
    print("3. 储存信息")
    print("4. 退出")
    dev = int(input("请输入你的选择:"))
    if(dev == 1):
        add()
    elif(dev == 2):
        show()
    elif(dev == 3):
        save()
    elif(dev == 4):
        exit(0)
    else:
        print("输入错误!")
