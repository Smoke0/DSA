"""
	this program will list the files name in current directory and
	sub directory and store result in list.txt also stores count of
	files
"""
import os

file = open("list.txt","w",encoding="utf-8")
count = 1
for root, dirs, files in os.walk("."):
    for filename in files:
        file.write(str(count)+"---" +filename+"\n")
        count = count +1

file.close()