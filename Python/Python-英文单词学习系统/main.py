def input_file():
    # 输入单词
    f = open("data.txt","w+")
    n = int(input("请输入单词的个数："))
    word = list()
    for i in range(1,n+1):
        t = input("第%d个单词是:"%i)+","
        word.append(t)

    # 单词进行排序
    word = sorted(word)
    print("文件中保存的单词为:",word)
    # 保存单词
    f.writelines(word)
    f.close()
    print("输入成功!")

def del_word():
    # 删除单词
    with open("data.txt","r") as f:
        line = f.readline()
    del_word = input("请输入你要删除的单词!")
    line = line.replace(del_word+",","")
    with open("data.txt","w") as f:
        f.writelines(line)
    print("删除成功!")

def change_word():
    # 修改单词
    with open("data.txt","r") as f:
        line = f.readline()

    will_change_word = input("请输入你要修改的单词?")
    change_word = input("请输入你要修改成什么?")
    line = line.replace(will_change_word+",",change_word+",")

    with open("data.txt","w") as f:
        f.writelines(line)
    print("修改成功!")

def main():
    while(True):
        print("--------英文单词学习系统--------")
        print(" 1.输入单词")
        print(" 2.删除单词")
        print(" 3.修改单词")
        print(" 4.退出")
        choose = input("请输入你的选择:")
        if(choose == "1"):
            input_file()
        if(choose == "2"):
            del_word()
        if(choose == "3"):
            change_word()
        if(choose == "4"):
            exit(0)

main()
