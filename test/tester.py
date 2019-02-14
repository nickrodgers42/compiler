import os

if __name__ == "__main__":
    for dirname in os.listdir("TestFiles"):
        for filename in os.listdir("TestFiles/" + dirname + "/"):
            print(filename + ": ")
            os.system("../compiler/test/cpsl < TestFiles/" + dirname + "/"+  filename)        

