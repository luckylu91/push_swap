import random as r
from processes import launch_pswap, launch_checker
import statistics
import os
import shutil

n_runs = 100
n_nums = 100
range_min = 0
range_max = 500
check_error = True
use_checker = True
checker = './checker'
if use_checker and not os.path.isfile(checker):
	print('invalid chercker param')
	exit(1)
if use_checker:
	if not checker.startswith('./'):
		checker = './' + checker

def get_score(start, stop, n):
	args = r.sample(list(range(start, stop)), n)
	args = [str(n) for n in args]
	out = launch_pswap(args, check_error)
	if use_checker:
		launch_checker(checker, args, out, check_error)
	return len(out), args, out

scores_in_out = []
for i in range(n_runs):
	scores_in_out.append(get_score(range_min, range_max, n_nums))

scores_in_out = list(sorted(scores_in_out, key = lambda x: x[0]))

dir_name = 'results'
if os.path.isdir(dir_name):
	shutil.rmtree(dir_name)
os.mkdir(dir_name)

for i, (score, algo_in, algo_out) in enumerate(scores_in_out):
	fin = open(os.path.join(dir_name, str(i) + '_in_score_' + str(score)), 'w')
	fin.write(' '.join(str(n) for n in algo_in))
	fin.close()
	fout = open(os.path.join(dir_name, str(i) + '_out_score_' + str(score)), 'w')
	fout.write('\n'.join(algo_out))
	fout.close()
f = open(os.path.join(dir_name,'stats'), 'w')

scores, _, _ = zip(*scores_in_out)

print("moyenne :", statistics.mean(scores))
print("max :", max(scores))
