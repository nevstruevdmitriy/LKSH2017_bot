#Библиотеки. Библиотеку telebot надо ЗАРАНИЕ СКАЧАТЬ (установить)

import telebot
import subprocess
import time
import random
import os
import sys
import resource
import threading
from threading import Timer
from telebot import types
import myToken

import data

# лямда функция процесса, что бы уметь убивать детей)))) ХАХАХА!
kill = lambda process: process.kill()

#теперь bot - структура взаимодействия с Телеграмом
bot = telebot.TeleBot(myToken.TOKEN)

raund = 0

def setlimits():
	resource.setrlimit(resource.RLIMIT_CPU, (64000000, 65000000))

def commitGit(name):
	pipe1 = subprocess.PIPE
	pipe2 = subprocess.PIPE
	out = "\ncommit:"
	try:
		add = subprocess.Popen(["git", "add", "*"])
		timer = Timer(10, kill, [add])
		timer.start()
		add.wait()

		commit = subprocess.Popen(["git", "commit", "-m", name])
		timer = Timer(10, kill, [commit])
		timer.start()
		commit.wait()

		pull = subprocess.Popen(["git", "push"], stdin = pipe1, stdout = pipe2, 
								stderr = pipe2)
		timer = Timer(10, kill, [pull])
		timer.start()
		pull.wait()

		out += "\n" + str(pull.stdout.read())
	except:
		out += "\n" + name + " error!!"
	return out;


def writeResult_nom(raund):
	resultName = "results_nom.txt"
	if not("result" in os.listdir("./")):
		os.makedirs("result/")
	result = open("result/" + resultName, "w")
	result.write("%d\n" % raund)
	result.close()

def writeId(userName, id_):
	if not(userName in os.listdir("sempel/")):
		os.makedirs("sempel/" + userName)
	
	fid_ = open("sempel/%s/%s_id.txt" % (userName, userName), "w")
	fid_.write("%d\n" % id_)
	fid_.close()

def tellAllId(mes):
	global bot
	for i in os.listdir("sempel/"):
		try:
			if "%s_id.txt" % i in os.listdir("sempel/%s/" % i):
				id_ = open("sempel/%s/%s_id.txt" % (i, i), "r")
				photo = open(data.p_update, "rb")
	
				idPuple = int(id_.readline())

				id_.close()

				bot.send_photo(idPuple, photo)
				photo.close()
				bot.send_message(idPuple, mes)
		except:
			print("error %s" % i)

def start():
	global raund
	resultName = "results_nom.txt"
	if not("sempel" in os.listdir("./")):
		os.makedirs("sempel/")
	if not("result" in os.listdir("./")):
		os.makedirs("result/")
	if not(resultName in os.listdir("result/")):
		writeResult_nom(0)
		raund = 0;
	else:
		result = open("result/" + resultName, "r")
		raund = int(result.readline())
		result.close()

def writeResult(out, ans, player):
	global raund

	writeResult_nom(raund + 1)

	readResult = "result_raund%d" % raund

	result = open("result/" + readResult, "w")
	for i in out:
		result.write("%s %d\n" % (i[1], i[0]))

	outR = "\n" + "".center(13, "-")	

	for i in range(0, len(player)):
		outR += "|" + ("%d" % i).rjust(2, "0")
	outR += "\n"

	for i in range(0, len(player)):
		outR += (player[i][:13]).rjust(13, " ")
		for j in range(0, len(player)):
			outR += "|" + str(ans[i][j]).rjust(2, "0")
		outR += "\n"

	outR += "\n"

	for i in range(0, len(player)):
		outR += "%d столбец принадлежит %s\n" % (i, player[i])

	result.write(outR)
	result.close()
	raund += 1
	

def smail(var):
	if var == 0:
		return u'\U0001F530'
	if var == 1:
		return u'\U000026A1'
	if var == 2:
		return u'\U0001F52B'
	if var == 3:
		return u'\U0001F4A3'
	if var == -1:
		return u'\U0000203C'
	return 'error'

