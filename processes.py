from subprocess import Popen, PIPE

class CommandException(Exception):
	def __init__(self, line, message, stdin=None, stdin_file='error_input'):
		mess = f'{line} : {message}'
		if stdin:
			f = open(stdin_file)
			mess += f' (stdin written in {stdin_file})'
		super().__init__(mess)

class ErrException(CommandException):
	def __init__(self, line, exit_code, err, stdin=None):
		err = err.replace('\n', '\\n')
		mess = f'Stderr = "{err}". Exit code equals to {exit_code}'
		super().__init__(line, mess, stdin=stdin)

class InvalidOut(CommandException):
	def __init__(self, line, wrong_out, stdin=None):
		mess = f'Wrong output line : "{wrong_out}"'
		super().__init__(line, mess, stdin=stdin)

correct_lines_pswap = {
	'pa', 'pb',
	'ra', 'rb', 'rr',
	'rra', 'rrb', 'rrr',
	'sa', 'sb', 'ss'}
def invalid_output_line_pswap(l):
	return (not l in correct_lines_pswap)

correct_lines_checker = {
	'OK\n' : 0,
	'KO\n' : 1
}
def invalid_output_line_checker(l):
	return (not l in correct_lines_checker)

def launch_pswap(args, check_error):
	proc = Popen(['./push_swap'] + args, stdout=PIPE, stderr=PIPE)
	line = ' '.join(['./push_swap'] + args)
	out, err = proc.communicate()
	out = out.decode('utf-8').split('\n')
	out = list(filter(lambda l: len(l) > 0, out))
	if check_error and (proc.returncode or len(err) > 0):
		raise ErrException(line, proc.returncode, err.decode('utf-8'))
	if check_error and len(out) > 0:
		for l in out:
			if (invalid_output_line_pswap(l)):
				raise InvalidOut(line, l)
	return (out)

def launch_checker(checker, args, ps_out, check_error):
	proc = Popen([checker] + args, stdout=PIPE, stderr=PIPE, stdin=PIPE)
	line = ' '.join([checker] + args)
	proc.stdin.write('\n'.join(ps_out).encode('utf-8'))
	out, err = proc.communicate()
	proc.stdin.close()
	out = out.decode('utf-8')
	if check_error and (proc.returncode or len(err) > 0):
		raise ErrException(line, proc.returncode, err.decode('utf-8'))
	if check_error:
		if invalid_output_line_checker(out):
			raise InvalidOut(line, out)
	if correct_lines_checker[out] != 0:
		print(f'{line} : KO')

