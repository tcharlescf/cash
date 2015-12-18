Explanaion of the commands

cd : to change the directory
md : to make a dirctory
copy : to copy files
goodbye : is equal to "exit"
cat : is equal to "cat"
path : is equal to "pwd"
echo : is equal to "echo"
ls : is equal to "ls"
catch : is equal to "grep"
remove : to remove files
rd : to remove directories
pipe : to do pipe

pipe example
	pipe ps -x | catch bash
	pipe ps -x | catch firefox
	pipe ls -l | wc -l
	pipe ls | wc
	pipe ls | catch "something..."
	pipe ls -l | wc
	pipe ls -a | wc
	pipe ls -al | wc
