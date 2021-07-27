import os
import subprocess


def main():
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

		i = 0
		n = len(text); m = len(pattern)
		d = len(fft); j = 0

		print('Pattern found using FFT -')
		while i < n:
			if j < d and i == fft[j]:
				for k in range(m):
					print('\033[1m' + '\033[33m' + text[i+k], end='')
				i += k+1
				j += 1
			else:
				print('\033[0m' + '\033[1m' + text[i], end='')
				i += 1

		print()
		i = 0; j = 0
		d = len(kmp)

		print('\033[0m' + 'Pattern found using KMP -')
		while i < n:
			if j < d and i == kmp[j]:
				for k in range(m):
					print('\033[1m' + '\033[33m' + text[i+k], end='')
				i += k+1
				j += 1
			else:
				print('\033[0m' + '\033[1m' + text[i], end='')
				i += 1

		print()
		subprocess.call(["rm -rf ./output.txt"], shell = True);
	else:
		print("Compilation errors");


if __name__ == "__main__":
	main()

