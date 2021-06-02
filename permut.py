

from subprocess import Popen, PIPE
import os
import shutil
from itertools import permutations
from collections import defaultdict
from math import factorial, log10
import sys

n_default = 3

argv = sys.argv
argc = len(argv)
if len(argv) == 1:
	n = n_default
else:
	try:
		n = int(argv[1])
	except:
		print('Argument is not a number, taking default value instead')
		n = n_default
if n <= 0 or n > 10:
	print('Value of n is invalid (0 < n <= 10)')
	exit(1)
print(f'Taille de n : {n}')
if n > 8:
	print(f"T'es en train d'essayer fact(n) = {factorial(n)} cas... Bon chance...")

results = defaultdict(int)
basis = list(range(1, n + 1))
for args in permutations(basis):
	args = [str(i) for i in args]
	proc = Popen(['./push_swap'] + args, stdout=PIPE, stderr=PIPE)
	out, _ = proc.communicate()
	out = out.decode("utf-8")
	out = list(filter(lambda l: len(l) > 0, out.split('\n')))
	print(' '.join(args) + ': ' + ' '.join(out))
	results[len(out)] += 1


k_min = min(results.keys())
k_max = max(results.keys())
k_width = max(int(log10(k) if k > 0 else 1) for k in results.keys())
for k in range(k_min, k_max + 1):
	print(f'Nombre de cas ou la sortie vaut {k: ={k_width}} : {results[k]}')
