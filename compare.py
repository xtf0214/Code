# https://github.com/luogu-dev/cyaron/wiki

from cyaron import *
import os

std_exe = r"D:\Code\CPP\OJ\Luogu\Problem\P1228A.cpp"
test_exe = r"D:\Code\CPP\OJ\Luogu\Problem\P1228.cpp"


def randRegion(a, b):
    i = randint(a, b)  # 数字位数
    l, r = 10**(i - 1), 10**i
    return randrange(l, r)


def makeData(i):
    test_data = IO(file_prefix="test", data_id=i)
    setData(i, test_data)
    test_data.output_gen(std_exe)


def osCompare(i):
    input_file = "D:\Code\CPP\\test%d.in" % i
    std = os.popen(std_exe + " < " + input_file)
    test = os.popen(test_exe + " < " + input_file)
    std_out = std.read()
    test_out = test.read()
    if std_out != test_out:
        print("Wrong Answer:", input_file)
        print("std_out:\n" + std_out)
        print("test_out:\n" + test_out)
        print()


def cmpProgram(i):
    test_data = IO(file_prefix="test", data_id=i, disable_output=True)
    setData(i, test_data)
    input_file = "D:\Code\CPP\\test%d.in" % i
    try:
        Compare.program(test_exe, input=test_data, std_program=std_exe)
    except:
        print("Wrong Answer:", input_file)


def setData(i, test_data: IO):
    # k=randRegion(1, 8)
    # print("input: ",k)
    # test_data.input_writeln(randRegion(1, 8))
    k = randint(1, 10)
    x = randint(1, 1 << k)
    y = randint(1, 1 << k)
    test_data.input_writeln(k, x, y)


for i in range(1, 10 + 1):
    print(i)
    cmpProgram(i)
    # osCompare(i)
