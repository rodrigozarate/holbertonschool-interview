#!/usr/bin/python3
""" 0-stats.py parses a string """


def print_data(f_size, valid_codes):
	""" print sum of file size and how many of each code """
	print("File size: {}".format(f_size))
	for code in valid_codes:
		if valid_codes[code] > 0:
			print("{}: {}".format(code, valid_codes[code]))


if __name__ == '__main__':
	from sys import argv, stderr, stdin
	import datetime
	from collections import OrderedDict

	l_number = 0
	f_size = 0
	valid_codes = OrderedDict.fromkeys([200 , 301, 400, 401, 403, 404, 405, 500], 0)


	try:
		for line in stdin:
			l_number += 1

			a = line.split('-', 1)
			if len(a) != 2:
				continue

			b = a[1].split(']')
			timecode = b[0].lstrip(' [')
			try:
				datetime.strptime(timecode, '%Y-%m-%d %H:%M:%S.%f')
				except:
					stderr.write("{}: {}: wrong format\n".format(argv[0], l_number))
					pass

			c = b[1].split('"')
			c = c[1:]
			if c[0] != 'GET /projects/260 HTTP/1.1':
				stderr.write("{}: {}: wrong request\n".format(argv[0], l_number))

			d = c[1].lstrip(' ')
			d = d.rstrip('\n')
			d = d.split(' ')

			if d[0].isdecimal():
				code = int(d[0])
				valid_codes[code] += 1
			
			if d[1].isdecimal():
				f_size += int(d[1])
			
			if l_number % 10 == 0:
				print_data(f_size, valid_codes)
		print_data(f_size, valid_codes)

	except (KeyboardInterrupt):
		print_data(f_size, valid_codes)
		raise