#По имени файла-решения игрока создаёт исполняемый файл
def makeSol(name1):
	pipe = subprocess.PIPE
	pathName = "sempel/" + name1 + "/" + name1
#	print(pathName)
	make = subprocess.Popen(["g++", pathName + ".cpp", "-std=gnu++11", "-o",
							pathName + ".exe"], stderr = pipe)
#   ставим таймер, что бы не висло
#	timer = Timer(5, kill, [make])
#	timer.start()

	make.wait()
	in_ = str(make.stderr.read())

	return in_

#Создаёт ботов
def makeName(name):
	log = makeSol(name)

	if log == "b\'\'":
		return "OK"
	return log

def writeLog(name, log):
	if not(name in os.listdir("sempel/")):
		os.makedirs("sempel/" + name)
	fileLog = open("sempel/" + name + "/" + name + "log.txt", "a")
	fileLog.write(log)
	print(log)

#функция игры, выводит проигравших
def war(name1, name2):
	logGame1 = []
	logGame2 = []
	out = ""

#	Создаём каналы для общения с детьми
	pipeIn1 = subprocess.PIPE
	pipeIn2 = subprocess.PIPE
	pipeOut1 = subprocess.PIPE
	pipeOut2 = subprocess.PIPE

	path1 = "sempel/" + name1 + "/" + name1 + ".exe"
	path2 = "sempel/" + name2 + "/" + name2 + ".exe"

	try:
		sol1 = subprocess.Popen([path1], stdin = pipeIn1, 
							stdout = pipeOut1, preexec_fn = setlimits)
	except:
		out += name1

	try:
		sol2 = subprocess.Popen([path2], stdin = pipeIn2,
							stdout = pipeOut2, preexec_fn = setlimits)
	except:
		out += name2

	if out != "":
		return (out, logGame1, logGame2)

	baz1 = 0
	baz2 = 0
	
	skil1 = 0
	skil2 = 0

#0 - защита
#1 - зарядка
#2 - пистолет
#3 - базука

	for i in range(0, 114):
#		ставим таймер, что бы не висло

		out = ""
		def warStep(sol, name):
			nonlocal out
			timer = Timer(0.1, kill, [sol])
			timer.start()

			try:
				var = int(sol.stdout.readline())
				timer.cancel()
				return var
			except:
				out += name + " "
				timer.cancel()
				return -1
		
		var1 = warStep(sol1, name1)
		var2 = warStep(sol2, name2)

		logGame1.append(var1)
		logGame2.append(var2)
		if var1 == 1:
			skil1 += 1
		if var2 == 1:
			skil2 += 1
		if var1 == 2 and skil1 == 0: # если некоректность выстерла
			out += name1 + " "
		if var2 == 2 and skil2 == 0:
			out += name2 + " "
		if var1 == 3 and skil1 < 3:
			out += name1 + " "
		if var2 == 3 and skil2 < 3:
			out += name2 + " "
		if out != "":               # если ввод не коректен
			break;


		if var1 == 3:                # если есть базука
			baz1 = 1
		if var2 == 3:
			baz2 = 1
		if baz1 == 1 and baz2 == 1:  # если выстрел одновременно
			out = "Ничья!"
			break
		if baz1 == 1:
			out = name2
			break
		if baz2 == 1:
			out = name1
			break
		if var1 == 2 and var2 == 2:  # если выстрелили одновременно
			out = "Ничья!"
			break
		if var1 == 2 and var2 != 0:  # елсли первый попал
			out = name2
			break
		if var2 == 2 and var1 != 0:  # если второй попал
			out = name1
			break
		if var1 == 2 or var1 == 3:
			skil1 = 0
		if var2 == 2 or var2 == 3:
			skil2 = 0
		
		try:
			sol1.stdin.write((str(var2) + "\n").encode())
			sol1.stdin.flush()
		except:
			out = out
		try:
			sol2.stdin.write((str(var1) + "\n").encode())
			sol2.stdin.flush()
		except:
			out = out

		if out != "":
			break
	if out == "":
		out = "Ничья!"
	
	sol1.kill()
	sol2.kill()
	return (out, logGame1, logGame2)


