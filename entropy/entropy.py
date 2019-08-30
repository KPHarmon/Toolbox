import math
import sys
from collections import Counter
# from progress.bar import IncrementalBar

def entropy(s):
	p, lns = Counter(s), float(len(s))
	return -sum(count/lns * math.log(count/lns,2) for count in p.values())

def graphic(total_entropy):
	bar = IncrementalBar('Shannon Entropy')
	bar.max = 8.0
	bar.min = 0.0
	bar.index = total_entropy
	return

def text_output(total_entropy):
	result = "Unknown"
	if total_entropy >= 4.066 and total_entropy <= 4.629:
		result = "Plaintext Data"
	elif total_entropy >= 4.941 and total_entropy <= 5.258:
		result = "Native Executable"
	elif total_entropy >= 6.677 and total_entropy <= 6.926:
		result = "Packed Executable"
	elif total_entropy >= 7.174 and total_entropy <= 7.177:
		result = "Encrypted Executable"

	print("\nENTROPY: " + str(total_entropy) + "  [" + result + "]\n")
	print("*----------------------------------*")
	print("| Data Sets      | Average Entropy |")
	print("*----------------------------------*")
	print("| Plaintext Data | 4.066 - 4.629   |")
	print("| Native Exes    | 4.941 - 5.258   |")
	print("| Packed Exes    | 6.677 - 6.926   |")
	print("| Encrypted Exes | 7.174 - 7.177   |")
	print("*----------------------------------*")
	return
	
def main():
	average_entropy = []
	total_entropy = 0
	with open(sys.argv[1], "rb") as f:
		chunk = f.read(1024)
		average_entropy.append(entropy(chunk))
	for i in average_entropy:
		total_entropy += i
	# graphic(total_entropy)
	text_output(total_entropy)
	
main()
