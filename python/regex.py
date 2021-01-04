#This program basically searches for regex in a string.
import re
def check(string):
	r1 = re.search(r'^(?=.{8,})(?=.*[@#$^&+=]).*$',string)
	if (r1!=None):
		return True
	else:
		return False	

print(check(input("Enter String\n")))			