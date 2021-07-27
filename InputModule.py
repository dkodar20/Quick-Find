import os
import subprocess

if subprocess.call(["g++", "./main.cc"]) == 0:
    subprocess.call(["./a.out < input.txt > output.txt"], shell = True)
    #taking input from output.txt
    with open('output.txt', 'r') as file:
        lines = [line.strip() for line in file]

    fft = list(map(int, lines[1].split()))
    kmp = list(map(int, lines[3].split()))

    with open('input.txt', 'r') as file:
        lines = [line.strip() for line in file]
    text = lines[0].split()[0]
    pattern = lines[1].split()[0]

    print(fft, kmp)

    m = len(pattern)

    for i in fft:
        print(text[i:i+m])
    subprocess.call(["rm -rf ./output.txt"], shell = True);
else:
    print("Compilation errors");
