import os
import glob
import re

LEN_MAX = 80
def cut_line(line):
	m = re.search('addprefix [^,]+, ', line)
	l = m.end()
	i = l
	lines_res = line[:i]
	line = line[i:]
	patt = re.compile(' ')
	line_update = ''
	di = 0
	while len(line) > 0:
		m = patt.search(line)
		if (m):
			di = m.start()
			line_update = line[:di]
			i += di
		else:
			di = len(line)
			i += di
		line_update = line[:di+1]
		line = line[di + 1:]
		if l + di > 80:
			lines_res += "\\\n\t" + line_update
			l = 8 + len(line_update)
		else:
			lines_res += line_update
			l = l + di
	return (lines_res)


def generate_srcs_lines(dirlist, suffix, include=True):
	i = 0
	for root, srcdir, files in os.walk('src'):
		if (len(root.split('/')) == 1):
			continue
		if include and root.split('/')[1] not in dirlist:
			continue
		elif not include and root.split('/')[1] in dirlist or root.split('/')[1].startswith('_'):
			continue
		res_line = "SRCS" + suffix + (" =" if i == 0 else " +=") \
			+ '$(addprefix {}/, '.format(root)
		i += 1
		files = filter(
			lambda f: not os.path.split(f)[-1].startswith('_') \
					and not f.endswith('.a') \
					and not f.endswith('.h') \
					and not f.endswith('.o') \
					and not f.endswith('.txt')
			, files)
		res_line += ' '.join(files) + ')'
		print(cut_line(res_line))
	print("OBJS" + suffix + " =$(SRCS" + suffix + ":%.c=%.o)")

	# srcdirs = os.listdir("src")
	# i = 0
	# for srcdir in srcdirs:
	# 	if include and srcdir not in dirlist:
	# 		continue
	# 	if not include and srcdir in dirlist:
	# 		continue
	# 	res_line = ("SRCS" + suffix + " =" if i == 0 else "SRCS" + suffix + " +=") + '$(addprefix {}/, '.format(os.path.join('src', srcdir))
	# 	i += 1
	# 	files = ['/'.join(y.split('/')[2:]) for x in os.walk('src/' + srcdir) for y in glob.glob(os.path.join(x[0], '*.c'))]
	# 	files = filter(lambda f: not f.startswith('_'), files)
	# 	res_line += ' '.join(files) + ')'
	# 	print(cut_line(res_line))
	# print("OBJS" + suffix + " =$(SRCS" + suffix + ":%.c=%.o)")

generate_srcs_lines(['pswap'], "_PS")
generate_srcs_lines(['checker'], "_CHK")
generate_srcs_lines(['pswap', 'checker', 'libft'], "_COM", include=False)