def testing():
	player = []
	ask = []
	
	for i in os.listdir("sempel/"):
		if str(i) + ".exe" in os.listdir("sempel/%s" % str(i)):
			player.append(i)

	for i in range(0, len(player)):
		ask.append([])
		for j in range(0, len(player)):
			ask[i].append([])

	for i in range(0, len(player)):
		for j in range(0, len(player)):
			ask[i][j] = 0		

	for kol in range(0, 20):
		for i in range(0, len(player)):
			for j in range(i + 1, len(player)):
				game = war(player[i], player[j])
				if (player[i] in game[0]) and not(player[j] in game[0]):
					ask[j][i] += 1
				if (player[j] in game[0]) and not(player[i] in game[0]):
					ask[i][j] += 1
				print("--> %d %d kol = %d\n" % (i, j, kol))
		time.sleep(1)

	summa = []
	for i in range(0, len(player)):
		teksum = 0
		for j in range(0, len(player)):
			teksum += ask[i][j]
		summa.append((teksum, player[i]))
	
	summa = sorted(summa, reverse = 1)

	out = ""
	ind = 1	

	for i in range(0, len(summa)):
		if summa[i][0] < summa[i - 1][0]:
			ind += 1
		out += "Место %s: %s набрал %d\n" % \
				(str(ind), summa[i][1], summa[i][0])


	out += "Cводная таблица:\n%s" % ("".center(2, "X"))

	for i in range(0, len(player)):
		out += "|" + ("%d" % i).rjust(2, "0")
	out += "\n"

	for i in range(0, len(player)):
		out += ("%d" % i).rjust(2, "0")
		for j in range(0, len(player)):
			out += "|" + str(ask[i][j]).rjust(2, "0")
		out += "\n"
	
	out += "\n"
	
	for i in range(0, len(player)):
		out += "%d линия принадлежит %s\n" % (i, player[i])

	writeResult(summa, ask, player)
	commitGit("all_testing")
	return out

def checkSol(name):
	src = "sempel/%s/%s.cpp" % (name, name)
	with open(src, 'rb') as name:
		for i in data.worldKey:
			for j in name:
				if i in str(j):
					print("error Sol")
					return i
	return "OK"

#@ - Это есть хендлер (почитай теорию по питону) который 
#позволяет не проверять много разных вариантов и отслеживать
#ошибки пользователя. Так же говрит телегамму, что в случая 
#выполнея всего без ошибок, после получения ответа от пользователя,
#вызовится эта функция.
#В скобках пишем какие доп. условия хотим проверять)

@bot.message_handler(content_types = ['text'])
def inputMesText(mes):
#	Теперь markup - способ задания "кнопочек")))
	markup = types.ReplyKeyboardMarkup()
