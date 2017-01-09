import random

word_list = open("word_bank.txt")
word_bank = word_list.read()
word_bank = word_bank.split()
# now have a word bank in list form

word_length = input("How long a word do you want to play with? > ")
word_length=int(word_length)

i=0
acceptable_words=[]
while i<1000:
	if len(word_bank[i]) == word_length:
		acceptable_words.append(word_bank[i])
	i+=1

def the_unseen_word(selected_word_letters, guessed_letter):
	for i in range(0,len(selected_word_letters)):
		if selected_word_letters[i] == guessed_letter:
			bracket[i] = guessed_letter

index_of_guessword = random.randrange(0, len(acceptable_words)-1)
word = str(acceptable_words[index_of_guessword])
letters = [word[i] for i in range(0,(len(word)))]
bracket = ["_ " for i in range(0, len(letters))]
print("I have selected a word. Commence guessing letters.")
print(letters)
wrong_answers = 0
guess = input("> ")
word_finished = False

while wrong_answers <3 and word_finished==False:
	if guess in letters:
		the_unseen_word(letters,guess)
		if bracket == letters:
			print(bracket)
			print("That's it! Good job!")
			word_finished=True
		else:
			print(bracket)
			guess= input("Nice, now give it another letter: ")

	elif guess not in letters:
		print(bracket)
		print("That letter is not part of this word.")
		wrong_answers+=1
		print("You are now at %d wrong answers out of three." %wrong_answers)
		if wrong_answers<3:
			guess = input("Now guess again: ")	
		if wrong_answers>=3:
			print("Sorry, out of luck.")