#	Теперь в markup есть кнопочка "/help")))
	markup.row("/help",  "/MyBot", "/task")
	userName = mes.from_user.last_name + \
				  mes.from_user.first_name
	photo = None

	if not(userName in os.listdir("sempel/")):
		os.makedirs("sempel/" + userName)

	writeId(userName, mes.chat.id)

	for i in os.listdir("sempel/"):
		if str(i) + ".exe" in os.listdir("sempel/%s" % str(i)):
			markup.row("Потребовать сатисфакцию :%s" % i)
	varTime = time.ctime(time.time())

	out = data.hi
	warOut = ()
	fl = 0
	log = "{%s}:%s:" % (varTime, userName)


	if mes.text == "/help" and 0:
		out = data.help_
		log += "/help\n"
		photo = open(data.p_help, "rb")
	elif mes.text == "/all_testing":
		out = testing()
	elif mes.text == "/MyBot" and 0:
		log += "/MyBot\n"
		try:
			print (userName)
			doc = open("sempel/" + userName + "/" + 
					   userName + ".cpp", "rb")
			bot.send_document(mes.chat.id, doc)
			doc.close()
			out = "Твоя прелесть)))"
			photo = open(data.p_gol, "rb")
		except:
			out = data.errorFile
			photo = open(data.p_mybot, "rb")
	elif mes.text == "/task" and 0:
		log += "/task\n"
		out = data.task
		photo = open(data.p_task, "rb")
	elif "/all_mes^" in mes.text and 0:
		messeg = mes.text.split("^")
		tellAllId("Объявление жюри: %s" % messeg[1])
	elif "Потребовать сатисфакцию :" in mes.text and 0:
		log += mes.text + "\n"
		anamy = mes.text.split(":")[1]
		fl = 1
	elif "war_" in mes.text and 0:
		log += mes.task + "\n"
		anamy = mes.text.split("_")[1]
		fl = 1
		
	else:
		photo = open(data.p_hi, "rb")
		out = "Контест закрыт))"

	if fl:
		photo = open(data.p_war, "rb")
		if not(userName + ".cpp" in os.listdir("sempel/" + userName)):
			out = data.errorFile
		elif not(anamy + ".cpp" in os.listdir("sempel/" + anamy)):
			out = data.errorFileAny
		else:
			log += "war %s %s\n" % (anamy, userName)
			warOut = war(anamy, userName)

	if warOut != ():
		out = ""
		if userName in warOut[0]: 
			whoIsWin = "you'll be back\n"
		elif warOut[0] == "Ничья!":
			whoIsWin = data.noWins
		else:
			whoIsWin = "Exterminate!\n"
		
		out += "Жребий брошен:\n"
		cmt = 0
		out += "№: ты -- он\n"
		if len(warOut[1]) == 0:
			print("ERRRRORRRR!!!XXX")

		for i in range(len(warOut[1])):
			out += "%d: %s -- %s\n" % \
					(i, smail(warOut[2][i]), smail(warOut[1][i]))
		out += whoIsWin
		log += whoIsWin + "\n"

	if photo != None:
		bot.send_photo(mes.chat.id, photo)
		photo.close()
	bot.send_message(mes.chat.id, out, reply_markup = markup)
	writeLog(userName, log)
	
@bot.message_handler(content_types = ['document'])
def inputMesData(mes):
#	Здесь будет обработка решений учатсника
#	print("dokument\n")
	
	
	bot.reply_to(mes, "Контест закрыт))")
	return

	VarTime = time.ctime(time.time())

	nameSol = mes.from_user.last_name + mes.from_user.first_name

	writeId(nameSol, mes.chat.id)

	try:
		chatId = mes.chat.id
		fileInfo = bot.get_file(mes.document.file_id)
		download = bot.download_file(fileInfo.file_path)

#		print(nameSol)
	
		if not(nameSol in os.listdir("sempel/")):
			os.makedirs("sempel/" + nameSol)
		src = 'sempel/' + nameSol + "/" + nameSol + ".cpp"

		with open(src, 'wb') as new_file:
			new_file.write(download)

		logCheck = checkSol(nameSol)
		if logCheck != "OK":
			bot.reply_to(mes, "Не используй %s в своём решении, пожалуйста))" %
						 logCheck)
		else:
			logMake = makeName(nameSol)
			if logMake != "OK":
				bot.reply_to(mes, "Решение не скомпилировалось(\n log: %s\n"
							 % logMake[:2113])
			else:
				tellAllId("%s Обновил решение!\n" % nameSol)
				bot.reply_to(mes, "Решение принято))")

	except Exception as e:
		bot.reply_to(mes, "Что то не так, нажми на /myBot и проверь что решение твоё")
	
	log = "{%s}:%s: Добавлин новый файл" % (VarTime, nameSol)
	log += commitGit("Новый файл " + nameSol)
	writeLog(nameSol, log)

if __name__ == "__main__":
	start()
	while(True):
		try:
			bot.polling(none_stop = True)
		except:
			print("Internet ERRORRR!!!\n")
			time.sleep(3)
